#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Engine.h"
#define PLAYER_SIZE 32

class GameObject
{
public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();

    void update();
    void render();
protected:
    int xPosition;
    int yPosition;
    
    SDL_Texture * objectTexture;
    SDL_Rect sourceRect, destinationRect;
};

#endif // GAMEOBJECT_H
