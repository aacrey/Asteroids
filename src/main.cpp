#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

int main(int argc, char* argv[])
{
    srand(time(0));
    Game game;
    if(!(game.init("Asteroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false)))
    {
        return 1;
    }

    while (game.isRunning())
    {
        game.handleEvents();
        game.update();
        game.render();
    }

    game.clean();

    return 0;
}