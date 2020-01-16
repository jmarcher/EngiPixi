#ifndef ENGIPIXI_TRANSFORMCOMPONENT_H
#define ENGIPIXI_TRANSFORMCOMPONENT_H

#include "Components.h"
#include "../Math/Vector2D.h"

class TransformComponent : public Component {
public:
    Vector2D position;
    Vector2D velocity;

    int width = 32;
    int height = 32;
    int scale = 1;
    int speed = 3;

    TransformComponent() {
        this->position.x = 0.0f;
        this->position.y = 0.0f;
    }

    TransformComponent(int scale) {
        this->setPosition(0.0f, 0.0f);
        this->scale = scale;
    }

    TransformComponent(float x, float y, int scale) {
        this->setPosition(x, y);
        this->scale = scale;
    }

    TransformComponent(float x, float y) {
        this->setPosition(x, y);
    }

    TransformComponent(float x, float y, int w, int h, int scale) {
        this->setPosition(x, y);
        this->width = w;
        this->height = h;
        this->scale = scale;
    }

    [[nodiscard]] float x() const {
        return this->position.x;
    }

    [[nodiscard]] float y() const {
        return this->position.y;
    }

    void init() override {
        this->velocity.x = 0;
        this->velocity.y = 0;
    }

    void update() override {
        this->position.x += this->velocity.x * this->speed;
        this->position.y += this->velocity.y * this->speed;
    }

    void addXPosition() {
        this->position.x++;
    }

    void subtractXPosition() {
        this->position.y--;
    }

    void setPosition(float x, float y) {
        this->position.x = x;
        this->position.y = y;
    }
};

#endif //ENGIPIXI_TRANSFORMCOMPONENT_H
