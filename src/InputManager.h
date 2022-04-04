#ifndef _InputManager_h_
#define _InputManager_h_

#include <SDL.h>

class InputManager
{
public:
    InputManager();
    void handleInputs(bool& p_isRunning);
private:
    SDL_Event m_event;
};


#endif //_InputManager_h_