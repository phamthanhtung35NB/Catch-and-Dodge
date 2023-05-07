// #include"manHinhKhoiDong.h"
#include "endGame.h"

SDL_Window* ggwindow=NULL;
// SDL_Renderer* renderer =NULL;
SDL_Surface* ggall =NULL;
bool trueFalse= true;

// SDL_Texture* backgroundTexture = NULL;
Mix_Music* music3=NULL;
Mix_Chunk* soundKichChuot2=NULL;
// const char* VIDEO_FILE_PATH = "videonhacnen.mp4";
const int SCREEN_WIDTH = 800;//1850;//rộng
const int SCREEN_HEIGHT = 800;

nhanvat nen(ggall,"data/hetTym.png",0,0);
nhanvat SurfaceChoiLai(ggall,"data/tiepTucEndChoiLai.png",179,658);
nhanvat SurfaceTiepTuc(ggall,"data/tiepTucEndChoiLai.png",402,658);

Text lai(ggall, "data/arial.ttf", 35,"Exit",  { 255, 255, 255,255 },  225, 675);
Text tiep(ggall, "data/arial.ttf", 35,"Next",  { 255, 255, 255,255 },  440, 675);

bool initFileEndGame(){

    //Tạo một cửa sổ
    ggwindow = SDL_CreateWindow("End", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    // Tạo trình kết xuất cho cửa sổ
    ggall = SDL_GetWindowSurface( ggwindow );
    music3 = Mix_LoadMUS("data/nhacnendotoc.mp3");
    Mix_PlayMusic(music3, -1);
    soundKichChuot2 = Mix_LoadWAV("data/chuotkich.wav");
    return true;
}
bool endGame(const int& Lv,const int& diemDatDuoc,const std::string& name){

    initFileEndGame();
    // Text name2(ggall, "data/arial.ttf", 15,name.c_str(),  { 0, 0, 0,0 },  204, 231);
    // Text diem2(ggall, "data/arial.ttf", 15,intToString(diemDatDuoc).c_str(),  { 0, 0, 0,0 },  291, 366);
    Text name2(ggall, "data/KOMIKAX_.ttf", 43,name.c_str(),  { 255, 255, 255,0 },  200, 200);
    Text LV(ggall, "data/KOMIKAX_.ttf", 50,("Level Max: "+intToString(Lv)).c_str(),  { 0, 0, 0,0 },  220, 280);
    Text diem2(ggall, "data/KOMIKAX_.ttf", 35,"Point Number Max:",  { 0, 0, 255,0 },  200, 390);
    Text Point(ggall, "data/KOMIKAX_.ttf", 60,intToString(diemDatDuoc).c_str(),  { 0, 255, 0,0 },  315, 440);
    bool quit,checkLoa,checkNhapName;
    quit = false;
    checkNhapName=false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            nen.updateBeMat(ggall);
            if (event.type == SDL_QUIT) {
                quit = true;
                trueFalse=false;
            }
            int x, y;
            SDL_GetMouseState(&x, &y);
            //thoat
            if (x>185&&x<185+225&&y>660&&y<660+74)
            {
                SurfaceChoiLai.updateBeMat(ggall);
                lai.updateBeMatText(ggall,"Exit",{ 0, 0, 0 });
                tiep.updateBeMatText(ggall, "Next",{ (0,0,128) });
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    Mix_PlayChannel(-1, soundKichChuot2, 0);
                    trueFalse=false;
                    quit=true;
                }
        
            }
            //tiep tuc (chon che do)
            else if (x>407&&x<407+225&&y>660&&y<660+74)
            {
                SurfaceTiepTuc.updateBeMat(ggall);
                tiep.updateBeMatText(ggall,"Next",{ 0, 0, 0 });
                lai.updateBeMatText(ggall, "Exit",{ (0,0,128)});
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    Mix_PlayChannel(-1, soundKichChuot2, 0);
                    trueFalse=true;
                    quit=true;
                }
            }
            else{
                if (event.type == SDL_MOUSEBUTTONDOWN) std::cout<<x<<" "<<y<<"\n";
                lai.updateBeMatText(ggall, "Exit",{ (0,0,128)});
                tiep.updateBeMatText(ggall, "Next",{ (0,0,128) });
            }

        }
        name2.updateBeMatText(ggall);
        diem2.updateBeMatText(ggall);
        Point.updateBeMatText(ggall);
        LV.updateBeMatText(ggall);
        SDL_UpdateWindowSurface(ggwindow);
    }
    Mix_FreeMusic(music3);
    Mix_FreeChunk(soundKichChuot2);
    // SDL_DestroyTexture(backgroundTexture);
    // SDL_FreeSurface(nen);

    // SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ggwindow);
    // SDL_Quit();
    return trueFalse;
}


