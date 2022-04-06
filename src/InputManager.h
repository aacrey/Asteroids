#ifndef _InputManager_h_
#define _InputManager_h_

#include <memory>
#include <SDL.h>
#include "EntityManager.h"

class InputManager
{
public:
    InputManager(std::shared_ptr<EntityManager> p_entityMgr);
    void handleInputs(bool& p_isRunning);
private:
    SDL_Event m_event;
    std::shared_ptr<EntityManager> m_entityMgr;
};


#endif //_InputManager_h_