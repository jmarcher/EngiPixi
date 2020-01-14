#ifndef TEXUREMANAGER_H
#define TEXUREMANAGER_H

#include "Engine.h"

class TexureManager
{
public:
    TexureManager();
    ~TexureManager();
    
    static SDL_Texture* LoadTexture(const char * fileName);

};

#endif // TEXUREMANAGER_H
