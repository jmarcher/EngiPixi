#include "ECS/Components.h"
#include "ECS/EntityComponentSystem.h"
#include "Engine.h"
#include "Map.h"
#include <fstream>

extern Manager manager;

Map::Map(const char *id, unsigned int mapScale, unsigned int tileSize) {
    this->textureId = id;
    this->mapScale = mapScale;
    this->tileSize = tileSize;
    this->scaledSize = mapScale * tileSize;

    this->actualMapSizeX = 0;
    this->actualMapSizeY = 0;
}

Map::~Map() {
}

void Map::load(const std::string &path, int sizeX, int sizeY) {
    char c;
    std::fstream mapFile;
    mapFile.open(path);

    // Initialize actual map members
    this->actualMapSizeX = sizeX;
    this->actualMapSizeY = sizeY;

    int sourceX, sourceY;

    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            // The first character gets interpreted as
            mapFile.get(c);
            sourceY = atoi(&c) * this->tileSize;

            mapFile.get(c);
            sourceX = atoi(&c) * this->tileSize;

            addTile(sourceX, sourceY, x * this->scaledSize, y * this->scaledSize);
            mapFile.ignore();
        }
        std::cout << std::endl;
    }

    // We separate the Map data from the colliders with an empty line,
    // that is why we need to ignore the next line in order to get to the
    // start of the colliders.
    mapFile.ignore();

    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            mapFile.get(c);
            int collider = 0;
            collider += atoi(&c) * 10;
            mapFile.get(c);
            collider += atoi(&c);

            std::cout << collider << ',';
            switch (collider) {
                case CT_FULL: {
                    auto &item(manager.addEntity());
                    item.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
                    item.addGroup(Engine::groupColliders);
                }
                    break;

                case CT_BOTTOM_RIGHT: {
                    auto &item(manager.addEntity());
                    item.addComponent<ColliderComponent>("terrain", (x * scaledSize) + (scaledSize / 2),
                                                         y * scaledSize + (scaledSize / 2), scaledSize / 2);
                    item.addGroup(Engine::groupColliders);
                }
                    break;

                case CT_FULL_BOTTOM: {
                    auto &item(manager.addEntity());
                    item.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize + (scaledSize / 2),
                                                         scaledSize, scaledSize / 2);
                    item.addGroup(Engine::groupColliders);
                }
                    break;

                case CT_FULL_LEFT: {
                    auto &item(manager.addEntity());
                    item.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize / 2,
                                                         scaledSize);
                    item.addGroup(Engine::groupColliders);
                }
                    break;

                case CT_FULL_RIGHT: {
                    auto &item(manager.addEntity());
                    item.addComponent<ColliderComponent>("terrain", x * scaledSize + (scaledSize / 2), y * scaledSize,
                                                         scaledSize / 2, scaledSize);
                    item.addGroup(Engine::groupColliders);
                }
                    break;

                case CT_TOP_RIGHT: {
                    auto &c(manager.addEntity());
                    c.addComponent<ColliderComponent>("terrain", x * scaledSize + (scaledSize / 2), y * scaledSize,
                                                      scaledSize / 2);
                    c.addGroup(Engine::groupColliders);
                }
                    break;

                case CT_LEFT_BOTTOM: {
                    auto &item(manager.addEntity());
                    item.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize + (scaledSize / 2),
                                                         scaledSize / 2);
                    item.addGroup(Engine::groupColliders);
                }
                    break;

                case CT_TOP_LEFT: {
                    auto &item(manager.addEntity());
                    item.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize / 2);
                    item.addGroup(Engine::groupColliders);
                }
                    break;
                case CT_FULL_TOP: {
                    auto &item(manager.addEntity());
                    item.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize,
                                                         scaledSize / 2);
                    item.addGroup(Engine::groupColliders);
                }
                    break;
                default:
                    break;
            }

            mapFile.ignore();
        }
        std::cout << std::endl;
    }

    mapFile.close();
}

void Map::addTile(int sourceX, int sourceY, int xPosition, int yPosition) {
    auto &tile(manager.addEntity());
    tile.addComponent<TileComponent>(
            sourceX, sourceY, xPosition, yPosition, tileSize, mapScale, textureId);
    tile.addGroup(Engine::groupMap);
}

unsigned int Map::getWidth() const {
    return this->actualMapSizeX * this->scaledSize;
}

unsigned int Map::getHeight() const {
    return this->actualMapSizeY * this->scaledSize;
}
