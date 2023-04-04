#include"nhanvat.h"

void nhanvat::updateBeMat(SDL_Surface * gALL){
    SDL_BlitSurface(surfaceLink, NULL, gALL, &ToaDo);
}
nhanvat::nhanvat(SDL_Surface* ALL, const char* path,int x, int y)
{
    SDL_Init( SDL_INIT_VIDEO );
    // load link
    this->surfaceLink = IMG_Load(path);
    this->ToaDo.x = x;
    this->ToaDo.y = y;
}
nhanvat::nhanvat(){
    this->surfaceLink = NULL;
    this->ToaDo.x = 0;
    this->ToaDo.y = 0;
    this->ToaDo.w = 0;
    this->ToaDo.h = 0;
}
nhanvat::~nhanvat()
{
    SDL_FreeSurface(surfaceLink);
	SDL_Quit();
}
int nhanvat::returnToaDoXY(){
    return ToaDo.x;
}
void nhanvat::updateToado(int x){
    ToaDo.x=x;
}