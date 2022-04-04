#include "EntityManager.h"
#include "TextureManager.h"

EntityManager::EntityManager()
{}

void EntityManager::updateEntities()
{}

void EntityManager::initBasicEntites(SDL_Renderer* p_renderer, TextureManager& p_textureMgr, vec2 p_windowSize)
{
    /* initialize background */
    auto texture = p_textureMgr.getTextureFromImg("background.png", p_renderer);
    if(texture == nullptr)
    {
        SDL_Log("Cannot load background");
        return;
    }
    Entity backgrnd("background", texture);
    backgrnd.setPosition(vec2(0, 0));
    backgrnd.setSize(p_windowSize);
    m_entities.push_back(backgrnd);

    /* initialize player */
    texture = p_textureMgr.getTextureFromImg("ship_floating.png", p_renderer);
    if(texture == nullptr)
    {
        SDL_Log("Cannot load ship image");
        return;
    }
    Entity player1("player1", texture);
    player1.setPosition(vec2(p_windowSize.x / 2, p_windowSize.y / 2));
    vec2 size;
    SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
    player1.setSize(size);
    m_entities.push_back(player1);
}

std::vector<Entity>& EntityManager::getEntities()
{
    return m_entities;
}