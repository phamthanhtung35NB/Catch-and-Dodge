#ifndef KHOITAO_H_
#define KHOITAO_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <ctime>
#include <windows.h>
class Text {
public:
    Text();
    Text(SDL_Renderer* renderer, const char* font_path, int font_size, const char* message, SDL_Color color, int x, int y);
    ~Text();
    void render(SDL_Renderer* renderer);
    void updateToado(int y);
    int returnToaDoY() ;
    // int randomDiemA();
    // int randomTruot();
private:
    TTF_Font* font;
    SDL_Texture* texture;
    SDL_Rect ToaDo;
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
    ~nhanvat();
    void updateBeMat(SDL_Surface* gALL);
    void updateToado(int x);
    int returnToaDoX();
};

#endif // KHOITAO_H_