#include "khoitao.h"
//default
Text::Text() {
    this->font = NULL;
    this->surfaceLinkText = NULL;
    this->ToaDo.x = 0;
    this->ToaDo.y = 0;
    this->ToaDo.w = 0;
    this->ToaDo.h = 0;
}
Text::Text(SDL_Surface* gALL, const char* font_path, int font_size, const char* message, SDL_Color color, int x, int y) {
    TTF_Init();
    SDL_Init( SDL_INIT_VIDEO );
    this->font = TTF_OpenFont(font_path, font_size);if (font==NULL)std::cout <<"\nko co phong";
    this->surfaceLinkText = TTF_RenderText_Solid(font, message, color);
    // this->texture = SDL_CreateTextureFromSurface(renderer, surface);
    // SDL_FreeSurface(surface);
    // SDL_QueryTexture(this->texture, NULL, NULL, &this->ToaDo.w, &this->ToaDo.h);
    this->ToaDo.x = x;
    this->ToaDo.y = y;
}
Text::~Text() {
    TTF_CloseFont(font);
    SDL_FreeSurface(surfaceLinkText);
    TTF_Quit();
}
void Text::updateBeMatText(SDL_Surface* gALL) {
    SDL_BlitSurface(surfaceLinkText, NULL, gALL, &ToaDo);
}
void Text::updateToadoY(int y){
    ToaDo.y=y;
}
int Text::returnToaDoY(){
    return ToaDo.y;
}
void Text::updateToadoX(int x){
    ToaDo.x=x;
}
int Text::returnToaDoX(){
    return ToaDo.x;
}
///////////////////////////////////////////////////////////////////////////////////////
void nhanvat::updateBeMat(SDL_Surface * gALL){
    SDL_BlitSurface(surfaceLink, NULL, gALL, &ToaDo);
}
nhanvat::nhanvat(SDL_Surface* gALL, const char* path,int x, int y)
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