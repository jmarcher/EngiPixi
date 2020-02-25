//
// Created by gordo on 24.02.20.
//

#ifndef ENGIPIXI_POSITIONCOMPONENT_H
#define ENGIPIXI_POSITIONCOMPONENT_H

#include "EntityComponentSystem.h"
#include "Components.h"


class PositionComponent:public Component{
public:
    Vector2D position;
    PositionComponent(int x, int y);
    PositionComponent(Vector2D p):position(p){}

    void init() override;

    void update() override;

    void draw() override;

    ~PositionComponent() {

    }
};


#endif //ENGIPIXI_POSITIONCOMPONENT_H
