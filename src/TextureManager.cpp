#include "TextureManager.h"

TextureManager::TextureManager() : m_renderer(nullptr)
{}

TextureManager::~TextureManager()
{}

void TextureManager::setRenderer(SDL_Renderer* p_renderer)
{
    m_renderer = p_renderer;
}

SDL_Texture* TextureManager::getTextureFromImg(std::string imgName)
{
    SDL_Texture* texture = findTexture(imgName);
    if(!texture)
    {
        std::string path = imgName;
        SDL_Surface* surface = IMG_Load(path.c_str());
        if (!surface)
        {
            path = "gfx/" + path;
            surface = IMG_Load(path.c_str());
            if (!surface)
            {
                path = "../" + path;
                surface = IMG_Load(path.c_str());
                if (!surface)
                {
                    path = "../" + path;
                    surface = IMG_Load(path.c_str());
                    if (!surface)
                    {
                        path = "../" + path;
                        surface = IMG_Load(path.c_str());
                        if (!surface)
                        {
                            SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
                            return nullptr;
                        }
                    }
                }
            }
        }

        texture = SDL_CreateTextureFromSurface(m_renderer, surface);
        SDL_FreeSurface(surface);

        m_textures[imgName] = texture;
    }
    return texture;
}

SDL_Texture* TextureManager::findTexture(std::string name)
{
    for (auto const& [key, val] : m_textures)
    {
        if(key == name)
        {
            return val;
        }
    }
    return nullptr;
}