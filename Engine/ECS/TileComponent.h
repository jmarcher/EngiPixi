#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#if defined(__linux__) || defined(__APPLE__)
    #include "SDL2/SDL.h"
#elif _WIN32
    #include "SDL.h"
#endif

#include <memory>
#include "../Math/Vector2D.h"
#include "EntityComponentSystem.h"

class SpriteComponent;

class TileComponent : public Component {
protected:
    SDL_Texture *texture;

public:
    SDL_Rect sourceRect{};
    SDL_Rect destinationRect{};
    Vector2D position;

    TileComponent() = default;

    ~TileComponent();

    TileComponent(int sourceX,
                  int sourceY,
                  int xPosition,
                  int yPosition,
                  int tileSize,
                  int tileScale,
                  const char *id);

    TileComponent(const char *textureId, SDL_Rect sR, SDL_Rect dR, Vector2D p);

    void draw() override;

    void update() override;
};

#endif // TILECOMPONENT_H
