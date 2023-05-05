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
// Hàm tạo Text
Text::Text(SDL_Surface* gALL, const char* font_path, int font_size, const char* message, SDL_Color color, int x, int y) {
    TTF_Init();
    SDL_Init( SDL_INIT_VIDEO );
    this->font = TTF_OpenFont(font_path, font_size);if (font==NULL)std::cout <<"\nko co phong";
    this->surfaceLinkText = TTF_RenderText_Solid(font, message, color);
    // SDL_FreeFormat()
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
void Text::updateBeMatText(SDL_Surface* gALL,const char* message, SDL_Color color) {
    SDL_BlitSurface(TTF_RenderText_Solid(font, message, color), NULL, gALL, &ToaDo);
}
void Text::updateToaDoY(int y){
    ToaDo.y=y;
}
int Text::returnToaDoY(){
    return ToaDo.y;
}
void Text::updateToaDoX(int x){
    ToaDo.x=x;
}
int Text::returnToaDoX(){
    return ToaDo.x;
}

///////////////////////////////////////////////////////////////////////////////////////

void nhanvat::updateBeMat(SDL_Surface * gALL){
    //surface nguồn.// vùng cần sao chép trên surface nguồn.//surface đích.//vùng cần vẽ trên surface đích
    SDL_BlitSurface(surfaceLink, NULL, gALL, &ToaDo);
}
void nhanvat::updateBeMat(SDL_Surface * gALL,SDL_Rect &sizeCat){
    //surface nguồn.// vùng cần sao chép trên surface nguồn.//surface đích.//vùng cần vẽ trên surface đích.
    SDL_BlitSurface(surfaceLink, &sizeCat, gALL, &ToaDo);
}
nhanvat::nhanvat(SDL_Surface* gALL, const char* path,int x, int y)
{
    SDL_Init( SDL_INIT_VIDEO );
    // load link
    this->surfaceLink = IMG_Load(path);
    this->ToaDo.x = x;
    this->ToaDo.y = y;
}
nhanvat::nhanvat(SDL_Surface* gALL, const char* path,int x, int y,int w,int h)
{
    SDL_Init( SDL_INIT_VIDEO );
    // load link
    this->surfaceLink = IMG_Load(path);
    this->ToaDo.x = x;
    this->ToaDo.y = y;
    this->ToaDo.w = w;
    this->ToaDo.h = h;
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
void nhanvat::updateToaDoX(int x){
    ToaDo.x=x;
}
// <<<<<<< HEAD
int nhanvat::returnToaDoY(){
    return ToaDo.y;
}
void nhanvat::updateToaDoY(int y){
    ToaDo.y=y;
}

///////////////////////////////////////////////////////////////////////////////////////

void bossG::updateToaDoBosVaVaTram(SDL_Surface * gALL){
    //surface nguồn.// vùng cần sao chép trên surface nguồn.//surface đích.//vùng cần vẽ trên surface đích
    SDL_BlitSurface(surfaceLink, NULL, gALL, &ToaDo);
}
bool bossG::updateToaDoBosVaVaTram(SDL_Surface* gALL, SDL_Rect &nhanvat){
    //dduoir
    if (ToaDo.x<nhanvat.x)
    {
        ToaDo.x+=tocDoDuoi;
    }
    else if (ToaDo.x>nhanvat.x)
    {
        ToaDo.x-=tocDoDuoi;
    }
    //roiw
    
    ToaDo.y+=tocDoRoi;
    
    //vatram
    if (ToaDo.y>500)
    {
        if (SDL_HasIntersection(&nhanvat, &ToaDo)){
            ToaDo.x=0;
            ToaDo.y=1000;
            return 1;
        }
    }
    //surface nguồn.// vùng cần sao chép trên surface nguồn.//surface đích.//vùng cần vẽ trên surface đích.
    SDL_BlitSurface(surfaceLink, NULL, gALL, &ToaDo);
    return false;
}
void bossG::khoiTaoLaiToaDo(){
    ToaDo.x=700;
    ToaDo.y=0;
}
bossG::bossG(SDL_Surface* gALL, const char* path,int x, int y)
{
    SDL_Init( SDL_INIT_VIDEO );
    // load link
    this->surfaceLink = IMG_Load(path);
    this->ToaDo.x = x;
    this->ToaDo.y = y;
    this->ToaDo.w = 10;
    this->ToaDo.h = 10;
}

bossG::bossG(){
    this->surfaceLink = NULL;
    this->ToaDo.x = 0;
    this->ToaDo.y = 0;
    this->ToaDo.w = 0;
    this->ToaDo.h = 0;
}
bossG::~bossG()
{
    
    SDL_FreeSurface(surfaceLink);
	SDL_Quit();
}
// int bossG::returnToaDoX(){
//     return ToaDo.x;
// }

// // <<<<<<< HEAD
// int bossG::returnToaDoY(){
//     return ToaDo.y;
// }
// void bossG::updateToaDoY(int y){
//     ToaDo.y=y;
// }

///////////////////////////////////////////////////////////

double ranDom(){
    //rand ()%(b -a+ 1)+a;    [a,b]
    // clock_t start, end;   // Khai báo biến thời gian
    // double time_use;      // Thời gian sử dụng
    // start = clock();  
    // end = clock();  // lấy thời gian sau khi thực hiện 
    double timesau=clock()%10;
    // if (timesau<5)
    // {   
    //     int timez=clock()%100;
    //     // while (timez>15||timez==0)
    //     // {
    //     //    timez=clock()%100;
    //     // }
    //     return timez*100;
    // }else
    return timesau*100;

}
std::string intToString(int num) {
    std::string result = "";
    bool isNegative = false;

    // xử lý số âm
    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    // chuyển đổi từng chữ số thành ký tự tương ứng
    do {
        char digit = '0' + (num % 10);
        result = digit + result;
        num /= 10;
    } while (num > 0);

    // xử lý trường hợp số âm
    if (isNegative) {
        result = '-' + result;
    }

    return result;
}


