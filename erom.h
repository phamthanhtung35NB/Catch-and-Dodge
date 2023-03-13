#pragma once // đảm bảo rằng một tệp mã nguồn được đọc và biên dịch chỉ một lần duy nhất trong quá trình biên dịch.
#ifndef erom_H

#define erom_H


#include <windows.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <ctime>

int run();
bool init();
bool loadMedia();
void close();
int randomDiemA();
int randomTruot();
// Khai báo biến global username
extern std::string name_login;
extern std::string diemmax;
extern std::string arr_login[3];
extern std::string arr[4];//hien thi luc chơi
// arr[0]=so thu to
// arr[1]=name
// arr[2]=pass
// arr[3]=diem

#endif