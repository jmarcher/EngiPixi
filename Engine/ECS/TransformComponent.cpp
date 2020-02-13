#include "TransformComponent.h"
#include <iostream>
#include "../Helpers/Debug/Assert.h"

TransformComponent::TransformComponent()
{
    this->position.zero();
}

TransformComponent::TransformComponent(int scale)
{
    this->position.x = 400 - 64;
    this->position.y = 320 - 64;
    this->scale = scale;
}

TransformComponent::TransformComponent(float x, float y, int scale)
{
    this->setPosition(x, y);
    this->scale = scale;
}

TransformComponent::TransformComponent(float x, float y)
{
    this->setPosition(x, y);
}

TransformComponent::TransformComponent(float x, float y, int w, int h, int scale)
{
    this->setPosition(x, y);
    this->width = w;
    this->height = h;
    this->scale = scale;
}

float TransformComponent::x() const
{
    return this->position.x;
}

float TransformComponent::y() const
{
    return this->position.y;
}

void TransformComponent::init()
{
    this->velocity.zero();
}

void TransformComponent::update()
{
    this->position.x += this->velocity.x * this->speed;
    this->position.y += this->velocity.y * this->speed;
}

void TransformComponent::setPosition(float x, float y)
{
    this->position.x = x;
    this->position.y = y;
}
TransformComponent::TransformComponent(int w, int h, int scale)
{
    this->width = w;
    this->height = h;
    this->scale = scale;
    this->setPosition(0, 0);
}
void TransformComponent::bounce(const Vector2D& oldPosition)
{
    Vector2D result = (position - oldPosition).normalized();
    
    switch(static_cast<int>(result.x)) {
    case 1:
        this->position.x = this->position.x + 2;
    case -1:
        this->position.x = this->position.x - 2;
    default:
        break;
    }
    switch(static_cast<int>(result.y)) {
    case 1:
        this->position.y = this->position.y + 2;
    case -1:
        this->position.y = this->position.y - 2;
    default:
        break;
    }
}
TransformComponent::TransformComponent(float speed)
{
    this->speed = speed;
}
