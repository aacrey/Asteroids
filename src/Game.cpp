#include "Game.h"

Game::Game(): m_isRunning(false), m_window(nullptr), m_renderer(nullptr)
{}

Game::~Game()
{}

bool Game::init(std::string title, int xPos, int yPos, int width, int height, bool isFullscreen)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_Log("SDL Initialization Failed: %1", SDL_GetError());
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    int res = IMG_Init(imgFlags);
    if((res & imgFlags) != imgFlags)
    {
        SDL_Log("SDL_image Initialization Failed: %1", SDL_GetError());
        return false;
    }

    int windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    if(isFullscreen)
    {
        windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN;
    }
    m_window = SDL_CreateWindow(title.c_str(), xPos, yPos, width, height, windowFlags);
    if(m_window == nullptr)
    {
        SDL_Log("Window Creation Failed: %1", SDL_GetError());
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    if(m_window == nullptr)
    {
        SDL_Log("Renderer Creation Failed: %1", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

    SDL_GetWindowSize(m_window, &m_windowSize.x, &m_windowSize.y);
    m_entityMgr.initBasicEntites(m_renderer, m_textureMgr, m_windowSize);

    m_isRunning = true;
    return true; 
}

bool Game::isRunning()
{
    return m_isRunning;
}

void Game::handleEvents()
{
    m_inputMgr.handleInputs(m_isRunning);
}

void Game::update()
{
    SDL_GetWindowSize(m_window, &m_windowSize.x, &m_windowSize.y);
    m_entityMgr.updateEntities();
}

void Game::render()
{
    SDL_RenderClear(m_renderer);
    auto entities = m_entityMgr.getEntities();
    for(auto entity : entities)
    {
        SDL_Rect textureRect;
        textureRect.x = 0;
        textureRect.y = 0;
        textureRect.w = entity.getSize().x;
        textureRect.h = entity.getSize().y;

        SDL_Rect windowRect;
        windowRect.x = entity.getPosition().x;
        windowRect.y = entity.getPosition().y;
        windowRect.w = entity.getSize().x;
        windowRect.h = entity.getSize().y;

        SDL_RenderCopy(m_renderer, entity.getTexture(), &textureRect, &windowRect);
    }
    SDL_Texture* texture = entities[0].getTexture();
    SDL_RenderPresent(m_renderer);
}

void Game::clean()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
