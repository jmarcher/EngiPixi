#include "Engine.h"

//#include "ECS/EntityComponentSystem.h"

#include "Collision.h"
#include "ECS/Components.h"
#include "Map.h"

SDL_Renderer *Engine::renderer = nullptr;

SDL_Event Engine::event;

SDL_Rect Engine::camera = {0, 0, 800, 640};

std::vector<ColliderComponent *> Engine::colliders;

Manager manager;

auto &player(manager.addEntity());
auto &wall(manager.addEntity());

enum groupedLabels : std::size_t {
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders,
};
bool Engine::isRunning = false;

auto &tiles(manager.getGroup(groupMap));
auto &players(manager.getGroup(groupPlayers));
auto &enemies(manager.getGroup(groupEnemies));
auto &colliders(manager.getGroup(groupColliders));

Engine::Engine(bool showFps) {
    Engine::isRunning = false;
    this->_showFps = showFps;
    this->window = nullptr;
}

Engine::~Engine() {
}

void Engine::start(const std::string &title, int width, int height, bool fullScreen) {
    int flags = 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        TTF_Init();
        this->debugFont = TTF_OpenFont("../assets/fonts/ani.ttf", 64);
        Engine::isRunning = true;
        if (fullScreen) {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        this->window =
                SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(this->window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

    } else {
        Engine::isRunning = false;
    }

    Map::load("../assets/data/maps/map.map", 25, 20);

    player.addComponent<TransformComponent>(4);
    player.addComponent<SpriteComponent>("../assets/sprites/player_anims.png", true);
    player.addComponent<KeyboardController>();
    //    player.addComponent<JoystickController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);

}


void Engine::handleEvents() {
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            Engine::isRunning = false;
            break;
        default:
            break;
    }
}

void Engine::update() {
    this->_frames++;
    manager.refresh();
    manager.update();

    camera.x = player.getComponent<TransformComponent>().position.x - 400;
    camera.y = player.getComponent<TransformComponent>().position.y - 320;

    if (camera.x < 0)
        camera.x = 0;
    if (camera.y < 0)
        camera.y = 0;
    if (camera.x > camera.w)
        camera.x = camera.w;
    if (camera.y > camera.h)
        camera.y = camera.h;
}

void Engine::render() {
    SDL_RenderClear(renderer);
    //    map->draw();

    //    manager.draw();

    for (auto &t : tiles) {
        t->draw();
    }
    for (auto &p : players) {
        p->draw();
    }
    for (auto &e : enemies) {
        e->draw();
    }
    for (auto &c : colliders) {
        c->draw();
    }
    // If the FPS are show, we can wait to present and drawFPS will present
    // the screen for us
    SDL_RenderPresent(renderer);
}

void Engine::clean() {
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "SDL Cleared" << std::endl;
}

void Engine::drawFPS(const std::string &fps) {
    SDL_Color White = {255, 255, 255, 255};
    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(this->debugFont, fps.c_str(), White);
    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);

    SDL_Rect message_rect = {10, 10, 100, 100}; // create a rect
    SDL_RenderCopy(renderer, message, nullptr, &message_rect);

    // We can safely call SDL_RenderPreset because when using this function the
    // draw method will not present anything.
    SDL_RenderPresent(renderer);
}

void Engine::addTile(int sourceX, int sourceY, int xPosition, int yPosition) {
    auto &tile(manager.addEntity());
    tile.addComponent<TileComponent>(sourceX, sourceY, xPosition, yPosition, "../assets/sprites/terrain_ss.png");
    tile.addGroup(groupMap);
}
