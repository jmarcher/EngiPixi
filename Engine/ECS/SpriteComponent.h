//
// Created by gordo on 15.01.20.
//

#ifndef ENGIPIXI_SPRITECOMPONENT_H
#define ENGIPIXI_SPRITECOMPONENT_H

#include <string>
#include "Components.h"
#include "SDL2/SDL.h"

class SpriteComponent : public Component
{
protected:
    TransformComponent* transformation;
    SDL_Texture* texture;
    SDL_Rect sourceRect, destinationRect;

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
