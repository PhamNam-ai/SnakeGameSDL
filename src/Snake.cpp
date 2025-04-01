// Snake.cpp
#include "Snake.h"
#include <iostream>

Snake::Snake(int x, int y) : dirX(20), dirY(0) {
    body.push_back({ x, y, 20, 20 });
}

void Snake::handleEvent(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
        case SDLK_UP:    if (dirY == 0) { dirX = 0; dirY = -20; } break;
        case SDLK_DOWN:  if (dirY == 0) { dirX = 0; dirY = 20; } break;
        case SDLK_LEFT:  if (dirX == 0) { dirX = -20; dirY = 0; } break;
        case SDLK_RIGHT: if (dirX == 0) { dirX = 20; dirY = 0; } break;
        }
    }
}

void Snake::move() {
    SDL_Rect newHead = body.front();
    newHead.x += dirX;
    newHead.y += dirY;
    body.insert(body.begin(), newHead);
    body.pop_back();
}

bool Snake::checkCollision() {
    SDL_Rect head = body.front();
    if (head.x < 0 || head.y < 0 || head.x >= 640 || head.y >= 480) return true;
    for (size_t i = 1; i < body.size(); i++) {
        if (head.x == body[i].x && head.y == body[i].y) return true;
    }
    return false;
}

bool Snake::eatFood(Food& food) {
    if (body.front().x == food.getX() && body.front().y == food.getY()) {
        body.push_back({ 0, 0, 20, 20 });
        return true;
    }
    return false;
}

void Snake::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (const auto& segment : body) {
        SDL_RenderFillRect(renderer, &segment);
    }
}

void Snake::reset() {
    body.clear();
    body.push_back({ 20, 20, 20, 20 });
    dirX = 20; dirY = 0;
}