#include "../TextureManager.h"
#include "ColliderComponent.h"
#include "../Helpers/Logger.h"

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
    if(entity->hasComponent<TransformComponent>()){
        positionComponent = &entity->getComponent<TransformComponent>();
    }else if (entity->hasComponent<PositionComponent>()) {
        positionComponent = &entity->getComponent<PositionComponent>();
    } else {
        positionComponent = nullptr;
    }

    this->displayTexture = TextureManager::load("../assets/sprites/collider.png");
    this->sourceRect = {this->collider.x, this->collider.y, this->collider.w, this->collider.h};
    this->destinationRect = {this->collider.x, this->collider.y, this->collider.w, this->collider.h};
}

void ColliderComponent::update() {
    if (positionComponent != nullptr && std::strcmp(this->tag, "terrain") != 0) {
        LOG(positionComponent->getPosition());
        collider.x = sourceRect.x + static_cast<int>(positionComponent->x());
        collider.y = sourceRect.y + static_cast<int>(positionComponent->y());

//        collider.w = positionComponent->width * positionComponent->scale;
//        collider.h = positionComponent->height * positionComponent->scale;
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

ColliderComponent &ColliderComponent::setPosition(PositionComponent *position) {
    this->positionComponent = position;
    return *this;
}

const SDL_Rect &ColliderComponent::getCollider() const {
    return collider;
}

const char *ColliderComponent::getTag() const {
    return tag;
}

PositionComponent *ColliderComponent::getPosition() {
    return positionComponent;
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
