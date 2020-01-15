#ifndef ENGIPIXI_POSITIONCOMPONENT_H
#define ENGIPIXI_POSITIONCOMPONENT_H

#include "Components.h"

class PositionComponent : public Component {
protected:
    int xPosition;
    int yPosition;

public:
    PositionComponent() {
        this->xPosition = 0;
        this->yPosition = 0;
    }

    PositionComponent(int x, int y) {
        this->setPosition(x, y);
    }

    [[nodiscard]] int x() const {
        return this->xPosition;
    }

    [[nodiscard]] int y() const {
        return this->yPosition;
    }

    void update() override {
        this->xPosition++;
        this->yPosition++;
    }

    void setPosition(int x, int y) {
        this->xPosition = x;
        this->yPosition = y;
    }
};

#endif //ENGIPIXI_POSITIONCOMPONENT_H
