#ifndef ENGINE_H
#define ENGINE_H

#define TILE_COUNT_PER_SCREEN 10

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>

#include "Map.h"
#include "TextureManager.h"
#include "Tile.h"


class Engine {
public:
    Engine(bool showFps);

    ~Engine();

    void start(const char *title, int width, int height, bool fullScreen);

    void handleEvents();

    void update();

    void render();

    void clean();

    bool isRunning() const;

    void drawFPS(const char *fps);

    static SDL_Renderer *renderer;

    static SDL_Event event;

protected:
    SDL_Window *window;
    bool _isRunning, _showFps;
    Tile _map[TILE_COUNT_PER_SCREEN][TILE_COUNT_PER_SCREEN];
    unsigned long long _ticks;

    void handleKeyboardEvents(SDL_KeyboardEvent *event);
};

#endif // ENGINE_H
