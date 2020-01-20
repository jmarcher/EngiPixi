#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include "Components.h"
#include "EntityComponentSystem.h"
#include "SDL2/SDL.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"


#define WATER 1
#define GRASS 0
#define DIRT 2
// Nice
#define TREE 3

#define TILE_SIZE 32

class SpriteComponent;

class TileComponent:public Component
{
public:
    TransformComponent* transform;
    SpriteComponent* sprite;
    SDL_Rect tileRect;
    
    std::string path;
    
    unsigned int tileId;

    TileComponent() = default;
    ~TileComponent();
    
    TileComponent(int x, int y, int w, int h, int id);
    
    void init() override;
};

#endif // TILECOMPONENT_H
