#include <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
    // Khởi tạo SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Tạo cửa sổ
    SDL_Window* window = SDL_CreateWindow("Đăng nhập", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // Tạo renderer để vẽ trên cửa sổ
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Tạo màu nền cho renderer
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Vẽ màu nền lên renderer
    SDL_RenderClear(renderer);

    // Tạo font cho văn bản
    TTF_Font* font = TTF_OpenFont("arial.ttf", 28);
    if (font == NULL) {
        std::cout << "Không tìm thấy font\n";
        return -1;
    }

    // Tạo văn bản cho tên đăng nhập và mật khẩu
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Tên đăng nhập: ", { 0, 0, 0 });
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = { 50, 100, textSurface->w, textSurface->h };
    SDL_FreeSurface(textSurface);

    SDL_Surface* textSurface1 = TTF_RenderText_Solid(font, "Mật khẩu: ", { 0, 0, 0 });
    SDL_Texture* textTexture1 = SDL_CreateTextureFromSurface(renderer, textSurface1);
    SDL_Rect textRect1 = { 50, 150, textSurface1->w, textSurface1->h };
    SDL_FreeSurface(textSurface1);

    // Tạo hộp văn bản để nhập tên đăng nhập và mật khẩu
    SDL_Rect boxRect = { 200, 100, 200, 30 };
    SDL_Rect boxRect1 = { 200, 150, 200, 30 };
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &boxRect);
    SDL_RenderDrawRect(renderer, &boxRect1);

    // Cập nhật renderer để hiển thị màn hình đăng nhập
    SDL_RenderPresent(renderer);

    // Vòng lặp để xử lý sự kiện
    SDL_Event event;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_RETURN)
                {
                // Kiểm tra thông tin đăng nhập
                std::string username = "admin";
                std::string password = "123456";
                SDL_Surface* surfaceMessage;
                SDL_Texture* Message;
                SDL_Rect Message_rect;
                if (/*nhập tên đăng nhập và mật khẩu của người dùng và so sánh với thông tin lưu trữ*/)
                {
                    std::cout << "Đăng nhập thành công\n";
                    surfaceMessage = TTF_RenderText_Solid(font, "Đăng nhập thành công", { 0, 255, 0 });
                    Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
                    Message_rect = { 50, 200, surfaceMessage->w, surfaceMessage->h };
                }
                else
                {
                    std::cout << "Đăng nhập thất bại\n";
                    surfaceMessage = TTF_RenderText_Solid(font, "Đăng nhập thất bại", { 255, 0, 0 });
                    Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
                    Message_rect = { 50, 200, surfaceMessage->w, surfaceMessage->h };
                }
                SDL_FreeSurface(surfaceMessage);

                // Vẽ thông báo trên renderer
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                SDL_RenderCopy(renderer, textTexture1, NULL, &textRect1);
                SDL_RenderDrawRect(renderer, &boxRect);
                SDL_RenderDrawRect(renderer, &boxRect1);
                SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
                SDL_RenderPresent(renderer);

                // Chờ 2 giây để người dùng đọc thông báo
                SDL_Delay(2000);

                // Xóa thông báo và cập nhật renderer để hiển thị màn hình đăng nhập
                SDL_DestroyTexture(Message);
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                SDL_RenderCopy(renderer, textTexture1, NULL, &textRect1);
                SDL_RenderDrawRect(renderer, &boxRect);
                SDL_RenderDrawRect(renderer, &boxRect1);
                SDL_RenderPresent(renderer);
            }
        }
    }
}

// Giải phóng bộ nhớ và đóng SDL
SDL_DestroyTexture(textTexture);
SDL_DestroyTexture(textTexture1);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

return 0;
}