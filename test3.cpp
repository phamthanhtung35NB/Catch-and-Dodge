#include <SDL2/SDL.h>
#include <cstdio>
#include <SDL2/SDL_image.h>
int main(int argc, char* argv[]) {
    // Khởi tạo SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Không thể khởi tạo SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Tạo cửa sổ
    SDL_Window* window = SDL_CreateWindow("Đăng nhập game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Không thể tạo cửa sổ: %s\n", SDL_GetError());
        return 1;
    }

    // Tạo renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Không thể tạo renderer: %s\n", SDL_GetError());
        return 1;
    }

    // Load ảnh nền
    SDL_Surface* backgroundSurface = IMG_Load("background.jpg");
    if (backgroundSurface == NULL) {
        printf("Không thể load ảnh nền: %s\n", SDL_GetError());
        return 1;
    }

    // Chuyển đổi ảnh nền thành texture
    SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    if (backgroundTexture == NULL) {
        printf("Không thể tạo texture: %s\n", SDL_GetError());
        return 1;
    }

    // Xoá ảnh nền từ bộ nhớ
    SDL_FreeSurface(backgroundSurface);

    // Vòng lặp chính
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        // Xử lý sự kiện
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Vẽ ảnh nền lên renderer
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

        // Cập nhật renderer
        SDL_RenderPresent(renderer);
    }

    // Giải phóng texture
    SDL_DestroyTexture(backgroundTexture);

    // Giải phóng renderer và cửa sổ
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Đóng SDL
    SDL_Quit();

    return 0;
}
