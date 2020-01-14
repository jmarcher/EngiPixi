#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "EntityComponentSystem.h"

class PositionComponent : public Component
{
protected:
    int xPostion;
    int yPosition;

public:
    int x() const
    {
        return xPostion;
    }

    int y() const
    {
        return yPosition;
    }

    void init() override
    {
        this->xPostion = 0;
        this->yPosition = 0;
    }

    void update() override
    {
        this->xPostion++;
        this->yPosition++;
    }

    void setPosition(int x, int y)
    {
        this->xPostion = x;
        this->yPosition = y;
    }
};

#endif