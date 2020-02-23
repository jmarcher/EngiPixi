#include "../TextureManager.h"
#include "ColliderComponent.h"

ColliderComponent::ColliderComponent(const char *t) {
    this->tag = t;
}

ColliderComponent::ColliderComponent(const char *t, int xPosition, int yPosition, int size) {
    this->tag = t;
    collider.x = xPosition;
    collider.y = yPosition;
    collider.h = collider.w = size;
}

void ColliderComponent::init() {
    if (entity->hasComponent<TransformComponent>()) {
        transform = &entity->getComponent<TransformComponent>();
    } else {
        transform = nullptr;
    }

    this->displayTexture = TextureManager::load("../assets/sprites/collider.png");
    this->sourceRect = {this->collider.x, this->collider.y, this->collider.w, this->collider.h};
    this->destinationRect = {this->collider.x, this->collider.y, this->collider.w, this->collider.h};
}

void ColliderComponent::update() {
    if (std::strcmp(this->tag, "terrain") != 0) {
        collider.x = sourceRect.x + static_cast<int>(transform->x());
        collider.y = sourceRect.y + static_cast<int>(transform->y());

//        collider.w = transform->width * transform->scale;
//        collider.h = transform->height * transform->scale;
    }

    this->destinationRect.x = collider.x - Engine::camera.x;
    this->destinationRect.y = collider.y - Engine::camera.y;
}

void ColliderComponent::draw() {
    if (std::strcmp(this->tag, "player") == 0) {
        SDL_SetRenderDrawColor(Engine::renderer, 255, 0, 100, 255);
    } else {
        SDL_SetRenderDrawColor(Engine::renderer, 227, 5, 197, 255);

    }
    SDL_RenderDrawRect(Engine::renderer, &this->destinationRect);
//    TextureManager::draw(this->displayTexture, this->sourceRect, this->destinationRect, SDL_FLIP_NONE);
}

ColliderComponent &ColliderComponent::setCollider(const SDL_Rect &collider) {
    this->collider = collider;
    this->init();
    return *this;
}

ColliderComponent &ColliderComponent::setTag(const char *tag) {
    this->tag = tag;
    return *this;
}

ColliderComponent &ColliderComponent::setTransform(TransformComponent *transform) {
    this->transform = transform;
    return *this;
}

const SDL_Rect &ColliderComponent::getCollider() const {
    return collider;
}

const char *ColliderComponent::getTag() const {
    return tag;
}

TransformComponent *ColliderComponent::getTransform() {
    return transform;
}

ColliderComponent::ColliderComponent(const char *t, const Offset &transformOffset) {
    this->tag = t;
    this->m_transformsSprite = true;
    this->m_transformOffset = transformOffset;
}

ColliderComponent::ColliderComponent(const char *t,
                                     int xPosition,
                                     int yPosition,
                                     int size,
                                     const Offset &transformOffset) {
    this->tag = t;
    collider.x = xPosition;
    collider.y = yPosition;
    collider.h = collider.w = size;
    this->m_transformsSprite = true;
    this->m_transformOffset = transformOffset;
}

ColliderComponent::ColliderComponent(const char *t, int xPosition, int yPosition, int width, int height) {
    this->tag = t;
    collider.x = xPosition;
    collider.y = yPosition;
    collider.h = height;
    collider.w = width;
}
