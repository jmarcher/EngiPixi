//
// Created by gordo on 24.02.20.
//

#ifndef ENGIPIXI_POSITIONCOMPONENT_H
#define ENGIPIXI_POSITIONCOMPONENT_H

#include "EntityComponentSystem.h"
//#include "Components.h"
#include "../Math/Vector2D.h"


class PositionComponent:public Component{
public:
    Vector2D position;
    PositionComponent(){position={0,0};}
    PositionComponent(int x, int y);
    PositionComponent(Vector2D p):position(p){}

    const Vector2D& getPosition() const{
        return position;
    }

    bool isBeforePlayer(const Vector2D& p) const{
        return position.y < p.y;
    }

    bool isAfterPlayer(const Vector2D& p) const{
        return position.y > p.y;
    }

    [[nodiscard]] float x() const;

    [[nodiscard]] float y() const;

    void init() override;

    void update() override;

    void draw() override;

    ~PositionComponent() {

    }
};


#endif //ENGIPIXI_POSITIONCOMPONENT_H
