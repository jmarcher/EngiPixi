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
    int range;
    int speed;
    int distance;

public:
    ProjectileComponent(int rng, int spd, Vector2D vel);

    ~ProjectileComponent();
    
    void init() override;

    void update() override;
};

#endif