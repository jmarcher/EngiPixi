#ifndef ENGINE_H
#define ENGINE_H

#define TILE_COUNT_PER_SCREEN 10
#define D_SHOW_FPS 0
#define D_SHOW_CROSSHAIR 2
#define D_ENABLE_VIGNETTE 4

#ifdef __linux__ 
    #include "SDL2/SDL.h"
    #include "SDL2/SDL_image.h"
#elif _WIN32
    #include "SDL.h"
    #include "SDL_image.h"
#endif

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "AssetManager.h"
#include "ECS/Components.h"
#include "TextureManager.h"

class ColliderComponent;
class AssetManager;

class Engine
{

protected:
    SDL_Window* window;
    int flags;
    unsigned long _frames;
    void handleKeyboardEvents(SDL_KeyboardEvent* event);

public:
    static SDL_Rect camera;

    static std::shared_ptr<Manager> managerPtr;
    
    static bool isRunning;

    Engine(int flags);

    ~Engine();

    void start(const std::string& title, int width, int height, bool fullScreen);

    void handleEvents();

    void update();

    void render();

    void clean();

    bool showFps() const;

    void drawFPS(const std::string& fps);


    static SDL_Renderer* renderer;

    static SDL_Event event;
    
    static AssetManager* assets;
    
    enum groupedLabels : std::size_t {
        groupMap,
        groupPlayers,
        groupEnemies,
        groupColliders,
        groupProjectiles
    };
};

#endif // ENGINE_H
