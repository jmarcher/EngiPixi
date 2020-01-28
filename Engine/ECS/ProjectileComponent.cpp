#include "ProjectileComponent.h"
void ProjectileComponent::update()
{
    this->distance += this->speed;
    if(this->distance > this->range) {
        entity->destroy();
    } else if(transform->position.x > Engine::camera.x + Engine::camera.w || transform->position.x < Engine::camera.x ||
        transform->position.y > Engine::camera.y + Engine::camera.h || transform->position.y < Engine::camera.y) {
        entity->destroy();
    }
}
void ProjectileComponent::init()
{
    transform = &entity->getComponent<TransformComponent>();
    transform->velocity = this->velocity;
}
ProjectileComponent::ProjectileComponent(int rng, int spd, Vector2D vel)
    : range(rng)
    , speed(spd)
    , velocity(vel)
{
}
ProjectileComponent::~ProjectileComponent()
{
}
