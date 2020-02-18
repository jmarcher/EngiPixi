#include "ECS/Components.h"
#include "ECS/EntityComponentSystem.h"
#include "Engine.h"
#include "Map.h"
#include <fstream>

extern Manager manager;

Map::Map(const char* id, unsigned int mapScale, unsigned int tileSize)
{
    this->textureId = id;
    this->mapScale = mapScale;
    this->tileSize = tileSize;
    this->scaledSize = mapScale * tileSize;

    this->actualMapSizeX = 0;
    this->actualMapSizeY = 0;
}

Map::~Map()
{
}

void Map::load(const std::string& path, int sizeX, int sizeY)
{
    char c;
    std::fstream mapFile;
    mapFile.open(path);

    // Initialize actual map members
    this->actualMapSizeX = sizeX;
    this->actualMapSizeY = sizeY;

    int sourceX, sourceY;

    for(int y = 0; y < sizeY; y++) {
        for(int x = 0; x < sizeX; x++) {
            // The first character gets interpreted as
            mapFile.get(c);
            sourceY = atoi(&c) * this->tileSize;

            mapFile.get(c);
            sourceX = atoi(&c) * this->tileSize;

            this->addTile(sourceX, sourceY, x * this->scaledSize, y * this->scaledSize);
            mapFile.ignore();
        }
    }

    // We separate the Map data from the colliders with an empty line,
    // that is why we need to ignore the next line in order to get to the
    // start of the colliders.
    mapFile.ignore();

    for(int y = 0; y < sizeY; y++) {
        for(int x = 0; x < sizeX; x++) {
            mapFile.get(c);
            if(c == COLLIDE) {
                auto& collider(manager.addEntity());
                Offset spriteOffset = { -16, -16 };
                collider.addComponent<ColliderComponent>(
                    "terrain", x * this->scaledSize, y * this->scaledSize, this->scaledSize, spriteOffset);
                collider.addComponent<TransformComponent>(1.0f);
                collider.getComponent<TransformComponent>().speed = 1.0f;
                collider.addGroup(Engine::groupColliders);
            }
            mapFile.ignore();
        }
    }

    mapFile.close();
}

void Map::addTile(int sourceX, int sourceY, int xPosition, int yPosition)
{
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(
        sourceX, sourceY, xPosition, yPosition, this->tileSize, this->mapScale, this->textureId);
    tile.addGroup(Engine::groupMap);
}

unsigned int Map::getWidth() const
{
    return this->actualMapSizeX * this->scaledSize;
}
unsigned int Map::getHeight() const
{
    return this->actualMapSizeY * this->scaledSize;
}
