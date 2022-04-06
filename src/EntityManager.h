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
    EntityManager(std::shared_ptr<TextureManager> p_textureMgr);

    void initBasicEntites(vec2 p_windowSize);

    void deleteEnemiesLeavingViewport(vec2& p_windowSize);
    void generateEnemyEntities(unsigned int p_level, vec2& p_windowSize);
    void movePlayerEntity(int p_value);

    void rotatePlayerEntity(std::string p_playerName, int p_value);
    void updatePlayerEntityTexture(std::string p_playerName, bool isMoving);

    void updateAllEntityPositions();

    std::vector<Entity>& getEntities();

private:
    std::vector<Entity> m_entities;
    std::shared_ptr<TextureManager> m_textureMgr;
};


#endif //_EntityManager_h_