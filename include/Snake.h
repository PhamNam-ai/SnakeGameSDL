// Snake.h
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SDL2/SDL.h>
#include "Food.h"

class Snake {
public:
    Snake(int x, int y);
    void handleEvent(SDL_Event& e);
    void move();
    void render(SDL_Renderer* renderer);
    bool checkCollision();
    bool eatFood(Food& food);
    void reset();

private:
    std::vector<SDL_Rect> body;
    int dirX, dirY;
};

#endif // SNAKE_H
