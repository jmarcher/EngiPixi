
#ifndef ENGIPIXI_COLLIDERCOMPONENT_H
#define ENGIPIXI_COLLIDERCOMPONENT_H

#include <string>
#include "SDL2/SDL.h"
#include "EntityComponentSystem.h"
#include "Components.h"

class ColliderComponent : public Component {
public:
    SDL_Rect collider;
    std::string tag;
    TransformComponent *transform;

    ColliderComponent(const std::string &t) {
        this->tag = t;
    }

    void init() override {
        if (!entity->hasComponents<TransformComponent>()) {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override {
        collider.x = static_cast<int>(transform->x());
        collider.y = static_cast<int>(transform->y());

        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }
};

#endif //ENGIPIXI_COLLIDERCOMPONENT_H
