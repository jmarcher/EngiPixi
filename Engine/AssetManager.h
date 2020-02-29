#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#if defined(__linux__) || defined(__APPLE__)
    #include "SDL2/SDL_ttf.h"
#elif _WIN32
    #include "SDL_ttf.h"
#endif

#include <map>
#include <string>
#include <memory>

#include "ECS/EntityComponentSystem.h"
#include "Map.h"
#include "Math/Vector2D.h"
#include "TextureManager.h"

class AssetManager {
protected:
    std::map<std::string, SDL_Texture *> textures;
    std::map<std::string, TTF_Font *> fonts;

public:

    AssetManager();


    ~AssetManager();

    // Texture management
    void addTexture(const std::string &id, const std::string &path);

    SDL_Texture *getTexture(const std::string &id);

    // Game objects
    void createProjectile(Vector2D position, Vector2D velocity, int range, int speed, const std::string &textureId);

    // Fonts
    void addFont(const std::string &id, const std::string &fontName, unsigned int size);

    TTF_Font *getFont(const std::string &id);
};

#endif // ASSETMANAGER_H