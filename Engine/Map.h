#ifndef MAP_H
#define MAP_H
#define MAP_ROWS 20
#define MAP_COLUMNS 20
#define WATER 1
#define GRASS 0
#define DIRT 2
// Nice
#define TREE 3

#define TILE_SIDE_SIZE 32

class Map
{
public:
    Map();
    ~Map();

    static void load(std::string path, int sizeX, int sizeY);

protected:
};

#endif // MAP_H
