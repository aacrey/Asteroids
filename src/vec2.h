#ifndef _vec2_h_
#define _vec2_h_

struct vec2
{
    vec2() : x(0), y(0) {};
    vec2(int px, int py) : x(px), y(py) {};

    int x;
    int y;

    void operator=(const vec2& other)
    {
        x = other.x;
        y = other.y;
    }

    vec2 operator+(const vec2& other)
    {
        return vec2((x + other.x), (y + other.y));
    }

    bool operator==(const vec2& other)
    {
        if(other.x == x && other.y == y)
        {
            return true;
        }
        return false;
    }
};

#endif //_vec2_h_
