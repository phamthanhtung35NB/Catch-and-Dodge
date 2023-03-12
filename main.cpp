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

extern std::string name_login;
extern std::string diemmax;
extern std::string pass_login;

std::string arr_login[3];
std::string arr[4];
int main( int argc, char* args[] )
{
    diemmax=login();
    return 0;
}