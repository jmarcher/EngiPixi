#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <string>
#include <map>

#include "Map.h"
#include "Math/Vector2D.h"
#include "TextureManager.h"
#include "ECS/EntityComponentSystem.h"

class AssetManager
{
protected:
    std::map<std::string, SDL_Texture*> textures;
    Manager * manager;
public:
    AssetManager(Manager* manager);
    ~AssetManager();

    // Texture managment
    void addTexture(const std::string& id, const std::string& path);
    SDL_Texture* getTexture(const std::string& id);
    
    // Game objects
    void createProjectile(Vector2D position, Vector2D velocity, int range, int speed, const std::string & textureId);
};

#endif // ASSETMANAGER_H