#ifndef _RenderManager_h_
#define _RenderManager_h_

#include <vector>
#include "Entity.h"

class RenderManager
{
public:
    RenderManager();
    void limitFramerate(int p_maxFramerate);
    void render(SDL_Renderer* p_renderer, std::vector<Entity>& p_entities);
    
private:
    unsigned int m_lastTick;
};

#endif //_RenderManager_h_