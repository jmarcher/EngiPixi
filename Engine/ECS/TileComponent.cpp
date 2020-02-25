#include "../TextureManager.h"
#include "TileComponent.h"
#include "../Helpers/Logger.h"

TileComponent::~TileComponent() {
    SDL_DestroyTexture(this->texture);
}

TileComponent::TileComponent(int sourceX,
                             int sourceY,
                             int xPosition,
                             int yPosition,
                             int tileSize,
                             int tileScale,
                             const char *id) {
    this->texture = Engine::assets->getTexture(id);

    this->position.x = xPosition;
    this->position.y = yPosition;

    this->sourceRect.x = sourceX;
    this->sourceRect.y = sourceY;

    this->sourceRect.h = this->sourceRect.w = tileSize;

    this->destinationRect.x = xPosition;
    this->destinationRect.y = yPosition;

    this->destinationRect.h = this->destinationRect.w = tileSize * tileScale;
}

void TileComponent::draw() {
//    LOG("Draw this here" << position << Vector2D(destinationRect.w,destinationRect.h));

    TextureManager::draw(this->texture, this->sourceRect, this->destinationRect, SDL_FLIP_NONE);
}

void TileComponent::update() {
    destinationRect.x = static_cast<int>(position.x) - Engine::camera.x;
    destinationRect.y = static_cast<int>(position.y) - Engine::camera.y;
}

TileComponent::TileComponent(const char *textureId, SDL_Rect sR, SDL_Rect dR, Vector2D p) {
    texture = Engine::assets->getTexture(textureId);
    sourceRect = sR;
    destinationRect = dR;
    position = p;
}
