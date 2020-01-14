#ifndef ENGINE_H
#define ENGINE_H

#define TILE_COUNT_PER_SCREEN 10

#include "Tile.h"
#include "SDL2/SDL.h"
#include <iostream>

class Engine
{
public:
    Engine();
    ~Engine();
    
    void start(const char* title, int width, int height, bool fullScreen);
    void handleEvents();
    void update();
    void draw();
    void present();
    void clean();
    
    bool isRunning() const;
protected:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool _isRunning;
    Tile _map[TILE_COUNT_PER_SCREEN][TILE_COUNT_PER_SCREEN];
    unsigned long long _ticks;
};

#endif // ENGINE_H
