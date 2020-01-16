#ifndef ENGIPIXI_KEYBOARDCONTROLLER_H
#define ENGIPIXI_KEYBOARDCONTROLLER_H

#include "../Engine.h"
#include "EntityComponentSystem.h"
#include "Components.h"

class KeyboardController : public Component {
public:
    TransformComponent *transform;

    void init() override {
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override {
        if (Engine::event.type == SDL_KEYDOWN) {
            switch (Engine::event.key.keysym.sym) {
                case SDLK_w:
                    std::cout << "moving" << std::endl;
                    this->transform->velocity.y = -1;
                    break;
                case SDLK_a:
                    this->transform->velocity.x = -1;
                    break;
                case SDLK_d:
                    this->transform->velocity.x = 1;
                    break;
                case SDLK_s:
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
                    break;
                case SDLK_a:
                    this->transform->velocity.x = 0;
                    break;
                case SDLK_d:
                    this->transform->velocity.x = 0;
                    break;
                case SDLK_s:
                    this->transform->velocity.y = 0;
                    break;
                default:
                    break;
            }
        }
    }
};

#endif //ENGIPIXI_KEYBOARDCONTROLLER_H
