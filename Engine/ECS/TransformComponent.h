#ifndef ENGIPIXI_TRANSFORMCOMPONENT_H
#define ENGIPIXI_TRANSFORMCOMPONENT_H

#include "PositionComponent.h"

#include "../Math/Vector2D.h"
#include "../Helpers/Debug/Assert.h"
const float TRANSFORM_BASE_SPEED = 1.5f;
class PositionComponent;
class TransformComponent : public PositionComponent {

public:
//    Vector2D position;
    Vector2D velocity;

    unsigned short width = 32;
    unsigned short height = 32;
    int scale = 1;
    float speed = TRANSFORM_BASE_SPEED;

    TransformComponent();

    explicit TransformComponent(int scale);

    TransformComponent(float x, float y, int scale);
    
    TransformComponent(int w, int h, int scale);
    
    TransformComponent(float x, float y);
    
    TransformComponent(float speed);

    TransformComponent(float x, float y, int w, int h, int scale);

    void init() override;

    void update() override;

    void setPosition(float x, float y);
    
    void setSpeed(float s){
        speed = s;
    }
    
    void bounce(const Vector2D& oldPosition);
    
};

#endif //ENGIPIXI_TRANSFORMCOMPONENT_H
