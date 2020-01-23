#include "TileComponent.h"
#include "../TextureManager.h"

TileComponent::~TileComponent()
{
    SDL_DestroyTexture(this->texture);
}

TileComponent::TileComponent(int sourceX, int sourceY, int xPosition, int yPosition, const std::string& path)
{
    this->texture = TextureManager::load(path);

    this->sourceRect.x = sourceX;
    this->sourceRect.y = sourceY;

    this->sourceRect.h = this->sourceRect.w = 32;

    this->destinationRect.x = xPosition;
    this->destinationRect.y = yPosition;

    this->destinationRect.h = this->destinationRect.w = 64;
}
void TileComponent::draw()
{
    TextureManager::draw(this->texture, this->sourceRect, this->destinationRect, SDL_FLIP_NONE);
}
