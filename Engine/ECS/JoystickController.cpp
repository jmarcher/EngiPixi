#include "JoystickController.h"

JoystickController::JoystickController()
{
}

JoystickController::~JoystickController()
{
}
void JoystickController::update()
{
    switch(Engine::event.type) {
    case SDL_JOYAXISMOTION: {
        printf("Motion Joystick 0\n");
        if((Engine::event.jaxis.value < -3200) || (Engine::event.jaxis.value > 3200)) {
            if(Engine::event.jaxis.axis == 0) {
                /* Left-right movement code goes here */
                if((Engine::event.jaxis.value > 3200)) {
                    this->transform->velocity.x = 1;
                } else {
                    this->transform->velocity.x = -1;
                }
            }

            if(Engine::event.jaxis.axis == 1) {
                /* Up-Down movement code goes here */
            }
        }else{
            this->transform->velocity.zero();
        }
        break;
    }
    }
}
void JoystickController::init()
{
    this->transform = &entity->getComponent<TransformComponent>();
    if(SDL_NumJoysticks() > 0) {
        this->joystick = SDL_JoystickOpen(0);
        if(this->joystick) {
            printf("Opened Joystick 0\n");
        }
    }
}
