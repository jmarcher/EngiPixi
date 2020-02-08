#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include "../Engine.h"
#include "SDL2/SDL.h"

class KeyboardHandler
{
public:
    KeyboardHandler();
    ~KeyboardHandler();
    static bool isPressed(SDL_Keycode key)
    {
        return (Engine::event.type == SDL_KEYDOWN) && (Engine::event.key.keysym.sym == key);
    }
    static bool isReleased(SDL_Keycode key)
    {
        return (Engine::event.type == SDL_KEYUP) && (Engine::event.key.keysym.sym == key);
    }
};

#endif // KEYBOARDHANDLER_H
