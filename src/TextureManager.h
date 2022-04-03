#ifndef _TextureManager_h_
#define _TextureManager_h_

#include <memory>
#include <string>
#include <unordered_map>
#include <SDL.h>
#include <SDL_image.h>

class TextureManager
{
public:
    TextureManager();
    ~TextureManager();

    SDL_Texture* getTextureFromImg(std::string imgName, SDL_Renderer *renderer);

    TextureManager(const TextureManager& other) = delete;
    void operator=(TextureManager const& other) = delete;

private:
    SDL_Texture* findTexture(std::string name);

    std::unordered_map<std::string, SDL_Texture*> m_textures;
};

#endif //_TextureManager_h_
