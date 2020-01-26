#include "Engine.h"
#include "Map.h"
#include <fstream>
#include "ECS/EntityComponentSystem.h"
#include "ECS/Components.h"


extern Manager manager;

Map::Map(std::string mapFilePath, unsigned int mapScale, unsigned int tileSize)
{
	this->mapFilePath = mapFilePath;
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

	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
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

	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapFile.get(c);
			if (c == '1') {
				auto& collider(manager.addEntity());
				collider.addComponent<ColliderComponent>("terrain", x * this->scaledSize, y*this->scaledSize, this->scaledSize);
				collider.addGroup(Engine::groupColliders);
			}
			mapFile.ignore();
		}
	}

	mapFile.close();
}

unsigned int Map::getWidth() const
{
	return this->actualMapSizeX * this->scaledSize;
}
unsigned int Map::getHeight() const
{
	return this->actualMapSizeY * this->scaledSize;
}

void Map::addTile(int sourceX, int sourceY, int xPosition, int yPosition) {
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(sourceX, sourceY, xPosition, yPosition, this->tileSize, this->mapScale, this->mapFilePath);
	tile.addGroup(Engine::groupMap);
}