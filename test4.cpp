#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

int main(int argc, char* argv[]) {
    // Khởi tạo SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Không thể khởi tạo SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Khởi tạo SDL_ttf
    if (TTF_Init() < 0) {
        printf("Không thể khởi tạo SDL_ttf: %s\n", TTF_GetError());
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

    // Load font
    TTF_Font* font = TTF_OpenFont("data/arial.ttf", 24);
    if (font == NULL) {
        printf("Không thể load font: %s\n", TTF_GetError());
        return 1;
    }

    // Tạo surface và texture cho các vùng nhập liệu
    SDL_Surface* usernameSurface = TTF_RenderText_Solid(font, "Tên đăng nhập:", {255, 255, 255});
    SDL_Surface* passwordSurface = TTF_RenderText_Solid(font, "Mật khẩu:", {255, 255, 255});
    SDL_Texture* usernameTexture = SDL_CreateTextureFromSurface(renderer, usernameSurface);
    SDL_Texture* passwordTexture = SDL_CreateTextureFromSurface(renderer, passwordSurface);

    SDL_Surface* usernameInputSurface ;
    SDL_Surface* passwordInputSurface ;
    SDL_Texture* usernameInputTexture ;
    SDL_Texture* passwordInputTexture ;
    SDL_Rect usernameInputRect ;
    SDL_Rect passwordInputRect ;

    // Xoá surface từ bộ nhớ
    // SDL_FreeSurface(usernameSurface);
    // SDL_FreeSurface(passwordSurface);

    // Vị trí của các vùng nhập liệu
    SDL_Rect usernameRect = {100, 200, 200, 30};
    SDL_Rect passwordRect = {100, 250, 200, 30};

    // Dữ liệu đang nhập vào các vùng nhập liệu
    std::string username = "";
    std::string password = "";

    // Vòng lặp chính
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        // Xử lý sự kiện
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            if (event.type == SDL_TEXTINPUT) {
                // Nếu có sự kiện nhập liệu
                if (usernameRect.x <= event.text.text[0] && event.text.text[0] <= usernameRect.x + usernameRect.w &&
                    usernameRect.y <= event.text.text[1] && event.text.text[1] <= usernameRect.y + usernameRect.h) {
                    username += event.text.text;
                } else if (passwordRect.x <= event.text.text[0] && event.text.text[0] <= passwordRect.x + passwordRect.w &&
                    passwordRect.y <= event.text.text[1] && event.text.text[1] <= passwordRect.y + passwordRect.h) {
                    password += event.text.text;
                }
            }
            else if (event.type == SDL_KEYDOWN) {
                // Nếu có sự kiện ấn phím
                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    // Nếu ấn phím backspace, xóa ký tự cuối cùng của dữ liệu đang nhập
                    if (!username.empty() &&
                        (usernameRect.x <= event.text.text[0] && event.text.text[0] <= usernameRect.x + usernameRect.w &&
                            usernameRect.y <= event.text.text[1] && event.text.text[1] <= usernameRect.y + usernameRect.h)) {
                        username.pop_back();
                    } else if (!password.empty() &&
                        (passwordRect.x <= event.text.text[0] && event.text.text[0] <= passwordRect.x + passwordRect.w &&
                            passwordRect.y <= event.text.text[1] && event.text.text[1] <= passwordRect.y + passwordRect.h)) {
                        password.pop_back();
                    }
                }
            }
        // }
        // Xoá toàn bộ renderer
        SDL_RenderClear(renderer);


        SDL_RenderCopy(renderer, usernameTexture, NULL, &usernameRect);
        SDL_RenderCopy(renderer, passwordTexture, NULL, &passwordRect);


        // Vẽ dữ liệu đang nhập lên renderer
        usernameInputSurface = TTF_RenderText_Solid(font, username.c_str(), {255, 255, 255});
        passwordInputSurface = TTF_RenderText_Solid(font, password.c_str(), {255, 255, 255});
        usernameInputTexture = SDL_CreateTextureFromSurface(renderer, usernameInputSurface);
        passwordInputTexture = SDL_CreateTextureFromSurface(renderer, passwordInputSurface);
        usernameInputRect = {300, 200, usernameInputSurface->w, usernameInputSurface->h};
        passwordInputRect = {300, 250, passwordInputSurface->w, passwordInputSurface->h};
        SDL_RenderCopy(renderer, usernameInputTexture, NULL, &usernameInputRect);
        SDL_RenderCopy(renderer, passwordInputTexture, NULL, &passwordInputRect);
       
        SDL_FreeSurface(usernameSurface);
        SDL_FreeSurface(passwordSurface);
        SDL_DestroyTexture(usernameTexture);
        SDL_DestroyTexture(passwordTexture);

        // Vẽ renderer ra màn hình
        SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(window);
        // Chờ 16ms để cho frame tiếp theo
        // SDL_Delay(166);


        // // Vẽ các vùng nhập liệu lên renderer
        // SDL_RenderCopy(renderer, usernameTexture, NULL, &usernameRect);
        // SDL_RenderCopy(renderer, passwordTexture, NULL, &passwordRect);

        // // Vẽ dữ liệu đang nhập lên renderer
        // SDL_Surface* usernameInputSurface = TTF_RenderText_Solid(font, username.c_str(), {255, 255, 255});
        // SDL_Surface* passwordInputSurface = TTF_RenderText_Solid(font, password.c_str(), {255, 255, 255});
        // SDL_Texture* usernameInputTexture = SDL_CreateTextureFromSurface(renderer, usernameInputSurface);
        // SDL_Texture* passwordInputTexture = SDL_CreateTextureFromSurface(renderer, passwordInputSurface);
        // SDL_Rect usernameInputRect = {300, 200, usernameInputSurface->w, usernameInputSurface->h};
        // SDL_Rect passwordInputRect = {300, 250, passwordInputSurface->w, passwordInputSurface->h};
        // SDL_RenderCopy(renderer, usernameInputTexture, NULL, &usernameInputRect);
        // SDL_RenderCopy(renderer, passwordInputTexture, NULL, &passwordInputRect);
        // SDL_FreeSurface(usernameInputSurface);
        // SDL_FreeSurface(passwordInputSurface);
        // SDL_DestroyTexture(usernameInputTexture);
        // SDL_DestroyTexture(passwordInputTexture);

        // // Vẽ renderer lên cửa sổ
        // SDL_RenderPresent(renderer);
        }
    }
    // Giải phóng tài nguyên,các resource đã sử dụng
    SDL_DestroyTexture(usernameTexture);
    SDL_DestroyTexture(passwordTexture);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
