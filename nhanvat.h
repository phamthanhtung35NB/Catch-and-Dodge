// #pragma once
#ifndef NHANVAT_H
#define NHANVAT_H

// #include <windows.h>
// #include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include <iostream>
// #include <ctime>
//hien thi len man hinh

class nhanvat
{
private:
    SDL_Rect ToaDo;
    SDL_Surface* surfaceLink;
public:
    nhanvat();
    //khỏi tạo
    nhanvat(SDL_Surface* gALL, const char* path, int x, int y);
    ~nhanvat();
    void updateBeMat(SDL_Surface* surfaceLink);
    void updateToado(int x);
    int returnToaDoXY();
    // int randomDiemA();
    // int randomTruot();
    ~nhanvat();
};


#endif
