#ifndef ENGIPIXI_KEYBOARDCONTROLLER_H
#define ENGIPIXI_KEYBOARDCONTROLLER_H

#include "../Engine.h"
#include "Components.h"
#include "EntityComponentSystem.h"

class KeyboardController : public Component
{
private:
    TransformComponent* transform;

public:
    void init() override;

    void update() override;
};

#endif // ENGIPIXI_KEYBOARDCONTROLLER_H
