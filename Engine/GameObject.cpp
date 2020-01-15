#include "GameObject.h"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
    this->xPosition = x;
    this->yPosition = y;
    this->objectTexture = TextureManager::LoadTexture(textureSheet);
}

GameObject::~GameObject()
{
}

void GameObject::update()
{
    this->yPosition++;
    this->xPosition++;

    this->sourceRect.w = PLAYER_SIZE;
    this->sourceRect.h = PLAYER_SIZE;

    this->sourceRect.x = 0;
    this->sourceRect.y = 0;

    this->destinationRect.x = this->xPosition;
    this->destinationRect.y = this->yPosition;

    this->destinationRect.w = sourceRect.w * 2;
    this->destinationRect.h = sourceRect.h * 2;
}

void GameObject::render()
{
    SDL_RenderCopy(Engine::renderer, objectTexture, &sourceRect, &destinationRect);
}
