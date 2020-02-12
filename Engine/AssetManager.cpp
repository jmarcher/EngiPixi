#include "AssetManager.h"
#include "ECS/Components.h"

AssetManager::AssetManager(Manager* m)
    : manager(m)
{
}

AssetManager::~AssetManager()
{
    std::map<const char*, TTF_Font*>::iterator iterator = this->fonts.begin();
    while (iterator != this->fonts.end()) {
        TTF_CloseFont(iterator->second);
    }
}

void AssetManager::addTexture(const char* id, const std::string& path)
{
    textures.emplace(id, TextureManager::load(path));
}

SDL_Texture* AssetManager::getTexture(const char* id)
{
    return this->textures[id];
}
void AssetManager::createProjectile(Vector2D position, Vector2D velocity, int range, int speed, const char* textureId)
{
    auto& projectile(manager->addEntity());

    projectile.addComponent<TransformComponent>(position.x, position.y, 32, 32, 1);
    projectile.addComponent<SpriteComponent>(textureId, false);
    projectile.addComponent<ProjectileComponent>(range, speed, velocity);
    projectile.addComponent<ColliderComponent>("projectile");
    projectile.addGroup(Engine::groupProjectiles);
}

void AssetManager::addFont(const char* id, const std::string& fontName, unsigned int size)
{
    this->fonts.emplace(id, TTF_OpenFont(fontName.c_str(), size));
}

TTF_Font* AssetManager::getFont(const char* id)
{
    return this->fonts[id];
}
