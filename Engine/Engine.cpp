#include "Engine.h"

#include "Collision.h"
#include "Map.h"

#include <sstream>
#include "Helpers/FpsHelper.h"
SDL_Rect Engine::camera = { 0, 0, 800, 640 };

SDL_Renderer* Engine::renderer = nullptr;

SDL_Event Engine::event;

Map* map;

Manager manager;

AssetManager* Engine::assets = new AssetManager(&manager);

auto& player(manager.addEntity());
auto& fpsLabel(manager.addEntity());
auto& label(manager.addEntity());

bool Engine::isRunning = false;

auto& tiles(manager.getGroup(Engine::groupMap));
auto& players(manager.getGroup(Engine::groupPlayers));
auto& colliders(manager.getGroup(Engine::groupColliders));
auto& projectiles(manager.getGroup(Engine::groupProjectiles));

Engine::Engine(int flags)
{
    Engine::isRunning = false;
    this->flags = flags;
    this->window = nullptr;
}

Engine::~Engine()
{
}

void Engine::start(const std::string& title, int width, int height, bool fullScreen)
{
    int flags = 0;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        Engine::isRunning = true;
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
        Engine::isRunning = false;
    }

    if(TTF_Init() == -1) {
        std::cout << "Can not initialize fonts" << std::endl;
    }

    assets->addTexture("terrain", "../assets/sprites/terrain_big_map.png");
    assets->addTexture("player", "../assets/sprites/Character_2.png");
    assets->addTexture("projectile", "../assets/sprites/projectile.png");

    assets->addFont("ani", "../assets/fonts/ani.ttf", 64);

    map = new Map("terrain", 3, 32);

    map->load("../assets/sprites/big_map.map", 32, 32);

    player.addComponent<TransformComponent>(92, 92, 2);
    player.addComponent<SpriteComponent>("player", true);
    player.addComponent<KeyboardController>();
    //    player.addComponent<JoystickController>();
    player.addComponent<ColliderComponent>("player");
//    player.addComponent<PhysicsComponent>();
    player.addGroup(groupPlayers);

    SDL_Color white = { 255, 255, 255 };

    label
        .addComponent<UILabel>("Text", 10, 10, "ani", white);
    fpsLabel.addComponent<UILabel>("0", 640, 10, "ani", white);

    assets->createProjectile(Vector2D(200, 200), Vector2D(2, 0), 200, 2, "projectile");
    assets->createProjectile(Vector2D(150, 100), Vector2D(2, -1), 200, 1, "projectile");
    assets->createProjectile(Vector2D(400, 50), Vector2D(2, 0), 200, 1, "projectile");
}

void Engine::handleEvents()
{
    SDL_PollEvent(&event);

    switch(event.type) {
    case SDL_QUIT:
        Engine::isRunning = false;
        break;
    default:
        break;
    }
}

void Engine::update()
{
    SDL_Rect playerCollider = player.getComponent<ColliderComponent>().getCollider();
    Vector2D playerPosition = player.getComponent<TransformComponent>().position;
    
    this->_frames++;
    manager.refresh();
    manager.update();

    for(auto& collider : colliders) {
        SDL_Rect cCollider = collider->getComponent<ColliderComponent>().getCollider();
        if(Collision::AABB(cCollider, playerCollider)) {
            player.getComponent<TransformComponent>().position = playerPosition;
        }
    }

    for(auto& p : projectiles) {
        SDL_Rect pCollider = p->getComponent<ColliderComponent>().getCollider();
        if(Collision::AABB(playerCollider, pCollider)) {
            p->destroy();
        }
    }

    camera.x = player.getComponent<TransformComponent>().position.x -
        (400 - (player.getComponent<SpriteComponent>().getDestinationRect().w / 2));
    camera.y = player.getComponent<TransformComponent>().position.y -
        (320 - (player.getComponent<SpriteComponent>().getDestinationRect().h / 2));

    if(camera.x < 0)
        camera.x = 0;
    if(camera.y < 0)
        camera.y = 0;
    if(camera.x > static_cast<int>(map->getWidth()) - camera.w)
        camera.x = map->getWidth() - camera.w;
    if(camera.y > static_cast<int>(map->getHeight()) - camera.h)
        camera.y = map->getHeight() - camera.h;
}

void Engine::render()
{
    SDL_RenderClear(renderer);
    //    map->draw();

    //    manager.draw();

    for(auto& t : tiles) {
        t->draw();
    }

    for(auto& c : colliders) {
        c->draw();
    }

    for(auto& p : players) {
        p->draw();
    }

    for(auto& p : projectiles) {
        p->draw();
    }

    if((this->flags & D_SHOW_CROSSHAIR) > 0) {
        // Debug Lines
        SDL_RenderDrawLine(renderer, 400, 0, 400, 640);
        SDL_RenderDrawLine(renderer, 0, 320, 800, 320);
    }

    if (!((this->flags & D_SHOW_FPS) > 0)) {
        // If the FPS are show, we can wait to present and drawFPS will present
        // the screen for us
        SDL_RenderPresent(renderer);
    }
}

bool Engine::showFps() const
{
    return (this->flags & D_SHOW_FPS) > 0;
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
    fpsLabel.getComponent<UILabel>().setText(fps, "ani");
    fpsLabel.draw();

    
        // We can safely call SDL_RenderPreset because when using this function the
        // draw method will not present anything.
        SDL_RenderPresent(renderer);
}
