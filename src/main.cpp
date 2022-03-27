#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";

    if(SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_init failed. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    if(!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG_init failed. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    SDL_Window *window = SDL_CreateWindow("My first window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    return 0;
}