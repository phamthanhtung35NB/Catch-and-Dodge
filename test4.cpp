#include <SDL2/SDL.h>
#include <cstdio>
#include<iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
char* input = new char[100];
std::string text;
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

    // Tạo font chữ
    TTF_Font* font = TTF_OpenFont("arial.ttf", 28);
    if (font == NULL) {
        printf("Không thể tạo font chữ: %s\n", SDL_GetError());
        return 1;
    }

    // Tạo màu chữ
    SDL_Color textColor = { 255, 255, 255 };

    // Tạo ô nhập tài khoản
    SDL_Rect accountInputRect = { 240, 200, 200, 40 };
    SDL_Surface* accountInputSurface = SDL_CreateRGBSurface(0, accountInputRect.w, accountInputRect.h, 32, 0, 0, 0, 0);
    SDL_FillRect(accountInputSurface, NULL, SDL_MapRGB(accountInputSurface->format, 0, 0, 0));
    SDL_Texture* accountInputTexture = SDL_CreateTextureFromSurface(renderer, accountInputSurface);
    SDL_FreeSurface(accountInputSurface);

    // Tạo ô nhập mật khẩu
    SDL_Rect passwordInputRect = { 240, 250, 200, 40 };
    SDL_Surface* passwordInputSurface = SDL_CreateRGBSurface(0, passwordInputRect.w, passwordInputRect.h, 32, 0, 0, 0, 0);
    SDL_FillRect(passwordInputSurface, NULL,  SDL_MapRGB(passwordInputSurface->format, 0, 0, 0));
    //SDL_FillRect(passwordInputSurface, NULL, SDL_MapRGB(passwordInputSurface->format, 0, 0, 0));
    SDL_Texture* passwordInputTexture = SDL_CreateTextureFromSurface(renderer, passwordInputSurface);
    SDL_FreeSurface(passwordInputSurface);
    // Vòng lặp game
    bool quit = false;
    while (!quit) {
        // Xử lý sự kiện
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    // Xử lý phím nhấn
                    switch (event.key.keysym.sym) {
                        case SDLK_RETURN:
                            // Xử lý đăng nhập
                            std::string account = ""; // Lưu tên đăng nhập
                            std::string password = ""; // Lưu mật khẩu
                            // Lấy thông tin từ ô nhập tài khoản
                            char* accountInput = new char[100];
                            SDL_SetTextInputRect(accountInput, 100);
                            // SDL_SetTextInputRect(accountInput, sizeof(accountInput));
                            account = accountInput;
                            delete[] accountInput;
                            // Lấy thông tin từ ô nhập mật khẩu
                            char* passwordInput = new char[100];
                            SDL_SetTextInputRect(passwordInput, 100);
                            password = passwordInput;
                            delete[] passwordInput;
                            // Kiểm tra thông tin đăng nhập
                            if (account == "admin" && password == "123456") {
                                printf("Đăng nhập thành công\n");
                            } else {
                                printf("Đăng nhập thất bại\n");
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_TEXTINPUT:
                    // Xử lý nhập liệu từ bàn phím
                    SDL_Rect inputRect;
                    if (SDL_HasIntersection(&event.edit.selection, &accountInputRect)) {
                        inputRect = accountInputRect;
                    } else if (SDL_HasIntersection(&event.edit.selection, &passwordInputRect)) {
                        inputRect = passwordInputRect;
                    } else {
                        break;
                    }


                    SDL_SetTextInputRect(input, 100);
                    text = input;
                    delete[] input;
                    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), textColor);
                    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
                    SDL_FreeSurface(surface);
                    SDL_RenderCopy(renderer, texture, NULL, &inputRect);
                    SDL_DestroyTexture(texture);
                    break;
                default:
                    break;
            }
        }

        // Vẽ ảnh nền
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

        // Vẽ ô nhập tài khoản
        SDL_RenderCopy(renderer, accountInputTexture, NULL, &accountInputRect);

        // Vẽ ô nhập mật khẩu
        SDL_RenderCopy(renderer, passwordInputTexture, NULL, &passwordInputRect);

        // Hiển thị lên màn hình
        SDL_RenderPresent(renderer);
    }

    // Giải phóng bộ nhớ và thoát
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(accountInputTexture);
    SDL_DestroyTexture(passwordInputTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    SDL_Quit();
    return 0;
}