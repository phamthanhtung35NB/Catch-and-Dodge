#include "khoitao.h"
//default
Text::Text() {
    this->font = NULL;
    this->texture = NULL;
    this->ToaDo.x = 0;
    this->ToaDo.y = 0;
    this->ToaDo.w = 0;
    this->ToaDo.h = 0;
}
Text::Text(SDL_Renderer* renderer, const char* font_path, int font_size, const char* message, SDL_Color color, int x, int y) {
    TTF_Init();
    this->font = TTF_OpenFont(font_path, font_size);
    SDL_Surface* surface = TTF_RenderText_Solid(font, message, color);
    this->texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(this->texture, NULL, NULL, &this->ToaDo.w, &this->ToaDo.h);
    this->ToaDo.x = x;
    this->ToaDo.y = y;
}
Text::~Text() {
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
    TTF_Quit();
}
void Text::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, NULL, &ToaDo);
}
void Text::updateToado(int y){
    ToaDo.y=y;
}
int Text::returnToaDoY(){
    return ToaDo.y;
}
///////////////////////////////////////////////////////////////////////////////////////
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
int nhanvat::returnToaDoX(){
    return ToaDo.x;
}
void nhanvat::updateToado(int x){
    ToaDo.x=x;
}