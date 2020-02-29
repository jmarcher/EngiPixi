#ifndef JOYSTICKCONTROLLER_H
#define JOYSTICKCONTROLLER_H

#if defined(__linux__) || defined(__APPLE__)
    #include "SDL2/SDL.h"
#elif _WIN32
    #include "SDL.h"
#endif

#include "../Engine.h"
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
