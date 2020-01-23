#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include <string>
#include "SDL2/SDL.h"
#include "EntityComponentSystem.h"


class SpriteComponent;

class TileComponent:public Component
{
protected:
    SDL_Texture* texture;
public:
    SDL_Rect sourceRect;
    SDL_Rect destinationRect;

    TileComponent() = default;
    ~TileComponent();
    
    TileComponent(int sourceX, int sourceY, int xPosition, int yPosition, const std::string& path);
    
    void draw() override;


};

#endif // TILECOMPONENT_H
