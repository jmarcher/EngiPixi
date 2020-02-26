#ifndef MAP_H
#define MAP_H

#include <string>
#include "Math/Vector2D.h"

enum ColliderType {
    CT_FULL = 25,
    CT_BOTTOM_RIGHT = 26,
    CT_FULL_BOTTOM = 27,
    CT_LEFT_BOTTOM = 28,
    CT_FULL_LEFT = 29,
    CT_TOP_LEFT = 30,
    CT_FULL_TOP = 31,
    CT_TOP_RIGHT = 32,
    CT_FULL_RIGHT = 33
};

enum TerrainObject{
    TO_TREE = 34,
    TO_BIG_ROCK = 35
};

class Map {
private:
    const char *textureId;
    unsigned int mapScale;
    unsigned int tileSize;
    unsigned int scaledSize;
    unsigned int actualMapSizeX;
    unsigned int actualMapSizeY;

    const char COLLIDE = '1';

public:
    Map(const char *id, unsigned int mapScale, unsigned int tileSize);

    ~Map();

    void load(const std::string &path, int sizeX, int sizeY);

    void addTile(int sourceX, int sourceY, int xPosition, int yPosition);
    static Entity& addTerrainObject(const char* texture, SDL_Rect source, SDL_Rect destination, Vector2D position);

    unsigned int getWidth() const;

    unsigned int getHeight() const;
};

#endif // MAP_H
