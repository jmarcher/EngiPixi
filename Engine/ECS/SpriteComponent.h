#ifndef ENGIPIXI_SPRITECOMPONENT_H
#define ENGIPIXI_SPRITECOMPONENT_H

#include "SDL2/SDL.h"
#include <string>
#include "Components.h"

class TransformComponent;

class SpriteComponent : public Component
{
protected:
    SDL_Texture* texture;
    SDL_Rect sourceRect, destinationRect;
    TransformComponent* transformation;

public:
    SpriteComponent() = default;

    SpriteComponent(const std::string& path);

    ~SpriteComponent();

    void setTexture(const std::string& path);

    void init() override;

    void update() override;

    void draw() override;
};

#endif // ENGIPIXI_SPRITECOMPONENT_H
