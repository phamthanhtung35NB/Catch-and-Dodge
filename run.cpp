
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <ctime>
#include <SDL2/SDL_image.h>
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;

int ramdomDiemA();
int randomTruot(const int& x,const int& y);


int randomTruot(const int& x,const int& y){
    //rand ()%(b -a+ 1)+a;    [a,b]
    srand(time(NULL));
    return rand ()%(y-x+ 1)+x;
}

int ramdomDiemA(){
    srand(time(NULL));
    return rand()%1000;
}
void start(){
    
}