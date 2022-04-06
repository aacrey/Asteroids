#include <iostream>
#include <random>
#include <cstdlib>
#include "EntityManager.h"
#include "TextureManager.h"

EntityManager::EntityManager(std::shared_ptr<TextureManager> p_textureMgr)
{
    m_textureMgr = p_textureMgr;
}

void EntityManager::initBasicEntites(vec2 p_windowSize)
{
    /* initialize background */
    auto texture = m_textureMgr->getTextureFromImg("background.png");
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
    texture = m_textureMgr->getTextureFromImg("ship_floating.png");
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

void EntityManager::deleteEnemiesLeavingViewport(vec2& p_windowSize)
{
    for (auto entity = std::begin(m_entities); entity !=end(m_entities); ++entity)
    {
        if (entity->getName() != "player1" && entity->getName() != "player2" && entity->getName() != "background")
        {
            vec2 pos = entity->getPosition();
            if (pos.x > p_windowSize.x ||
                pos.x < -256 ||
                pos.y > p_windowSize.y ||
                pos.y < -256)
            {
                m_entities.erase(entity);
                break;
            }
        }
    }
}

void EntityManager::generateEnemyEntities(unsigned int p_level, vec2& p_windowSize)
{
    unsigned int numberOfEnemyEntities = 0;
    for (auto& entity : m_entities)
    {
        if (entity.getName() != "player1" && entity.getName() != "player2" && entity.getName() != "background")
        {
            ++numberOfEnemyEntities;
        }
    }

    if (numberOfEnemyEntities < p_level)
    {
        SDL_Texture* texture = m_textureMgr->getTextureFromImg("L_rock_1.png");
        Entity rock("L_rock_1", texture);

        // Generate random position just outside the viewport and random direction
        int xPos, yPos, xVel = 0, yVel = 0;
        if (rand() % 2)
        {
            xPos = rand() % (p_windowSize.x + 256) - 256;
            if (xPos % 2)
            {
                yPos = -256;
                yVel = 1;
            }
            else
            {
                yPos = p_windowSize.y;
                yVel = -1;
            }
            if (xPos < 0)
            {
                xVel = 1;
            }
            else if (xPos > 0.8 * p_windowSize.x)
            {
                xVel = -1;
            }
        }
        else
        {
            yPos = rand() % (p_windowSize.x + 256) - 256;
            if (yPos % 2)
            {
                xPos = -256;
                xVel = 1;
            }
            else
            {
                xPos = p_windowSize.x;
                xVel = -1;
            }
            if (yPos < 0)
            {
                yVel = 1;
            }
            else if (yPos > 0.8 * p_windowSize.y)
            {
                yVel = -1;
            }
        }
 
        rock.setPosition(vec2(xPos, yPos));
        rock.setVelocity(vec2(xVel, yVel));

        vec2 size;
        SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
        rock.setSize(size);

        m_entities.push_back(rock);
    }
}

void EntityManager::movePlayerEntity(int p_value)
{
    for(auto& entity: m_entities)
    {
        if (entity.getName() == "player1")
        {
            vec2 position = entity.getPosition();
            vec2 move;
            int rotation = entity.getRotation();
            if (rotation < 15)  //TODO: This is horrendous. But it works
            {
                move.x = 0;
                move.y = -3;
            }
            else if (rotation < 30)
            {
                move.x = 1;
                move.y = -3;
            }
            else if (rotation < 45)
            {
                move.x = 2;
                move.y = -3;
            }
            else if (rotation < 60)
            {
                move.x = 3;
                move.y = -2;
            }
            else if (rotation < 75)
            {
                move.x = 3;
                move.y = -1;
            }
            else if (rotation < 90)
            {
                move.x = 3;
                move.y = 0;
            }
            else if (rotation < 105)
            {
                move.x = 3;
                move.y = 1;
            }
            else if (rotation < 120)
            {
                move.x = 3;
                move.y = 2;
            }
            else if (rotation < 135)
            {
                move.x = 3;
                move.y = 3;
            }
            else if (rotation < 150)
            {
                move.x = 2;
                move.y = 3;
            }
            else if (rotation < 165)
            {
                move.x = 1;
                move.y = 3;
            }
            else if (rotation < 180)
            {
                move.x = 0;
                move.y = 3;
            }
            else if (rotation < 195)
            {
                move.x = -1;
                move.y = 3;
            }
            else if (rotation < 210)
            {
                move.x = -2;
                move.y = 3;
            }
            else if (rotation < 225)
            {
                move.x = -3;
                move.y = 3;
            }
            else if (rotation < 240)
            {
                move.x = -3;
                move.y = 2;
            }
            else if (rotation < 255)
            {
                move.x = -3;
                move.y = 1;
            }
            else if (rotation < 270)
            {
                move.x = -3;
                move.y = 0;
            }
            else if (rotation < 285)
            {
                move.x = -3;
                move.y = -1;
            }
            else if (rotation < 300)
            {
                move.x = -3;
                move.y = -2;
            }
            else if (rotation < 315)
            {
                move.x = -3;
                move.y = -3;
            }
            else if (rotation < 330)
            {
                move.x = -2;
                move.y = -3;
            }
            else if (rotation < 345)
            {
                move.x = -1;
                move.y = -3;
            }
            else if (rotation < 360)
            {
                move.x = 0;
                move.y = -3;
            }

            entity.setPosition(position + move);
        }
    }
}

void EntityManager::rotatePlayerEntity(std::string p_playerName, int p_value)
{
    for (auto& entity : m_entities)
    {
        if (entity.getName() == p_playerName)
        {
            entity.rotate(p_value);
        }
    }
}

void EntityManager::updatePlayerEntityTexture(std::string p_playerName, bool isMoving)
{
    for (auto& entity : m_entities)
    {
        if (entity.getName() == p_playerName)
        {
            if (isMoving)
            {
                auto texture = m_textureMgr->getTextureFromImg("ship_going.png");
                entity.setTexture(texture);
            }
            else
            {
                auto texture = m_textureMgr->getTextureFromImg("ship_floating.png");
                entity.setTexture(texture);
            }
        }
    }
}

void EntityManager::updateAllEntityPositions()
{
    for (auto& entity : m_entities)
    {
        vec2 pos = entity.getPosition();
        vec2 veloc = entity.getVelocity();
        entity.setPosition(pos + veloc);
    }
}

std::vector<Entity>& EntityManager::getEntities()
{
    return m_entities;
}