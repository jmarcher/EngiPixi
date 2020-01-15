//
// Created by gordo on 15.01.20.
//

#ifndef ENGIPIXI_SPRITECOMPONENT_H
#define ENGIPIXI_SPRITECOMPONENT_H

#include "Components.h"
#include "SDL2/SDL.h"

class SpriteComponent : public Component {
public:
    SpriteComponent() = default;

    SpriteComponent(const char *path) {
        this->setTexture(path);
    }

    void setTexture(const char *path) {
        this->texture = TextureManager::LoadTexture(path);
    }

    void init() override {
        this->position = &entity->getComponent<PositionComponent>();
        this->sourceRect.x = this->sourceRect.y = 0;
        this->sourceRect.h = this->sourceRect.w = 32;
        this->destinationRect.h = this->destinationRect.w = this->sourceRect.h * 2;
    }

    void update() override {
        this->destinationRect.x = this->position->x();
        this->destinationRect.y = this->position->y();
    }

    void draw() override {
        TextureManager::draw(this->texture, this->sourceRect, this->destinationRect);
    }

protected:
    PositionComponent *position;
    SDL_Texture *texture;
    SDL_Rect sourceRect, destinationRect;
};

#endif //ENGIPIXI_SPRITECOMPONENT_H
