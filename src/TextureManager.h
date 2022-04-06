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

    void setRenderer(SDL_Renderer* p_renderer);

    SDL_Texture* getTextureFromImg(std::string imgName);

    TextureManager(const TextureManager& other) = delete;
    void operator=(TextureManager const& other) = delete;

private:
    SDL_Texture* findTexture(std::string name);

    SDL_Renderer* m_renderer;
    std::unordered_map<std::string, SDL_Texture*> m_textures;
};

#endif //_TextureManager_h_
