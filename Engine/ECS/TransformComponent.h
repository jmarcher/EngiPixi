#ifndef ENGIPIXI_TRANSFORMCOMPONENT_H
#define ENGIPIXI_TRANSFORMCOMPONENT_H

#include "Components.h"
#include "../Math/Vector2D.h"

class TransformComponent : public Component {
public:
    Vector2D position;
    TransformComponent() {
        this->position.x = 0.0f;
        this->position.y = 0.0f;
    }

    TransformComponent(float x, float y) {
        this->setPosition(x, y);
    }

    [[nodiscard]] float x() const {
        return this->position.x;
    }

    [[nodiscard]] float y() const {
        return this->position.y;
    }

    void update() override {

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
