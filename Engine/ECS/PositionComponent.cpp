//
// Created by gordo on 24.02.20.
//

#include "PositionComponent.h"

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
