#include "InputManager.h"

InputManager::InputManager()
{}

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
                    break;
                case SDLK_DOWN:
                    break;
                case SDLK_RIGHT:
                    break;
                case SDLK_LEFT:
                    break;
                case SDLK_ESCAPE:
                    p_isRunning = false;
                    break;
            }
        }
        else if(m_event.type == SDL_KEYDOWN)
        {
            switch(m_event.key.keysym.sym)
            {
                case SDLK_UP:
                    break;
                case SDLK_DOWN:
                    break;
                case SDLK_RIGHT:
                    break;
                case SDLK_LEFT:
                    break;
            }
        }
    }
}