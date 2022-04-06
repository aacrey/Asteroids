#include "InputManager.h"
#include <iostream>

InputManager::InputManager(std::shared_ptr<EntityManager> p_entityMgr)
{
    m_entityMgr = p_entityMgr;
}

void InputManager::handleInputs(bool& p_isRunning)
{
    while(SDL_PollEvent(&m_event) != 0)
    {
        if(m_event.type == SDL_QUIT)
        {
            p_isRunning = false;
            break;
        }
        else if(m_event.type == SDL_KEYDOWN)
        {
            switch(m_event.key.keysym.sym)
            {
                case SDLK_UP:
                    m_entityMgr->movePlayerEntity(3);
                    m_entityMgr->updatePlayerEntityTexture("player1", true);
                    break;
                case SDLK_DOWN:
                    break;
                case SDLK_RIGHT:
                    m_entityMgr->rotatePlayerEntity("player1", 3);
                    m_entityMgr->updatePlayerEntityTexture("player1", true);
                    break;
                case SDLK_LEFT:
                    m_entityMgr->rotatePlayerEntity("player1", -3);
                    m_entityMgr->updatePlayerEntityTexture("player1", true);
                    break;
                case SDLK_ESCAPE:
                    p_isRunning = false;
                    break;
            }
        }
        else if(m_event.type == SDL_KEYUP)
        {
            switch(m_event.key.keysym.sym)
            {
                case SDLK_UP:
                    m_entityMgr->updatePlayerEntityTexture("player1", false);
                    break;
                case SDLK_DOWN:
                    break;
                case SDLK_RIGHT:
                    m_entityMgr->updatePlayerEntityTexture("player1", false);
                    break;
                case SDLK_LEFT:
                    m_entityMgr->updatePlayerEntityTexture("player1", false);
                    break;
            }
        }
    }
}