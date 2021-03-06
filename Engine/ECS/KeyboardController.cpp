#include "KeyboardController.h"

#include "../Helpers/KeyboardHandler.h"
#include <iostream>

void KeyboardController::init()
{
    transform = &entity->getComponent<TransformComponent>();
    sprite = &entity->getComponent<SpriteComponent>();
}

void KeyboardController::update()
{

    if(Engine::event.type == SDL_KEYDOWN) {
        switch(Engine::event.key.keysym.sym) {
        case SDLK_w:
//            this->positionComponent->velocity.x = 0;
            this->transform->velocity.y = -1;
            break;
        case SDLK_a:
            this->transform->velocity.x = -1;
//            this->positionComponent->velocity.y = 0;
            break;
        case SDLK_d:
            this->transform->velocity.x = 1;
//            this->positionComponent->velocity.y = 0;
            break;
        case SDLK_s:
            this->transform->velocity.y = 1;
//            this->positionComponent->velocity.x = 0;
            break;
        default:
            break;
        }
    }
    if(Engine::event.type == SDL_KEYUP) {
        switch(Engine::event.key.keysym.sym) {
        case SDLK_w:
            this->transform->velocity.y = 0;
            break;
        case SDLK_a:
            this->transform->velocity.x=0;
            break;
        case SDLK_d:
            this->transform->velocity.x = 0;
            break;
        case SDLK_s:
            this->transform->velocity.y = 0;
            break;
        case SDLK_ESCAPE:
            Engine::isRunning = false;
            break;
        default:
            break;
        }
    }
}