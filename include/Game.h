#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>  // Thêm thư viện SDL_ttf
#include "Snake.h"
#include "Food.h"

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void renderGameOver(); // Hàm vẽ "GAME OVER"
    void reset();
    void loadBackground();

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* backgroundTexture;
    TTF_Font* font; // Font chữ

    bool running;
    bool gameOver;
    Snake snake;
    Food food;
};

#endif // GAME_H
