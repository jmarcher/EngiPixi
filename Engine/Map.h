#ifndef MAP_H
#define MAP_H

#include <string>

class Map
{
private:
	std::string textureId;
	unsigned int mapScale;
	unsigned int tileSize;
	unsigned int scaledSize;
	unsigned int actualMapSizeX;
	unsigned int actualMapSizeY;

public:
    Map(const std::string& id, unsigned int mapScale, unsigned int tileSize);
    ~Map();

    void load(const std::string& path, int sizeX, int sizeY);

	void addTile(int sourceX, int sourceU, int xPosition, int yPosition);

	unsigned int getWidth() const;
	unsigned int getHeight() const;
};

#endif // MAP_H
