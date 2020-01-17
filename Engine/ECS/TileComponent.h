#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include "EntityComponentSystem.h"
#include "SDL2/SDL.h"
#include "Components.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"

class SpriteComponent;

class TileComponent:public Component
{
public:
    TransformComponent* transform;
    SpriteComponent* sprite;
    SDL_Rect tileRect;
    unsigned int tileId;
    
    std::string path;

    TileComponent() = default;
    ~TileComponent();
    
    TileComponent(int x, int y, int w, int h, int id);
    
    void init() override;
};

#endif // TILECOMPONENT_H
