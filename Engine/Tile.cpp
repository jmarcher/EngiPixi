#include "Tile.h"

Tile::Tile()
{
    fillTile(black);
}

Tile::~Tile()
{
}

void Tile::fillTile(Pixel p){
    for(auto i = 0; i < TILE_SIZE ; ++i){
        for(auto j = 0; j < TILE_SIZE; ++j){
            _pixels[i][j] = p;
        }
    }
}

void Tile::fillTile(int r, int g, int b){
    for(auto i = 0; i < TILE_SIZE ; ++i){
        for(auto j = 0; j < TILE_SIZE; ++j){
            _pixels[i][j] = Pixel(r,g,b);
        }
    }
}

void Tile::draw(){
    
}

