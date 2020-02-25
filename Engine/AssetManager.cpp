#include "AssetManager.h"
#include "ECS/Components.h"
#include "Engine.h"

extern Manager manager;

AssetManager::~AssetManager() {
    std::map<const char *, TTF_Font *>::iterator iterator = this->fonts.begin();
    while (iterator != this->fonts.end()) {
        TTF_CloseFont(iterator->second);
    }
}

void AssetManager::addTexture(const char *id, const std::string &path) {
    textures.emplace(id, TextureManager::load(path));
    ASSERT_MSG(this->textures[id] != nullptr, "Null pointer");
}

SDL_Texture *AssetManager::getTexture(const char *id) {
    // ASSERT_MSG(this->textures[id] != nullptr, "Null pointer");
//    if(this->textures.at(id) == nullptr){
//        std::cerr << id << std::endl;
//    }
    try{
        return this->textures.at(id);
    }catch(std::out_of_range e){
        std::cerr << "error here: " << id << " . "<< __LINE__ << std::endl;
    }
}

void AssetManager::createProjectile(Vector2D position, Vector2D velocity, int range, int speed, const char *textureId) {
    auto &projectile(manager.addEntity());

    projectile.addComponent<TransformComponent>(position.x, position.y, 32, 32, 1);
    projectile.addComponent<SpriteComponent>(textureId, false);
    projectile.addComponent<ProjectileComponent>(range, speed, velocity);
    projectile.addComponent<ColliderComponent>("projectile");
    projectile.addGroup(Engine::groupProjectiles);
}

void AssetManager::addFont(const char *id, const std::string &fontName, unsigned int size) {
    this->fonts.emplace(id, TTF_OpenFont(fontName.c_str(), size));
}

TTF_Font *AssetManager::getFont(const char *id) {
    return this->fonts[id];
}

AssetManager::AssetManager() {

}
