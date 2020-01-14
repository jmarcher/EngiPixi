#include "Engine.h"

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
        for(auto & x : _map) {
            for(auto & y : x) {
                y = Tile();
            }
        }

        this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if(this->window) {
            std::cout << "Window initialized" << std::endl;
        }

        this->renderer = SDL_CreateRenderer(this->window, -1, 0);
        if(this->renderer) {
            std::cout << "Renderer initialized" << std::endl;
            SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
        }

    } else {
        this->_isRunning = false;
    }
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
    std::cout << this->_ticks << std::endl;
}

void Engine::draw()
{
    SDL_RenderClear(this->renderer);
}

void Engine::present()
{
    SDL_RenderPresent(this->renderer);
}

void Engine::clean()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
    std::cout << "SDL Cleared" << std::endl;
}