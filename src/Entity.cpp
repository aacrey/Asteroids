#include "Entity.h"
#include <iostream>

Entity::Entity(std::string p_name, SDL_Texture* p_texture) : m_name(p_name), m_texture(p_texture), m_rotation(0)
{}

const std::string& Entity::getName() const
{
    return m_name;
}

void Entity::setPosition(vec2& p_pos)
{
    m_position = p_pos;
}

const vec2& Entity::getPosition()
{
    return m_position;
}

void Entity::setSize(vec2& p_size)
{
    m_size = p_size;
}

const vec2& Entity::getSize()
{
    return m_size;
}

void Entity::setVelocity(vec2& p_velocity)
{
    m_velocity = p_velocity;
}

const vec2& Entity::getVelocity()
{
    return m_velocity;
}

void Entity::setTexture(SDL_Texture* p_texture)
{
    m_texture = p_texture;
}

SDL_Texture* Entity::getTexture()
{
    return m_texture;
}

void Entity::rotate(int p_rotation)
{
    m_rotation += p_rotation;
    if (m_rotation >= 360)
    {
        m_rotation -= 360;
    }
    else if (m_rotation < 0)
    {
        m_rotation += 360;
    }
}

int Entity::getRotation()
{
    return m_rotation;
}
