#include"login.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    //SDL_Window* window = SDL_CreateWindow("Login", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    //SDL_Surface* surface = SDL_GetWindowSurface(window);

    // SDL_Surface* buttonSurface = IMG_Load("data/xacnhan.png");
    SDL_Rect buttonRect = {100, 100, 200, 30 };
    SDL_BlitSurface(buttonSurface, NULL, surface, &buttonRect);

    SDL_UpdateWindowSurface(window);

    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;
                if (mouseX >= buttonRect.x && mouseX < buttonRect.x + buttonRect.w && mouseY >= buttonRect.y && mouseY < buttonRect.y + buttonRect.h) {
                    // Người dùng nhấn nút, xác nhận đăng nhập ở đây
                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Thông báo", "Đăng nhập thành công!", window);
                }
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
