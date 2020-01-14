#ifndef MAP_H
#define MAP_H

#define WATER 0
#define GRASS 1
#define DIRT 2

#define TILE_SIDE_SIZE 32

#include "Engine.h"

class Map
{
public:
    Map();
    ~Map();

    void load(int toLoad[20][25]);
    void draw();

protected:
    SDL_Rect source, destination;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;
    
    int map[20][25];
};

#endif // MAP_H
