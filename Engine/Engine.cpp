#include "Engine.h"

//#include "ECS/EntityComponentSystem.h"
#include "ECS/Components.h"
#include <string>

SDL_Renderer *Engine::renderer = nullptr;

Map *map;
Manager *manager = new Manager();

auto &player(manager->addEntity());

Engine::Engine(bool showFps) {
    this->_isRunning = false;
    this->_showFps = showFps;
    this->_ticks = 0;
    this->window = nullptr;
}

Engine::~Engine() {
}

void Engine::start(const char *title, int width, int height, bool fullScreen) {
    int flags = 0;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        TTF_Init();
        this->_isRunning = true;
        if (fullScreen) {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        // Init tiles
        for (auto &x : _map) {
            for (auto &y : x) {
                y = Tile();
            }
        }

        this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(this->window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

    } else {
        this->_isRunning = false;
    }

    map = new Map();

    player.addComponent<TransformComponent>(0, 0);
    player.addComponent<SpriteComponent>("../assets/sprites/player.png");
}

bool Engine::isRunning() const {
    return this->_isRunning;
}

void Engine::handleKeyboardEvents(SDL_KeyboardEvent *key) {
    switch (key->keysym.sym) {
        case SDLK_ESCAPE:
            this->_isRunning = false;
            break;
        case SDLK_RIGHT:
            player.getComponent<TransformComponent>().addXPosition();
            break;
            case SDLK_LEFT:
                player.getComponent<TransformComponent>().subtractXPosition();
            break;
        default:
            break;
    }
}

void Engine::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            this->_isRunning = false;
            break;
        case SDL_KEYDOWN:
            this->handleKeyboardEvents(&event.key);
        default:
            break;
    }
}

void Engine::update() {
    this->_ticks++;

    manager->update();
    player.getComponent<TransformComponent>().position.add(Vector2D(0,5));
    if (player.getComponent<TransformComponent>().x() > 100) {
        player.getComponent<SpriteComponent>().setTexture("../assets/sprites/enemy.png");
    }else{
        player.getComponent<SpriteComponent>().setTexture("../assets/sprites/player.png");
    }
}

void Engine::render() {
    SDL_RenderClear(renderer);
    map->draw();

    manager->draw();

    // If the FPS are show, we can wait to present and drawFPS will present
    // the screen for us
    if (!this->_showFps)
        SDL_RenderPresent(renderer);
}

void Engine::clean() {
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "SDL Cleared" << std::endl;
}

void Engine::drawFPS(const char *fps) {
    TTF_Font *Sans = TTF_OpenFont("../assets/fonts/ani.ttf", 32);

    SDL_Color White = {255, 255, 255, 255};
    SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Sans, fps, White);
    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);

    SDL_Rect message_rect = {10, 10, 100, 100}; //create a rect
    SDL_RenderCopy(renderer, message, nullptr, &message_rect);

    // We can safely call SDL_RenderPreset because when using this function the
    // draw method will not present anything.
    SDL_RenderPresent(renderer);
}
