#ifndef _Entity_h_
#define _Entity_h_

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "vec2.h"

class Entity
{
public:
    Entity(std::string name, SDL_Texture* texture);

    const std::string& getName() const;

    void setPosition(vec2& pos);
    const vec2& getPosition();

    void setSize(vec2& size);
    const vec2& getSize();

    void setVelocity(vec2& velocity);
    const vec2& getVelocity();

    void setTexture(SDL_Texture* texture);
    SDL_Texture* getTexture();
    
private:
    std::string m_name;

    vec2 m_position;
    vec2 m_size;
    vec2 m_velocity;

    SDL_Texture* m_texture;
};

#endif //_Entity_h_
