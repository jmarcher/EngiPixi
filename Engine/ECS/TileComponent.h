#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#ifdef __linux__ 
#include "SDL2/SDL.h"
#elif _WIN32
#include "SDL.h"
#endif

#include "../Math/Vector2D.h"
#include "EntityComponentSystem.h"

class SpriteComponent;

class TileComponent : public Component
{
protected:
    SDL_Texture* texture;

public:
    SDL_Rect sourceRect;
    SDL_Rect destinationRect;
    Vector2D position;

    TileComponent() = default;
    ~TileComponent();

    TileComponent(int sourceX,
        int sourceY,
        int xPosition,
        int yPosition,
        int tileSize,
        int tileScale,
        const char* id);

    void draw() override;

    void update() override;
};

#endif // TILECOMPONENT_H
