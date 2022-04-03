#include "Game.h"

Game::Game(): m_isRunning(false), m_window(nullptr), m_renderer(nullptr)
{}

Game::~Game()
{

}

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
    initBasicEntites();

    m_isRunning = true;
    return true; 
}

bool Game::isRunning()
{
    return m_isRunning;
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        m_isRunning = false;
        break;
    
    default:
        break;
    }
}

void Game::update()
{
    SDL_GetWindowSize(m_window, &m_windowSize.x, &m_windowSize.y);
}

void Game::render()
{
    SDL_RenderClear(m_renderer);
 
    for(auto entity : m_entities)
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
    SDL_Texture* texture = m_entities[0].getTexture();
    SDL_RenderPresent(m_renderer);
}

void Game::clean()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Game::initBasicEntites()
{
    /* initialize background */
    auto texture = m_textureMgr.getTextureFromImg("background.png", m_renderer);
    if(texture == nullptr)
    {
        SDL_Log("Cannot load background");
        return;
    }
    Entity backgrnd("background", texture);
    backgrnd.setPosition(vec2(0, 0));
    backgrnd.setSize(m_windowSize);
    m_entities.push_back(backgrnd);

    /* initialize player */
    texture = m_textureMgr.getTextureFromImg("ship_floating.png", m_renderer);
    if(texture == nullptr)
    {
        SDL_Log("Cannot load ship image");
        return;
    }
    Entity player1("player1", texture);
    player1.setPosition(vec2(m_windowSize.x / 2, m_windowSize.y / 2));
    vec2 size;
    SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
    player1.setSize(size);
    m_entities.push_back(player1);
}
