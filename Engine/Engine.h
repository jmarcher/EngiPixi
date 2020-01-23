#ifndef ENGINE_H
#define ENGINE_H

#define TILE_COUNT_PER_SCREEN 10

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include <string>
#include <vector>

#include "ECS/ColliderComponent.h"
#include "TextureManager.h"

class ColliderComponent;

class Engine
{

protected:
    TTF_Font* debugFont;
    SDL_Window* window;
    bool _showFps;
    unsigned long _frames;
    void handleKeyboardEvents(SDL_KeyboardEvent* event);

public:
    static bool isRunning;

    Engine(bool showFps);

    ~Engine();

    void start(const std::string& title, int width, int height, bool fullScreen);

    void handleEvents();

    void update();

    void render();

    void clean();

    static void addTile(int sourceX, int sourceU, int xPosition, int yPosition);

    void drawFPS(const std::string& fps);

    static SDL_Rect camera;

    static SDL_Renderer* renderer;

    static SDL_Event event;

    static std::vector<ColliderComponent*> colliders;
};

#endif // ENGINE_H
