#include "ColliderComponent.h"
#include "../TextureManager.h"

ColliderComponent::ColliderComponent(const std::string& t)
{
    this->tag = t;
}

ColliderComponent::ColliderComponent(const std::string& t, int xPosition, int yPosition, int size) {
    this->tag = t;
    collider.x = xPosition;
    collider.y = yPosition;
    collider.h = collider.w = size;
}
void ColliderComponent::init()
{
    if(!entity->hasComponents<TransformComponent>()) {
        entity->addComponent<TransformComponent>();
    }
    transform = &entity->getComponent<TransformComponent>();

    this->displayTexture = TextureManager::load("../assets/sprites/collider.png");
    this->sourceRect = { 0,0,32,32 };
    this->destinationRect = { this->collider.x, this->collider.y, this->collider.w,this->collider.h};

}

void ColliderComponent::update()
{
    if (this->tag != "terrain") {
        collider.x = static_cast<int>(transform->x());
        collider.y = static_cast<int>(transform->y());

        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }

    this->destinationRect.x = collider.x - Engine::camera.x;
    this->destinationRect.y = collider.y - Engine::camera.y;
}

void ColliderComponent::draw() {
    TextureManager::draw(this->displayTexture, this->sourceRect, this->destinationRect, SDL_FLIP_NONE);
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
