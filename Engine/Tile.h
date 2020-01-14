#ifndef TILE_H
#define TILE_H
#include <tuple>
#define TILE_SIZE 1
typedef std::tuple<int,int,int> Pixel;
const Pixel black(0,0,0);
class Tile
{
public:
    Tile();
    ~Tile();
    void draw();
    int xPosition() const;
    int yPosition() const;
protected:
    void fillTile(int,int,int);
    void fillTile(Pixel);
    Pixel _pixels[TILE_SIZE][TILE_SIZE];
    int _x,_y;
};

#endif // TILE_H
