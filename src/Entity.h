#ifndef _Entity_h_
#define _Entity_h_

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "vec2.h"

class Entity
{
public:
    Entity(std::string p_name, SDL_Texture* p_texture);

    const std::string& getName() const;

    void setPosition(vec2& p_pos);
    const vec2& getPosition();

    void setSize(vec2& p_size);
    const vec2& getSize();

    void setVelocity(vec2& p_velocity);
    const vec2& getVelocity();

    void setTexture(SDL_Texture* p_texture);
    SDL_Texture* getTexture();

    void rotate(int p_rotation);
    int getRotation();

private:
    std::string m_name;

    vec2 m_position;
    vec2 m_size;
    vec2 m_velocity;
    int m_rotation;

    SDL_Texture* m_texture;
};

#endif //_Entity_h_
