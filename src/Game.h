#ifndef _Game_h_
#define _Game_h_

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "Entity.h"
#include "vec2.h"

class Game
{
public:
    Game();
    ~Game();

    bool init(std::string title, int xPos, int yPos, int width, int height, bool isFullscreen);
    bool isRunning();
    void handleEvents();
    void update();
    void render();
    void clean();

private:
    void initBasicEntites();

    bool m_isRunning;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    TextureManager m_textureMgr;
    std::vector<Entity> m_entities;
    vec2 m_windowSize;
};

#endif //_Game_h_
