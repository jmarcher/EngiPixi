#include "TileComponent.h"

TileComponent::~TileComponent()
{
}

TileComponent::TileComponent(int x, int y, int w, int h, int id)
{
    this->tileId = id;
    this->tileRect.x = x;
    this->tileRect.y = y;
    this->tileRect.w = w;
    this->tileRect.h = h;

    switch(id) {
    case WATER:
        this->path = "../assets/sprites/water.png";
        break;
    case DIRT:
        this->path = "../assets/sprites/dirt.png";
        break;
    case GRASS:
        this->path = "../assets/sprites/grass.png";
        break;
    }
}
void TileComponent::init()
{
    entity->addComponent<TransformComponent>(this->tileRect.x, this->tileRect.y, this->tileRect.w, this->tileRect.h, 1);
    transform = &entity->getComponent<TransformComponent>();

    entity->addComponent<SpriteComponent>(this->path);
    sprite = &entity->getComponent<SpriteComponent>();
}
