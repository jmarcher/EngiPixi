#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#ifdef __linux__
    #include "SDL2/SDL_ttf.h"
#elif _WIN32
    #include "SDL_ttf.h"
#endif
#include <map>
#include <string>

#include "ECS/EntityComponentSystem.h"
#include "Map.h"
#include "Math/Vector2D.h"
#include "TextureManager.h"

class AssetManager
{
protected:
    std::map<const char*, SDL_Texture*> textures;
    std::map<const char*, TTF_Font*> fonts;
    Manager* manager;

public:
    AssetManager(Manager* manager);
    ~AssetManager();

    // Texture managment
    void addTexture(const char* id, const std::string& path);
    SDL_Texture* getTexture(const char* id);

    // Game objects
    void createProjectile(Vector2D position, Vector2D velocity, int range, int speed, const char* textureId);

    // Fonts
    void addFont(const char* id, const std::string& fontName, unsigned int size);
    TTF_Font* getFont(const char* id);
};

#endif // ASSETMANAGER_H