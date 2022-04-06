#include "Game.h"

Game::Game(): m_isRunning(false), m_window(nullptr), m_renderer(nullptr)
{
    m_textureMgr = std::make_shared<TextureManager>();
    m_entityMgr = std::make_shared<EntityManager>(m_textureMgr);
    m_inputMgr = std::make_shared<InputManager>(m_entityMgr);
}

Game::~Game()
{}

bool Game::init(std::string title, int xPos, int yPos, int width, int height, bool isFullscreen)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        SDL_Log("SDL Initialization Failed: %s", SDL_GetError());
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    int res = IMG_Init(imgFlags);
    if((res & imgFlags) != imgFlags)
    {
        SDL_Log("SDL_image Initialization Failed: %s", SDL_GetError());
        return false;
    }

    int windowFlags = SDL_WINDOW_SHOWN;
    if(isFullscreen)
    {
        windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN;
    }
    m_window = SDL_CreateWindow(title.c_str(), xPos, yPos, width, height, windowFlags);
    if(m_window == nullptr)
    {
        SDL_Log("Window Creation Failed: %s", SDL_GetError());
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    if(m_window == nullptr)
    {
        SDL_Log("Renderer Creation Failed: %s", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

    m_textureMgr->setRenderer(m_renderer);

    SDL_GetWindowSize(m_window, &m_windowSize.x, &m_windowSize.y);
    m_entityMgr->initBasicEntites(m_windowSize);

    m_isRunning = true;
    return true; 
}

bool Game::isRunning()
{
    return m_isRunning;
}

void Game::handleEvents()
{
    m_inputMgr->handleInputs(m_isRunning);
}

void Game::update()
{
    SDL_GetWindowSize(m_window, &m_windowSize.x, &m_windowSize.y);
    m_entityMgr->deleteEnemiesLeavingViewport(m_windowSize);
    //m_entityMgr->generateEnemyEntities((SDL_GetTicks64() / 10000 + 1), m_windowSize);
    m_entityMgr->generateEnemyEntities(3, m_windowSize);
    m_entityMgr->updateAllEntityPositions();
}

void Game::render()
{
    m_renderMgr.render(m_renderer, m_entityMgr->getEntities());
}

void Game::clean()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
