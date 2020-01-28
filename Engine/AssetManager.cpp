#include "AssetManager.h"
#include "ECS/Components.h"

AssetManager::AssetManager(Manager* m)
    : manager(m)
{
}

AssetManager::~AssetManager()
{
}

void AssetManager::addTexture(const std::string& id, const std::string& path)
{
    textures.emplace(id, TextureManager::load(path));
}

SDL_Texture* AssetManager::getTexture(const std::string& id)
{
    return this->textures[id];
}
void AssetManager::createProjectile(Vector2D position, Vector2D velocity, int range, int speed, const std::string& textureId)
{
    auto& projectile(manager->addEntity());

    projectile.addComponent<TransformComponent>(position.x, position.y, 32, 32, 1);
    projectile.addComponent<SpriteComponent>(textureId, false);
    projectile.addComponent<ProjectileComponent>(range, speed, velocity);
    projectile.addComponent<ColliderComponent>("projectile");
    projectile.addGroup(Engine::groupProjectiles);
}
