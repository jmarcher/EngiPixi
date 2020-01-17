#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(const std::string& t)
{
    this->tag = t;
}

void ColliderComponent::init()
{
    if(!entity->hasComponents<TransformComponent>()) {
        entity->addComponent<TransformComponent>();
    }
    transform = &entity->getComponent<TransformComponent>();
}

void ColliderComponent::update()
{
    collider.x = static_cast<int>(transform->x());
    collider.y = static_cast<int>(transform->y());

    collider.w = transform->width * transform->scale;
    collider.h = transform->height * transform->scale;
}