#include "TexureManager.h"

TexureManager::TexureManager()
{
}

TexureManager::~TexureManager()
{
}

SDL_Texture* TexureManager::LoadTexture(const char* fileName)
{
    SDL_Texture* result;
    SDL_Surface* temporalSurface = IMG_Load(fileName);
    result = SDL_CreateTextureFromSurface(Engine::renderer, temporalSurface);
    SDL_FreeSurface(temporalSurface);
    
    return result;
}
