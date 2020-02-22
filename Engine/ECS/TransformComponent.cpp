#include "../Collision.h"
#include "../Helpers/Debug/Assert.h"
#include "TransformComponent.h"
#include <iostream>
#include "../Engine.h"

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

    auto& colliders(manager->getGroup(Engine::groupColliders));
    SDL_Rect playerCollider = *(&entity->getComponent<ColliderComponent>().getCollider());
    for(auto& collider : colliders) {
        SDL_Rect cCollider = collider->getComponent<ColliderComponent>().getCollider();
        CollisionPart cp = Collision::Colliding(playerCollider,cCollider);
        switch(cp) {
        case CP_TOP:
            if(this->velocity.y > 0) {
                this->velocity.y = 0;
            }
            break;
        case CP_LEFT:
            if(this->velocity.x > 0) {
                this->velocity.x = 0;
            }
            break;
        case CP_RIGHT:
            if(this->velocity.x < 0) {
                this->velocity.x = 0;
            }
            break;
        case CP_BOTTOM:
            if(this->velocity.y < 0) {
                this->velocity.y = 0;
            }
            break;
        }
    }
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
    if(velocity.y > 0)
        std::cout << velocity << std::endl;
    switch(static_cast<int>(velocity.x)) {
    case 1:
        this->position.x = this->position.x - 1;
        break;
    case -1:
        this->position.x = this->position.x + 1;
        break;
    default:
        break;
    }
    switch(static_cast<int>(velocity.y)) {
    case 1:
        this->position.y = this->position.y - 1;
        break;
    case -1:
        this->position.y = this->position.y + 1;
        break;
    default:
        break;
    }
}
TransformComponent::TransformComponent(float speed)
{
    this->speed = speed;
}
