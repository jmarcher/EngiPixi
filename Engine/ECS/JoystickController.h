#ifndef JOYSTICKCONTROLLER_H
#define JOYSTICKCONTROLLER_H

#include "../Engine.h"
#include "SDL2/SDL.h"
#include "Components.h"
#include "EntityComponentSystem.h"

class JoystickController:public Component
{
protected:
    SDL_Joystick * joystick;
    TransformComponent* transform;
public:
    JoystickController();
    ~JoystickController();
    
    void init() override;
    
    void update() override;

};

#endif // JOYSTICKCONTROLLER_H
