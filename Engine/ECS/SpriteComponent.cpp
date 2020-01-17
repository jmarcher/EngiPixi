#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(const std::string& path)
{
    this->setTexture(path);
}

SpriteComponent::~SpriteComponent()
{
    SDL_DestroyTexture(this->texture);
}

void SpriteComponent::setTexture(const std::string& path)
{
    this->texture = TextureManager::LoadTexture(path.c_str());
}

void SpriteComponent::init()
{
    this->transformation = &entity->getComponent<TransformComponent>();
    this->sourceRect.x = this->sourceRect.y = 0;
    this->sourceRect.w = this->transformation->width;
    this->sourceRect.h = this->transformation->height;
    this->destinationRect.h = this->transformation->height * this->transformation->scale;
    this->destinationRect.w = this->transformation->width * this->transformation->scale;
}

void SpriteComponent::update()
{
    this->destinationRect.x = static_cast<int>(this->transformation->x());
    this->destinationRect.y = static_cast<int>(this->transformation->y());
}

void SpriteComponent::draw()
{
    TextureManager::draw(this->texture, this->sourceRect, this->destinationRect);
}