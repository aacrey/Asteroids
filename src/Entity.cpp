#include "Entity.h"

Entity::Entity(std::string name, SDL_Texture* texture) : m_name(name), m_texture(texture)
{}

const std::string& Entity::getName() const
{
    return m_name;
}

void Entity::setPosition(vec2& pos)
{
    m_position = pos;
}

const vec2& Entity::getPosition()
{
    return m_position;
}

void Entity::setSize(vec2& size)
{
    m_size = size;
}

const vec2& Entity::getSize()
{
    return m_size;
}

void Entity::setVelocity(vec2& velocity)
{
    m_velocity = velocity;
}

const vec2& Entity::getVelocity()
{
    return m_velocity;
}

void Entity::setTexture(SDL_Texture* texture)
{
    m_texture = texture;
}

SDL_Texture* Entity::getTexture()
{
    return m_texture;
}
