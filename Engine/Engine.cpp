#include "Engine.h"

//#include "ECS/EntityComponentSystem.h"

#include "Collision.h"
#include "ECS/Components.h"
#include "Map.h"
#include "SDL2/SDL_image.h"
#include <string>

SDL_Renderer* Engine::renderer = nullptr;

SDL_Event Engine::event;

std::vector<ColliderComponent*> Engine::colliders;

Map* map;
Manager manager;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

enum groupedLabels : std::size_t {
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders,
};

Engine::Engine(bool showFps)
{
    this->_isRunning = false;
    this->_showFps = showFps;
    this->window = nullptr;
}

Engine::~Engine()
{
}

void Engine::start(const std::string& title, int width, int height, bool fullScreen)
{
    int flags = 0;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        TTF_Init();
        this->debugFont = TTF_OpenFont("../assets/fonts/ani.ttf", 64);
        this->_isRunning = true;
        if(fullScreen) {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        this->window =
            SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(this->window, -1, 0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

    } else {
        this->_isRunning = false;
    }

    map = new Map();

    Map::load("../assets/data/maps/intro.map", TILE_SIZE, TILE_SIZE);

    player.addComponent<TransformComponent>(0, 0, 2);
    player.addComponent<SpriteComponent>("../assets/sprites/player_anims.png", true);
    player.addComponent<KeyboardController>();
    //    player.addComponent<JoystickController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);

    wall.addComponent<TransformComponent>(600.0f, 600.0f, 300, 20, 1);
    wall.addComponent<SpriteComponent>("../assets/sprites/dirt.png");
    wall.addComponent<ColliderComponent>("wall");
    wall.addGroup(groupMap);
}

bool Engine::isRunning() const
{
    return this->_isRunning;
}

void Engine::handleEvents()
{
    SDL_PollEvent(&event);

    switch(event.type) {
    case SDL_QUIT:
        this->_isRunning = false;
        break;
    default:
        break;
    }
}

void Engine::update()
{
    this->_frames++;
    manager.refresh();
    manager.update();

    for(auto collider : colliders) {
        if(Collision::AABB(player.getComponent<ColliderComponent>(), *collider))
            ;
    }

    if(Collision::AABB(
           player.getComponent<ColliderComponent>().getCollider(), wall.getComponent<ColliderComponent>().getCollider())) {
        player.getComponent<TransformComponent>().velocity * -1;
        std::cout << "Colliding" << std::endl;
    }
}
auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));
auto& colliders(manager.getGroup(groupColliders));

void Engine::render()
{
    SDL_RenderClear(renderer);
    //    map->draw();

    //    manager.draw();

    for(auto& t : tiles) {
        t->draw();
    }
    for(auto& p : players) {
        p->draw();
    }
    for(auto& e : enemies) {
        e->draw();
    }
    for(auto& c : colliders) {
        c->draw();
    }
    // If the FPS are show, we can wait to present and drawFPS will present
    // the screen for us
    SDL_RenderPresent(renderer);
}

void Engine::clean()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "SDL Cleared" << std::endl;
}

void Engine::drawFPS(const std::string& fps)
{
    SDL_Color White = { 255, 255, 255, 255 };
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(this->debugFont, fps.c_str(), White);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);

    SDL_Rect message_rect = { 10, 10, 100, 100 }; // create a rect
    SDL_RenderCopy(renderer, message, nullptr, &message_rect);

    // We can safely call SDL_RenderPreset because when using this function the
    // draw method will not present anything.
    SDL_RenderPresent(renderer);
    delete message;
}
void Engine::addTile(int id, int x, int y)
{
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, TILE_SIZE, TILE_SIZE, id);
    tile.addGroup(groupMap);
}
