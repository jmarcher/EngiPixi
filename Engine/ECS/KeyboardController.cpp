#include "KeyboardController.h"

void KeyboardController::init() {
    transform = &entity->getComponent<TransformComponent>();
    sprite = &entity->getComponent<SpriteComponent>();
}

void KeyboardController::update() {
    if (Engine::event.type == SDL_KEYDOWN) {
        switch (Engine::event.key.keysym.sym) {
            case SDLK_w:
                this->sprite->play("walk");
                this->transform->velocity.y = -1;
                break;
            case SDLK_a:
                this->sprite->play("walk");
                this->sprite->setHorizontalFlip();
                this->transform->velocity.x = -1;
                break;
            case SDLK_d:
                sprite->play("walk");
                this->transform->velocity.x = 1;
                break;
            case SDLK_s:
                this->sprite->play("walk2");
                this->transform->velocity.y = 1;
                break;
            default:
                break;
        }
    }
    if (Engine::event.type == SDL_KEYUP) {
        switch (Engine::event.key.keysym.sym) {
            case SDLK_w:
                this->transform->velocity.y = 0;
                this->sprite->play("idle");
                break;
            case SDLK_a:
                this->transform->velocity.x = 0;
                this->sprite->setNoFlip();
                this->sprite->play("idle");
                break;
            case SDLK_d:
                this->transform->velocity.x = 0;
                this->sprite->play("idle");
                break;
            case SDLK_s:
                this->transform->velocity.y = 0;
                this->sprite->play("idle");
                break;
            default:
                break;
        }
    }
}