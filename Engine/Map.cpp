#include "Engine.h"
#include "Map.h"
#include <fstream>

Map::Map()
{
}

Map::~Map()
{
}

void Map::load(const std::string& path, int sizeX, int sizeY)
{
    char c;
    std::fstream mapFile;
    mapFile.open(path);

    int sourceX, sourceY;

    for(int y = 0; y < sizeY; y++) {
        for(int x = 0; x < sizeX; x++) {
            // The first character gets interpreted as
            mapFile.get(c);
            sourceY = atoi(&c) * 32;

            mapFile.get(c);
            sourceX = atoi(&c) * 32;

            Engine::addTile(sourceX, sourceY, x * 64, y * 64);
            mapFile.ignore();
        }
    }

    mapFile.close();
}
