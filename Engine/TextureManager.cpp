#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

SDL_Texture* TextureManager::load(const std::string& fileName)
{
    SDL_Texture* result;
    SDL_Surface* temporalSurface = IMG_Load(fileName.c_str());
    result = SDL_CreateTextureFromSurface(Engine::renderer, temporalSurface);
    SDL_FreeSurface(temporalSurface);
    
    return result;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination)
{
    SDL_RenderCopy(Engine::renderer, texture, &source, &destination);
}
