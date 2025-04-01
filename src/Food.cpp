// Food.cpp
#include "Food.h"
#include <cstdlib>

Food::Food(int x, int y) {
    rect = { x, y, 20, 20 };
}

void Food::respawn() {
    rect.x = (rand() % 32) * 20;
    rect.y = (rand() % 24) * 20;
}

void Food::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}
