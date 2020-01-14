#include "Tile.h"

Tile::Tile()
{
    this->_x = 0;
    this->_y = 0;
    fillTile(black);
}

Tile::~Tile()
{
}


void Tile::fillTile(Pixel p){
    for(auto & _pixel : _pixels){
        for(auto & j : _pixel){
            j = p;
        }
    }
}

void Tile::fillTile(int r, int g, int b){
    for(auto & _pixel : _pixels){
        for(auto & j : _pixel){
            j = Pixel(r,g,b);
        }
    }
}

void Tile::draw(){
    
}

int Tile::xPosition() const {
    return this->_x;
}

int Tile::yPosition() const {
    return this->_y;
}

