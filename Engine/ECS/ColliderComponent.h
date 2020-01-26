
#ifndef ENGIPIXI_COLLIDERCOMPONENT_H
#define ENGIPIXI_COLLIDERCOMPONENT_H

#ifdef __linux__ 
#include "SDL2/SDL.h"
#elif _WIN32
#include "SDL.h"
#endif

#include "Components.h"
#include "EntityComponentSystem.h"
#include <string>

class ColliderComponent : public Component
{
protected:
    SDL_Rect collider;
    TransformComponent* transform;
    std::string tag;

public:
    ColliderComponent(const std::string& t);

    ColliderComponent& setCollider(const SDL_Rect& collider);

    ColliderComponent& setTag(const std::string& tag);

    ColliderComponent& setTransform(TransformComponent* transform);

    const SDL_Rect& getCollider() const;

    const std::string& getTag() const;
    
    TransformComponent* getTransform();
    
    void init() override;

    void update() override;
};

#endif // ENGIPIXI_COLLIDERCOMPONENT_H
