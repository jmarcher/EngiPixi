#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "../Helpers/FpsHelper.h"
#include "../Math/Vector2D.h"
#include "EntityComponentSystem.h"
#include "Components.h"

const float GRAVITY = 9.8f;

class TransformComponent;

class PhysicsComponent : public Component
{
protected:
    TransformComponent* transform;
    Vector2D acceleration;

public:
    [[deprecated]]
    PhysicsComponent();
    ~PhysicsComponent();

    void init() override;

    void update() override;
};

#endif // PHYSICSCOMPONENT_H
