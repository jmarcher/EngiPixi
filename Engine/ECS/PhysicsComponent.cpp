#include "PhysicsComponent.h"
#include <iostream>

PhysicsComponent::PhysicsComponent()
{
    this->acceleration = { 0, -1 };
}

PhysicsComponent::~PhysicsComponent()
{
}

void PhysicsComponent::init()
{
    transform = &entity->getComponent<TransformComponent>();
}

void PhysicsComponent::update()
{
    double deltaTime = FpsHelper::deltaTime();
    this->transform->velocity.y += ((GRAVITY / 2.0f) * deltaTime * deltaTime);
    
    std::cout << ((GRAVITY / 2.0f) * deltaTime * deltaTime) << std::endl;
}