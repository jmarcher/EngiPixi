//
// Created by gordo on 24.02.20.
//
#include "PositionComponent.h"
#include "../Collision.h"

PositionComponent::PositionComponent(int x, int y) {
    position.x = x;
    position.y = y;
}

void PositionComponent::init() {
    Component::init();
}

void PositionComponent::update() {
    Component::update();
}

void PositionComponent::draw() {
    Component::draw();
}

float PositionComponent::x() const {
    return position.x;
}

float PositionComponent::y() const {
    return position.y;
}

bool PositionComponent::isBeforePlayer(const Vector2D &p, const SDL_Rect &playerRect) const {
    SDL_Rect destinationRect = *(&entity->getComponent<TileComponent>().destinationRect);
    return Collision::AABB(playerRect, destinationRect) &&
           (position.y < p.y);
}

bool PositionComponent::isAfterPlayer(const Vector2D &p, const SDL_Rect &playerRect) const  {
    SDL_Rect destinationRect = *(&entity->getComponent<TileComponent>().destinationRect);

    return !Collision::AABB(playerRect, destinationRect)  || (position.y >= p.y);
}