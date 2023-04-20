#include"manHinhKhoiDong.h"

SDL_Window* window=NULL;
// SDL_Renderer* renderer =NULL;
SDL_Surface* gall =NULL;
std::string inputString;
// SDL_Surface* SurfaceMuteVolume=NULL;
// SDL_Surface* SurfaceOption=NULL;
// SDL_Surface* SurfaceFeedBack=NULL;
// SDL_Surface* SurfacePlay=NULL;
// SDL_Surface* SurfaceExit=NULL;
// SDL_Surface* SurfaceUserName=NULL;
// SDL_Surface* backgroundSurface=NULL;


// SDL_Texture* backgroundTexture = NULL;
Mix_Music* music=NULL;
Mix_Chunk* soundKichChuot=NULL;
// const char* VIDEO_FILE_PATH = "videonhacnen.mp4";
const int SCREEN_WIDTH = 1000;//1850;//rộng
const int SCREEN_HEIGHT = 800;

nhanvat backgroundSurface(gall,"anhnenkhoidong.png",0,0);
nhanvat SurfaceMuteVolume(gall,"data/tatlo.png",820,14);
nhanvat SurfaceOption(gall,"data/chucnang.png",905,13);
nhanvat SurfaceFeedBack(gall,"data/feedback.png",5,720);
nhanvat SurfacePlay(gall,"data/playkhian.png",374,576);
nhanvat SurfaceExit(gall,"data/exitkhian.png",780,702);
nhanvat SurfaceUserName(gall,"data/nhapthongtin.png",286,401);

bool initFileKhoiDong(){

    //Tạo một cửa sổ
    window = SDL_CreateWindow("Start", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    // Tạo trình kết xuất cho cửa sổ
    gall = SDL_GetWindowSurface( window );
    // renderer = SDL_CreateRenderer(window, -1, 0);
    // backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    music = Mix_LoadMUS("nhacnendotoc.mp3");
    Mix_PlayMusic(music, -1);
    soundKichChuot = Mix_LoadWAV("data/chuotkich.wav");
    return true;
}
std::string manHinhKhoiDong(){

    initFileKhoiDong();
    Text text12kitu(gall, "data/arial.ttf", 15,"Userame no more than 12 characters and no special characters",  { 255, 255, 255,255 },  293, 410);
    Text textName(gall, "data/arial.ttf", 40,inputString.c_str(),  { 255, 255, 255,255 },  305, 439);
    bool quit,checkLoa,checkNhapName;
    quit = false;
    checkLoa=true;
    checkNhapName=false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            backgroundSurface.updateBeMat(gall);
            if (event.type == SDL_QUIT) {
                inputString="        ";
                quit = true;
            }
             else if (event.type == SDL_MOUSEBUTTONDOWN) {
                
                Mix_PlayChannel(-1, soundKichChuot, 0);
            }
            int x, y;
            SDL_GetMouseState(&x, &y);
            //nut loa
            if (x>820&&x<866&&y>14&&y<81)
            {
                SurfaceMuteVolume.updateBeMat(gall);
                
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    checkLoa=!checkLoa;
                    if (checkLoa==false)
                    {
                        Mix_HaltMusic();
                    }
                    else if(checkLoa==true){
                        Mix_PlayMusic(music, -1);
                    }
                    
                }
        
            }
            //nut chuc nang
            else if (x>903&&x<969&&y>15&&y<82)
            {
                SurfaceOption.updateBeMat(gall);
            }
            //nut phản hồi
            else if (x>5&&x<217&&y>720&&y<790)
            {
                SurfaceFeedBack.updateBeMat(gall);
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    ShellExecute(NULL, "open", "https://github.com/phamthanhtung35NB/Catch-and-Dodge/issues/new", NULL, NULL, SW_SHOWNORMAL);
                }
            }
            //nút play
            else if (x>374&&x<635&&y>576&&y<694)
            {
                SurfacePlay.updateBeMat(gall);
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    quit=true;
                }
            }
            //nút thoát
            else if (x>780&&x<1000&&y>702&&y<800)
            {
                SurfaceExit.updateBeMat(gall);
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    quit=true;
                    Mix_PlayChannel(-1, soundKichChuot, 0);
                    SDL_Delay(1000);
                }
            }
            //ô nhạp tên
            else if (x>286&&x<716&&y>401&&y<509)
            {
                SurfaceUserName.updateBeMat(gall);
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    checkNhapName=true;
                }
                
            }
            else{
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    checkNhapName=false;
                }
            }
            //else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN&&checkNhapName==true) {
            //         std::cout << "-----" << inputString.c_str() << std::endl;
            //         // inputString.clear();
            // }
            if (checkNhapName==true)
            {
                if (event.type == SDL_TEXTINPUT && inputString.size()<=12) {
                    inputString += event.text.text;
                }else if (event.key.keysym.sym == SDLK_BACKSPACE && !inputString.empty()) {
                    inputString.pop_back();
                    SDL_Delay(100);
                }

            }

            
        }
        if (checkLoa==false)
        {
            SurfaceMuteVolume.updateBeMat(gall);
        }
        if (checkNhapName==true)
        {
            SurfaceUserName.updateBeMat(gall);
            textName.updateBeMatText(gall, inputString.c_str(),{ 0, 0, 0 });
            text12kitu.updateBeMatText(gall);
        }
        

        

        SDL_UpdateWindowSurface(window);
    }
    Mix_FreeMusic(music);
    Mix_FreeChunk(soundKichChuot);
    // SDL_DestroyTexture(backgroundTexture);
    // SDL_FreeSurface(backgroundSurface);

    // SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    // SDL_Quit();
    return inputString;
}


