#include "SpriteComponent.h"
#include <cstring>
SpriteComponent::SpriteComponent(const std::string& id)
{
    this->setTexture(id);
}

SpriteComponent::SpriteComponent(const std::string& id, bool isAnimated)
{
    this->animated = isAnimated;

    Animation idle = Animation(0, 1, 100);
    Animation walkSouth = Animation(0, 1, 100);
    Animation walkSouthWestEast = Animation(1, 1, 100);
    Animation walkNorthWestEast = Animation(2, 1, 100);
    Animation walkNorth = Animation(3, 1, 100);
    Animation walkWestEast = Animation(4, 1, 100);
    //    Animation walk = Animation(1, 3, 100);
    //    Animation run = Animation(2, 7, 80);

    animations.emplace("idle", idle);
    animations.emplace("walkSouth", walkSouth);
    animations.emplace("walkNorth", walkNorth);
    animations.emplace("walkNorthWestEast", walkNorthWestEast);
    animations.emplace("walkSouthWestEast", walkSouthWestEast);
    animations.emplace("walkWestEast", walkWestEast);
    animations.emplace("run", idle);

    this->play("idle");

    this->setTexture(id);
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::setTexture(const std::string& id)
{
    this->texture = Engine::assets->getTexture(id);
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

    if(this->transformation->velocity.y == -1) {
        if(this->transformation->velocity.x == 1) {
            this->play("walkNorthWestEast");
            this->setHorizontalFlip();
        } else if(this->transformation->velocity.x == -1) {
            this->play("walkNorthWestEast");
        } else {
            this->play("walkNorth");
        }
    } else if(this->transformation->velocity.y == 1) {
        if(this->transformation->velocity.x == 1) {
            this->play("walkSouthWestEast");
        } else if(this->transformation->velocity.x == -1) {
            this->play("walkSouthWestEast", SDL_FLIP_HORIZONTAL);
        } else {
            this->play("walkSouth");
        }
    } else if(this->transformation->velocity.x == 1 && this->transformation->velocity.y == 0) {
        this->play("walkWestEast");
    } else if(this->transformation->velocity.x == -1 && this->transformation->velocity.y == 0) {
        this->setHorizontalFlip();
        this->play("walkWestEast", SDL_FLIP_HORIZONTAL);
        std::cout << "Moving left" << std::endl;
    }
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
    this->spriteFlip = SDL_FLIP_NONE;
    animationIndex = this->animations[animationName].aIndex;
    frames = this->animations[animationName].aFrames;
    animationSpeed = this->animations[animationName].aSpeed;
}

SDL_Rect SpriteComponent::getDestinationRect() const
{
    return this->destinationRect;
}

void SpriteComponent::play(const std::string& animationName, SDL_RendererFlip flip)
{
    this->play(animationName);
    this->spriteFlip = flip;
}
