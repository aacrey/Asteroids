#ifndef _EntityManager_h_
#define _EntityManager_h_

#include <vector>
#include <memory>
#include "Entity.h"
#include "TextureManager.h"
#include "vec2.h"

class EntityManager
{
public:
    EntityManager();

    void initBasicEntites(SDL_Renderer* p_renderer, TextureManager& p_textureMgr, vec2 p_windowSize);
    void updateEntities();
    std::vector<Entity>& getEntities();

private:
    std::vector<Entity> m_entities; 
};


#endif //_EntityManager_h_