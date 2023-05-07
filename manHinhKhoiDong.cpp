#include"manHinhKhoiDong.h"

SDL_Window* window=NULL;

SDL_Surface* gall =NULL;


// bool checkLoa;

// SDL_Texture* backgroundTexture = NULL;

Mix_Chunk* soundKichChuot=NULL;
// const char* VIDEO_FILE_PATH = "videonhacnen.mp4";
const int SCREEN_WIDTH = 1000;//1850;//rộng
const int SCREEN_HEIGHT = 800;

nhanvat backgroundSurface(gall,"data/anhnenkhoidong.png",0,0);
nhanvat SurfaceMuteVolume(gall,"data/tatlo.png",820,14);
nhanvat SurfaceOption(gall,"data/chucnang.png",905,13);
nhanvat SurfaceFeedBack(gall,"data/feedback.png",5,720);
nhanvat SurfacePlay(gall,"data/playkhian.png",374,576);
nhanvat SurfaceExit(gall,"data/exitkhian.png",780,702);
nhanvat SurfaceUserName(gall,"data/nhapthongtin.png",286,401);
// keyState;
bool initFileKhoiDong(){

    //Tạo một cửa sổ
    window = SDL_CreateWindow("Start", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
    // Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    // Tạo trình kết xuất cho cửa sổ
    gall = SDL_GetWindowSurface( window );
    // renderer = SDL_CreateRenderer(window, -1, 0);
    // backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    music = Mix_LoadMUS("data/nhacnendotoc.mp3");
    Mix_PlayMusic(music, -1);
    soundKichChuot = Mix_LoadWAV("data/chuotkich.wav");
    return true;
}
int manHinhKhoiDong(){

    initFileKhoiDong();
    Text text12kitu(gall, "data/KOMIKAX_.ttf", 15,"Userame no more than 12 characters and no special characters",  { 255, 255, 255,255 },  240, 410);
    Text textName(gall, "data/KOMIKAX_.ttf", 40,inputString.c_str(),  { 255, 255, 255,255 },  310, 422);
    bool quit,checkNhapName;
    quit = false;
    
    checkNhapName=false;
    while (!quit) {
        SDL_Event event;
        keyState = SDL_GetKeyboardState(NULL);
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
                    // ShellExecute(NULL, "open", "https://github.com/phamthanhtung35NB/Catch-and-Dodge/issues/new", NULL, NULL, SW_SHOWNORMAL);
                    // ShellExecute(NULL, "open", "https://www.facebook.com/phamthanhtung489", NULL, NULL, SW_SHOWNORMAL);
                    SDL_OpenURL("https://www.facebook.com/phamthanhtung489");
                }
            }
            //nút play
            else if ((x>374&&x<635&&y>576&&y<694)||keyState[SDL_SCANCODE_KP_ENTER])
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
                    inputString="        ";
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
    
    return luaChonCheDo();
}
int luaChonCheDo(){
    nhanvat backgroup(gall,"data/backgrounlogin.png",0,0);
    nhanvat thanhchdo1(gall,"data/nhapthongtin.png",286,300);
    nhanvat thanhchdo2(gall,"data/nhapthongtin.png",286,500);
    Text textso1(gall, "data/KOMIKAX_.ttf", 35,"Catch and Dodge",  { 255, 255, 255,255 },  325, 323);
    Text textso2(gall, "data/KOMIKAX_.ttf", 35,"Coming soon",  { 255, 255, 255,255 },  370, 523);
    bool quit2 = false;
    while (!quit2) {
        SDL_Event event;
        keyState = SDL_GetKeyboardState(NULL);
        while (SDL_PollEvent(&event)) {
            backgroup.updateBeMat(gall);
            thanhchdo1.updateBeMat(gall);
            thanhchdo2.updateBeMat(gall);
            if (event.type == SDL_QUIT) {
                quit2 = true;
                return 0;
            }
            int x, y;
            SDL_GetMouseState(&x, &y);
            //nut 1

            if (x>286&&x<716&&y>301&&y<409)
            {
                textso1.updateBeMatText(gall, "Catch and Dodge",{ 0, 0, 255 });
                textso2.updateBeMatText(gall,"Coming soon",{ 0, 0, 0 });
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    quit2=true;
                    return 1;
                }
            }
            //nút 2
            else if (x>286&&x<716&&y>501&&y<609)
            {
                textso1.updateBeMatText(gall, "Catch and Dodge",{ 0, 0, 0 });
                textso2.updateBeMatText(gall,"Coming soon",{ 0, 0, 255 });
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    quit2=true;
                    return 2;
                }
            }
            else
            {
                textso1.updateBeMatText(gall, "Catch and Dodge",{ 0, 0, 0 });
                textso2.updateBeMatText(gall,"Coming soon",{ 0, 0, 0 });
            }
            
        SDL_UpdateWindowSurface(window);
        }
    }
    return 0;
}
void thoat(){
    // Mix_HaltMusic();
    // Mix_FreeMusic(music);
    // Mix_FreeChunk(soundKichChuot);
    // SDL_DestroyWindow(window);
}


