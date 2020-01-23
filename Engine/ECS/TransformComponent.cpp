#include "TransformComponent.h"

TransformComponent::TransformComponent() {
    this->position.zero();
}

TransformComponent::TransformComponent(int scale) {
    this->position.x = 400-64;
    this->position.y = 320-64;
    this->scale = scale;
}

TransformComponent::TransformComponent(float x, float y, int scale) {
    this->setPosition(x, y);
    this->scale = scale;
}

TransformComponent::TransformComponent(float x, float y) {
    this->setPosition(x, y);
}

TransformComponent::TransformComponent(float x, float y, int w, int h, int scale) {
    this->setPosition(x, y);
    this->width = w;
    this->height = h;
    this->scale = scale;
}

float TransformComponent::x() const {
    return this->position.x;
}

float TransformComponent::y() const {
    return this->position.y;
}

void TransformComponent::init() {
    this->velocity.zero();
}

void TransformComponent::update() {
//    this->position.x += this->velocity.x * static_cast<float>(this->speed);
//    this->position.y += this->velocity.y * static_cast<float>(this->speed);
}

void TransformComponent::setPosition(float x, float y) {
    this->position.x = x;
    this->position.y = y;
}