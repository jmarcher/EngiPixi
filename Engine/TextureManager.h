#ifndef TEXUREMANAGER_H
#define TEXUREMANAGER_H

#include "Engine.h"

class TextureManager
{
public:
    TextureManager();
    ~TextureManager();
    
    static SDL_Texture* load(const std::string& fileName);
    static void draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination);
};

#endif // TEXUREMANAGER_H
