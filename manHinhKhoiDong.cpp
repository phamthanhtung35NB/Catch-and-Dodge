#include"manHinhKhoiDong.h"
SDL_Window* gWindowFileKhoiDong = NULL;
SDL_Surface* gALLFileKhoiDong = NULL;
const int SCREEN_WIDTH = 1850;//1850;//rộng
const int SCREEN_HEIGHT = 1000;
bool initFileKhoiDong(){
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        std::cout<<"SDL_ERROR: \n"<<SDL_GetError();
        return false;
    }
	if (TTF_Init()<0)
    {
        return false;
    }
    gWindowFileKhoiDong = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN );
	if( gWindowFileKhoiDong == NULL ){
        std::cout<<( "Window could not be created! SDL_Error:\n", SDL_GetError() );
        return false;
    }
    gALLFileKhoiDong = SDL_GetWindowSurface( gWindowFileKhoiDong );
    int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags)){
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                return false;
            }
    return true;
}
void manHinhKhoiDong(){
    std::cout<<initFileKhoiDong();
}