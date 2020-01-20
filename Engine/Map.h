#ifndef MAP_H
#define MAP_H
#define MAP_ROWS 20
#define MAP_COLUMNS 20


#define TILE_SIDE_SIZE 32

class Map
{
public:
    Map();
    ~Map();

    static void load(std::string path, int sizeX, int sizeY);

};

#endif // MAP_H
