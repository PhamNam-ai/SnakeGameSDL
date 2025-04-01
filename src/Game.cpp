#include "Game.h"
#include <iostream>

Game::Game() : running(true), gameOver(false), snake(20, 20), food(40, 40), backgroundTexture(nullptr), font(nullptr) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Không thể khởi tạo SDL: " << SDL_GetError() << std::endl;
        return;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "Lỗi khởi tạo SDL2_image: " << IMG_GetError() << std::endl;
        return;
    }

    if (TTF_Init() == -1) {
        std::cerr << "Lỗi khởi tạo SDL_ttf: " << TTF_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Không thể tạo cửa sổ: " << SDL_GetError() << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Không thể tạo renderer: " << SDL_GetError() << std::endl;
        return;
    }

    // Tải font chữ
    font = TTF_OpenFont("assets/font.ttf", 48); // Đặt file font.ttf vào thư mục assets/
    if (!font) {
        std::cerr << "No download font: " << TTF_GetError() << std::endl;
    }

    loadBackground();
}

Game::~Game() {
    if (backgroundTexture) {
        SDL_DestroyTexture(backgroundTexture);
    }
    if (font) {
        TTF_CloseFont(font);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::loadBackground() {
    SDL_Surface* tempSurface = IMG_Load("assets/background.png");
    if (!tempSurface) {
        std::cerr << "No download picture " << IMG_GetError() << std::endl;
        return;
    }
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

void Game::run() {
    while (running) {
        processEvents();
        if (!gameOver) {
            update();
        }
        render();
        SDL_Delay(200);
    }
}

void Game::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        if (gameOver && event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
            reset();
        }
        snake.handleEvent(event);
    }
}

void Game::update() {
    snake.move();
    if (snake.checkCollision()) {
        gameOver = true;
    }
    if (snake.eatFood(food)) {
        food.respawn();
    }
}

void Game::render() {
    SDL_RenderClear(renderer);

    // Vẽ ảnh nền
    if (backgroundTexture) {
        SDL_RenderCopy(renderer, backgroundTexture, nullptr, nullptr);
    }
    else {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderClear(renderer);
    }

    snake.render(renderer);
    food.render(renderer);

    // Hiển thị Game Over nếu thua
    if (gameOver) {
        renderGameOver();
    }

    SDL_RenderPresent(renderer);
}

void Game::renderGameOver() {
    if (!font) return;

    SDL_Color color = { 255, 0, 0, 255 }; // Màu đỏ
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "GAME OVER", color);
    if (!textSurface) {
        std::cerr << "NO create surface " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    if (!textTexture) {
        std::cerr << "No create texture " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Rect textRect = { 220, 200, 200, 50 }; // Định vị trí chữ trên màn hình
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
    SDL_DestroyTexture(textTexture);
}

void Game::reset() {
    gameOver = false;
    snake.reset();
    food.respawn();
}
