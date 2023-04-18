#include"manHinhKhoiDong.h"
SDL_Window* window=NULL;
SDL_Renderer* renderer =NULL;
SDL_Surface* backgroundSurface=NULL;
SDL_Texture* backgroundTexture =NULL;
Mix_Music* music=NULL;
Mix_Chunk* soundEffect=NULL;
const int SCREEN_WIDTH = 1000;//1850;//rộng
const int SCREEN_HEIGHT = 800;

bool initFileKhoiDong(){
    // Khởi tạo SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    //Tạo một cửa sổ
    window = SDL_CreateWindow("Start", SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
    // Tạo trình kết xuất cho cửa sổ
    renderer = SDL_CreateRenderer(window, -1, 0);
    backgroundSurface = IMG_Load("anhnenkhoidong.png");
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    music = Mix_LoadMUS("nhacnendotoc.mp3");
    Mix_PlayMusic(music, -1);
    soundEffect = Mix_LoadWAV("07071033.wav");
    return true;
}
void manHinhKhoiDong(){
    initFileKhoiDong();
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                Mix_PlayChannel(-1, soundEffect, 0);
                SDL_Delay(2500);
                quit=true;
            }
        }

        //Vẽ kết cấu nền
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

        //Cập nhật màn hình
        SDL_RenderPresent(renderer);
    }
    Mix_FreeMusic(music);
    Mix_FreeChunk(soundEffect);
    SDL_DestroyTexture(backgroundTexture);
    SDL_FreeSurface(backgroundSurface);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}