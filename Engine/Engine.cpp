#include "Engine.h"

//#include "ECS/EntityComponentSystem.h"

#include "Collision.h"
#include <string>

SDL_Renderer* Engine::renderer = nullptr;

SDL_Event Engine::event;

std::vector<ColliderComponent*> Engine::colliders;

Map* map;
Manager* manager = new Manager();

auto& player(manager->addEntity());
auto& wall(manager->addEntity());
auto& tile_0(manager->addEntity());
auto& tile_1(manager->addEntity());
auto& tile_2(manager->addEntity());

Engine::Engine(bool showFps)
{
    this->_isRunning = false;
    this->_showFps = showFps;
    this->_ticks = 0;
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

    tile_0.addComponent<TileComponent>(200, 200, 32, 32, WATER);
    
    tile_1.addComponent<TileComponent>(250, 250, 32, 32, DIRT);
    tile_1.addComponent<ColliderComponent>("dirt");

    tile_2.addComponent<TileComponent>(150, 150, 32, 32, GRASS);
    tile_2.addComponent<ColliderComponent>("grass");

    player.addComponent<TransformComponent>(0, 0, 2);
    player.addComponent<SpriteComponent>("../assets/sprites/player.png");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");

    wall.addComponent<TransformComponent>(600.0f, 600.0f, 300, 20, 1);
    wall.addComponent<SpriteComponent>("../assets/sprites/dirt.png");
    wall.addComponent<ColliderComponent>("wall");
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
    manager->refresh();
    manager->update();
    
    for(auto collider : colliders){
        if(Collision::AABB(player.getComponent<ColliderComponent>(), *collider));
    }

    if(Collision::AABB(
           player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider)) {
        player.getComponent<TransformComponent>().velocity * -1;
        std::cout << "Colliding" << std::endl;
    }
}

void Engine::render()
{
    SDL_RenderClear(renderer);
//    map->draw();

    manager->draw();

    // If the FPS are show, we can wait to present and drawFPS will present
    // the screen for us
    if(!this->_showFps)
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
    TTF_Font* Sans = TTF_OpenFont("../assets/fonts/ani.ttf", 32);

    SDL_Color White = { 255, 255, 255, 255 };
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, fps.c_str(), White);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);

    SDL_Rect message_rect = { 10, 10, 100, 100 }; // create a rect
    SDL_RenderCopy(renderer, message, nullptr, &message_rect);

    // We can safely call SDL_RenderPreset because when using this function the
    // draw method will not present anything.
    SDL_RenderPresent(renderer);
}
