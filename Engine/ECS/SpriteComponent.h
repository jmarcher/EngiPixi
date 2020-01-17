//
// Created by gordo on 15.01.20.
//

#ifndef ENGIPIXI_SPRITECOMPONENT_H
#define ENGIPIXI_SPRITECOMPONENT_H

#include "Components.h"
#include "SDL2/SDL.h"

class SpriteComponent : public Component {
protected:
    TransformComponent *transformation;
    SDL_Texture *texture;
    SDL_Rect sourceRect, destinationRect;
public:
    SpriteComponent() = default;

    SpriteComponent(const char *path) {
        this->setTexture(path);
    }

    ~SpriteComponent() {
        SDL_DestroyTexture(this->texture);
    }

    void setTexture(const char *path) {
        this->texture = TextureManager::LoadTexture(path);
    }

    void init() override {
        this->transformation = &entity->getComponent<TransformComponent>();
        this->sourceRect.x = this->sourceRect.y = 0;
        this->sourceRect.w = this->transformation->width;
        this->sourceRect.h = this->transformation->height;
        this->destinationRect.h = this->transformation->height * this->transformation->scale;
        this->destinationRect.w = this->transformation->width * this->transformation->scale;
    }

    void update() override {
        this->destinationRect.x = static_cast<int>(this->transformation->x());
        this->destinationRect.y = static_cast<int>(this->transformation->y());
    }

    void draw() override {
        TextureManager::draw(this->texture, this->sourceRect, this->destinationRect);
    }
};

#endif //ENGIPIXI_SPRITECOMPONENT_H
