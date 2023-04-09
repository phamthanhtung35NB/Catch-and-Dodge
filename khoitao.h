#ifndef KHOITAO_H_
#define KHOITAO_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <ctime>
#include <fstream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include<time.h>

class Text {
public:
    Text();
    Text(SDL_Surface* gALL, const char* font_path, int font_size, const char* message, SDL_Color color, int x, int y);
    ~Text();
    void updateBeMatText(SDL_Surface* gALL);
    void updateToaDoY(int y);
    int returnToaDoY();
    void updateToaDoX(int X);
    int returnToaDoX() ;
    // int randomDiemA();
    // int randomTruot();
private:
    TTF_Font* font;
    // SDL_Texture* texture;
    SDL_Rect ToaDo;
    SDL_Surface* surfaceLinkText;
};

class nhanvat
{
private:
    SDL_Rect ToaDo;
    SDL_Surface* surfaceLink;
public:
    nhanvat();
    //khỏi tạo
    nhanvat(SDL_Surface* gALL, const char* path, int x, int y);
    nhanvat(SDL_Surface* gALL, const char* path,int x, int y,int w,int h);
    ~nhanvat();
    void updateBeMat(SDL_Surface* gALL);
    void updateBeMat(SDL_Surface* gALL,SDL_Rect &sizeCat);
    void updateToaDoX(int x);
    int returnToaDoX();
    int returnToaDoY();
    void updateToaDoY(int y);
    // int (int y);
};



double ranDom();

#endif // KHOITAO_H_