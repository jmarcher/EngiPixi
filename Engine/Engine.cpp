#include "Engine.h"

#include "EntityComponentSystem.h"
#include "Components.h"

GameObject* player;
GameObject* enemy;
Map * map;

Manager manager;
auto & newPlayer(manager.addEntity());

SDL_Renderer* Engine::renderer = nullptr;

Engine::Engine()
{
    this->_isRunning = false;
}

Engine::~Engine()
{
}

void Engine::start(const char* title, int width, int height, bool fullScreen)
{
    int flags = 0;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        this->_isRunning = true;
        if(fullScreen) {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        // Init tiles
        for(auto& x : _map) {
            for(auto& y : x) {
                y = Tile();
            }
        }

        this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(this->window, -1, 0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

    } else {
        this->_isRunning = false;
    }
    player = new GameObject("../assets/sprites/player.png", 0, 0);
    enemy = new GameObject("../assets/sprites/enemy.png", 50, 50);
    map = new Map();
    
    newPlayer.addComponent<PositionComponent>();
    newPlayer.getComponent<PositionComponent>().setPosition(500,500);
}

bool Engine::isRunning() const
{
    return this->_isRunning;
}

void Engine::handleEvents()
{
    SDL_Event event;
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
    this->_ticks++;

    player->update();
    enemy->update();
    manager.update();
    
    std::cout << newPlayer.getComponent<PositionComponent>().x() << "," <<
    newPlayer.getComponent<PositionComponent>().y() << std::endl;

//    std::cout << this->_ticks << std::endl;
}

void Engine::render()
{
    SDL_RenderClear(renderer);
    map->draw();
    player->render();
    enemy->render();
    SDL_RenderPresent(renderer);
}

void Engine::clean()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "SDL Cleared" << std::endl;
}