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

    Engine::colliders.push_back(this);
}

void ColliderComponent::update()
{
    collider.x = static_cast<int>(transform->x());
    collider.y = static_cast<int>(transform->y());

    collider.w = transform->width * transform->scale;
    collider.h = transform->height * transform->scale;
}

ColliderComponent& ColliderComponent::setCollider(const SDL_Rect& collider)
{
    this->collider = collider;
    return *this;
}

ColliderComponent& ColliderComponent::setTag(const std::string& tag)
{
    this->tag = tag;
    return *this;
}

ColliderComponent& ColliderComponent::setTransform(TransformComponent* transform)
{
    this->transform = transform;
    return *this;
}

const SDL_Rect& ColliderComponent::getCollider() const
{
    return collider;
}

const std::string& ColliderComponent::getTag() const
{
    return tag;
}

TransformComponent* ColliderComponent::getTransform()
{
    return transform;
}
