#include "SpriteComponent.h"
#include <cstring>
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
    this->texture = TextureManager::load(path.c_str());
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
    if(this->animated) {
        this->sourceRect.x =
            this->sourceRect.w * static_cast<int>((SDL_GetTicks() / this->animationSpeed) % this->frames);
    }
    this->sourceRect.y = this->transformation->height * this->animationIndex;
    this->destinationRect.x = static_cast<int>(this->transformation->x()) - Engine::camera.x;
    this->destinationRect.y = static_cast<int>(this->transformation->y()) - Engine::camera.y;
}

void SpriteComponent::draw()
{
    TextureManager::draw(this->texture, this->sourceRect, this->destinationRect, spriteFlip);
}

void SpriteComponent::setNoFlip()
{
    this->spriteFlip = SDL_FLIP_NONE;
}

void SpriteComponent::setVerticalFlip()
{
    this->spriteFlip = SDL_FLIP_VERTICAL;
}

void SpriteComponent::setHorizontalFlip()
{
    this->spriteFlip = SDL_FLIP_HORIZONTAL;
}

void SpriteComponent::play(const std::string& animationName)
{
    animationIndex = this->animations[animationName].aIndex;
    frames = this->animations[animationName].aFrames;
    animationSpeed = this->animations[animationName].aSpeed;
}

SpriteComponent::SpriteComponent(const std::string& path, bool isAnimated)
{
    this->animated = isAnimated;

    Animation idle = Animation(0, 3, 100);
    Animation walk = Animation(1, 8, 100);

    animations.emplace("idle", idle);
    animations.emplace("walk", walk);

    this->play("idle");

    this->setTexture(path);
}
