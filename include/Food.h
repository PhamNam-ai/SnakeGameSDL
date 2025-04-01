// Food.h
#ifndef FOOD_H
#define FOOD_H

#include <SDL2/SDL.h>

class Food {
public:
    Food(int x, int y);
    void respawn();
    void render(SDL_Renderer* renderer);
    int getX() const { return rect.x; }
    int getY() const { return rect.y; }

private:
    SDL_Rect rect;
};

#endif // FOOD_H
