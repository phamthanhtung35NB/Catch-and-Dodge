#pragma once // đảm bảo rằng một tệp mã nguồn được đọc và biên dịch chỉ một lần duy nhất trong quá trình biên dịch.
#ifndef vatpham_H
#define vatpham_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <exception>
#include <string>
#include <SDL2/SDL_ttf.h>
#include <windows.h>

class text
{
private:
    TTF_Font* font;
    SDL_Texture* texture;
    SDL_Rect ToaDo;
public:
    text();
    text(SDL_Renderer* renderer, const char* font_path, int font_size, const char* message, SDL_Color color, int x, int y);
    ~text();
    void render(SDL_Renderer* renderer);
    void updateToado(int y);
    int returnToaDoY();
};


#endif