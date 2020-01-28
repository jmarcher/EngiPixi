#ifndef ENGIPIXI_PROJECTILE_H
#define ENGIPIXI_PROJECTILE_H

#include "EntityComponentSystem.h"
#include "Components.h"
#include "../Math/Vector2D.h"

class ProjectileComponent : public Component
{
protected:
    TransformComponent* transform;
    Vector2D velocity;
    int range = 0;
    int speed = 0;
    int distance = 0;

public:
    ProjectileComponent(int rng, int spd, Vector2D vel);

    ~ProjectileComponent();
    
    void init() override;

    void update() override;
};

#endif