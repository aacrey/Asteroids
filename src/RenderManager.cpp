#include "RenderManager.h"
#include <iostream>

RenderManager::RenderManager() : m_lastTick(0)
{}

void RenderManager::limitFramerate(int p_maxFramerate)
{
    int frameTime = 1000 / p_maxFramerate;
    auto elapsed = SDL_GetTicks64() - m_lastTick;
    if (elapsed < frameTime)
    {
        SDL_Delay(frameTime - elapsed);
    }
    m_lastTick = SDL_GetTicks64();
}

void RenderManager::render(SDL_Renderer* p_renderer, std::vector<Entity>& p_entities)
{
    this->limitFramerate(60);
    SDL_RenderClear(p_renderer);
    for (auto& entity : p_entities)
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

        //SDL_RenderCopy(p_renderer, entity.getTexture(), &textureRect, &windowRect);
        SDL_RenderCopyEx(p_renderer, entity.getTexture(), &textureRect, &windowRect, entity.getRotation(), NULL, SDL_FLIP_HORIZONTAL);
    }
    SDL_RenderPresent(p_renderer);
}