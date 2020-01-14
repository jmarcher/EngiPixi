#ifndef ENGINE_H
#define ENGINE_H

#define TILE_COUNT_PER_SCREEN 10

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

#include "GameObject.h"
#include "TexureManager.h"
#include "Tile.h"

class Engine
{
public:
    Engine();
    ~Engine();

    void start(const char* title, int width, int height, bool fullScreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool isRunning() const;

    static SDL_Renderer* renderer;

protected:
    SDL_Window* window;
    bool _isRunning;
    Tile _map[TILE_COUNT_PER_SCREEN][TILE_COUNT_PER_SCREEN];
    unsigned long long _ticks;
};

#endif // ENGINE_H
