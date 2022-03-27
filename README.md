# Asteroids
Arcade asteroids game written in C++, using SDL

## Prerequisites

 - `cmake` installed on your computer
 - Internet connection:
     - This project uses the SDL2 and SDL_image libraries for graphics and the gtest libraries for testing
     - These libraries are open source
     - It would redundant to include them in this repo so they are included as submodules

## Build

 - Clone this repository with `git clone --recurse-submodules` to also clone the submodules
 - `cd` into the folder
 - Run `cd build`
 - Run `cmake ..` to configure
 - Run `cmake --build .` to build the binaries
 - The executable, called `Asteroids` will be in the _build/bin_ folder, along with the necessary .dll-s

## Tests

 - Tested on Windows 10
