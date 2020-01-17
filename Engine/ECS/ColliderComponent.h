
#ifndef ENGIPIXI_COLLIDERCOMPONENT_H
#define ENGIPIXI_COLLIDERCOMPONENT_H

#include "Components.h"
#include "EntityComponentSystem.h"
#include "SDL2/SDL.h"
#include <string>

class ColliderComponent : public Component
{
public:
    SDL_Rect collider;
    std::string tag;
    TransformComponent* transform;

    ColliderComponent(const std::string& t);

    void init() override;

    void update() override;
};

#endif // ENGIPIXI_COLLIDERCOMPONENT_H
