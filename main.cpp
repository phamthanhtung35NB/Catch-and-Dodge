#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h> 
#include "run.cpp"
#include "login.cpp"
#include "erom.h"


// Your code to to push student code up to Firebase goes here... 


// const int SCREEN_WIDTH = 1000;
// const int SCREEN_HEIGHT = 1000;
std::string name;
std::string pass;
std::string diemmax;
int main( int argc, char* args[] )
{
    diemmax=login();
    start();
    return 0;
}

