#include"vatpham.h"

//default
Text::Text() {
    this->font = NULL;
    this->texture = NULL;
    this->ToaDo.x = 0;
    this->ToaDo.y = 0;
    this->ToaDo.w = 0;
    this->ToaDo.h = 0;
}
text::text(SDL_Renderer* renderer, const char* font_path, int font_size, const char* message, SDL_Color color, int x, int y)
{
    TTF_Init();
    this->font=TTF_OpenFont(font_path,font_size);
    SDL_Surface* surface=TTF_RenderText_Solid(font,message,color);
    this->texture=SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(this->texture, NULL, NULL, &this->ToaDo.w, &this->ToaDo.h);
    this->ToaDo.x = x;
    this->ToaDo.y = y;
}

text::~text()
{
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
    TTF_Quit();
}
void text::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, NULL, &ToaDo);
}
void text::updateToado(int y){
    ToaDo.y=y;
}
int text::returnToaDoY(){
    return ToaDo.y;
}
