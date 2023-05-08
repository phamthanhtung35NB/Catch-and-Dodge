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
#include <string>
#include <SDL2/SDL_mixer.h>
extern bool checkLoa;
extern Mix_Music* music;
extern const Uint8 * keyState;


// extern int check=5;
class Text {
public:
    Text();
    Text(SDL_Surface* gALL, const char* font_path, int font_size, const char* message, SDL_Color color, int x, int y);
    ~Text();
    void updateBeMatText(SDL_Surface* gALL);
    void updateBeMatText(SDL_Surface* gALL,const char* message, SDL_Color color);
    void updateToaDoY(int y);
    int returnToaDoY();
    void updateToaDoX(int X);
    int returnToaDoX();
    void updateWH(const char* message,int &W,int &H);
private:
    TTF_Font* font;
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

class bossG
{
private:
    SDL_Rect ToaDo;
    SDL_Surface* surfaceLink;
    int tocDoRoi=4;
    int tocDoDuoi=5;
public:
    bossG();
    //khỏi tạo
    bossG(SDL_Surface* gALL, const char* path, int x, int y);
    bossG(SDL_Surface* gALL, const char* path,int x, int y,int w,int h);
    ~bossG();
    void updateToaDoBosVaVaTram(SDL_Surface* gALL);
    bool updateToaDoBosVaVaTram(SDL_Surface* gALL,SDL_Rect &nhanvat);
    void khoiTaoLaiToaDo();
};

std::string intToString(int num);
double ranDom();

#endif // KHOITAO_H_
