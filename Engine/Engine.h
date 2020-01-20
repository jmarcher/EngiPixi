#ifndef ENGINE_H
#define ENGINE_H

#define TILE_COUNT_PER_SCREEN 10

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <string>
#include <vector>

#include "TextureManager.h"
#include "ECS/ColliderComponent.h"

class ColliderComponent;

class Engine {
    
protected:
    SDL_Window *window;
    bool _isRunning;
    bool _showFps;

    void handleKeyboardEvents(SDL_KeyboardEvent *event);
    
public:
    Engine(bool showFps);

    ~Engine();

    void start(const std::string& title, int width, int height, bool fullScreen);

    void handleEvents();

    void update();

    void render();

    void clean();

    bool isRunning() const;

    void drawFPS(const std::string& fps);

    static SDL_Renderer *renderer;

    static SDL_Event event;
    
    static std::vector<ColliderComponent*> colliders;
    
    static void addTile(int id, int x, int y);

};

#endif // ENGINE_H
