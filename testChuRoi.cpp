#include <iostream>
#include <fstream>
#include <string>
#include <SDL2/SDL.h>

#include <SDL2/SDL_ttf.h>

const int SCREEN_WIDTH = 1040;
const int SCREEN_HEIGHT = 1080;
SDL_Surface* textSurface =NULL;
TTF_Font* font=NULL;
SDL_Rect spriteRect;
        spriteRect.x = 0;
        spriteRect.y = 0;
        spriteRect.w = 735;
        spriteRect.h = 735;
int main(int argc, char* argv[])
{
                lai:
    // Khởi tạo SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Khong the khoi tao SDL: " << SDL_GetError() << std::endl;
        return 1;
    }
    TTF_Init();
    // Tạo cửa sổ hiển thị
    SDL_Window* window = SDL_CreateWindow("Tha tung dong tren man hinh", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        std::cout << "Khong the tao cua so hien thi: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 2;
    }

    // Tạo surface để vẽ lên
    SDL_Surface* surface = SDL_GetWindowSurface(window);

    // Mở file và đọc từng dòng
    std::ifstream infile("dataLuuTam.txt");

    if(infile.is_open())
    {
        std::string line;

        while(getline(infile,line))
        {
            // Xóa bộ đệm hiển thị
            SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));

            // Thêm văn bản vào surface
            SDL_Color textColor = { 0xFF, 0xFF, 0xFF };
            font =TTF_OpenFont("data/arial.ttf", 50);
            textSurface = TTF_RenderText_Solid(font, line.c_str(), textColor);

            // Vẽ surface lên cửa sổ hiển thị
            SDL_Rect textRect = { (SCREEN_WIDTH - textSurface->w) / 2, (SCREEN_HEIGHT - textSurface->h) / 2, textSurface->w, textSurface->h };
            SDL_BlitSurface(textSurface, NULL, surface, &textRect);

            // Cập nhật màn hình
            SDL_UpdateWindowSurface(window);

            // Giữ cửa sổ đóng trong vòng 1 giây
            SDL_Delay(100);

            // Giải phóng surface chứa văn bản
            SDL_FreeSurface(textSurface);
        }
        infile.close();
    }
    else
    {
        std::cout << "Khong the mo file de doc." << std::endl;
        SDL_FreeSurface(surface);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }

    // Đóng cửa sổ và thoát SDL
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    goto lai;
    SDL_Quit();
    return 0;
}
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>

// const int SCREEN_WIDTH = 1040;
// const int SCREEN_HEIGHT = 1080;

// int main(int argc, char* argv[])
// {
//     // Khởi tạo SDL
//     if(SDL_Init(SDL_INIT_VIDEO) < 0)
//     {
//         std::cout << "Khong the khoi tao SDL: " << SDL_GetError() << std::endl;
//         return 1;
//     }
//     TTF_Init();
//     // Tạo cửa sổ hiển thị
//     SDL_Window* window = SDL_CreateWindow("Tha tung dong tren man hinh", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//     if(window == NULL)
//     {
//         std::cout << "Khong the tao cua so hien thi: " << SDL_GetError() << std::endl;
//         SDL_Quit();
//         return 2;
//     }

//     // Tạo renderer để vẽ lên
//     SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

//     // Mở file và đọc từng dòng
//     std::ifstream infile("dataLuuTam.txt");

//     if(infile.is_open())
//     {
//         std::string line;

//         while(getline(infile,line))
//         {
//             // Xóa bộ đệm hiển thị
//             SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
//             SDL_RenderClear(renderer);

//             // Thêm văn bản vào renderer
//             SDL_Color textColor = { 0xFF, 0xFF, 0xFF };
//             TTF_Font* font =TTF_OpenFont("data/arial.ttf", 50);
//             if (font==NULL)
//             {
//                 std::cout<<"ko có phông";
//             }

//             SDL_Surface* textSurface = TTF_RenderText_Solid(font, line.c_str(), textColor);
//             if(textSurface == NULL)
//             {
//                 std::cout << "Khong the tao surface hien thi van ban: " << SDL_GetError() << std::endl;
//                 infile.close();
//                 SDL_DestroyRenderer(renderer);
//                 SDL_DestroyWindow(window);
//                 SDL_Quit();
//                 return 3;
//             }

//             SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
//             if(texture == NULL)
//             {
//                 std::cout << "Khong the tao texture hien thi van ban: " << SDL_GetError() << std::endl;
//                 SDL_FreeSurface(textSurface);
//                 infile.close();
//                 SDL_DestroyRenderer(renderer);
//                 SDL_DestroyWindow(window);
//                 SDL_Quit();
//                 return 4;
//             }

//             // Lấy kích thước của văn bản để căn giữa trên màn hình
//             int text_width, text_height;
//             SDL_QueryTexture(texture, NULL, NULL, &text_width, &text_height);
//             SDL_Rect textRect = { (SCREEN_WIDTH - text_width) / 2, (SCREEN_HEIGHT - text_height) / 2, text_width, text_height };

//             // Vẽ texture lên renderer
//             SDL_RenderCopy(renderer, texture, NULL, &textRect);

//             // Cập nhật màn hình
//             SDL_RenderPresent(renderer);

//             // Giữ cửa sổ đóng trong vòng 1 giây
//             SDL_Delay(1000);

//             // Giải phóng surface và texture chứa văn bản
//             SDL_FreeSurface(textSurface);
//             SDL_DestroyTexture(texture);
//         }
//         infile.close();
//     }
//     else
//     {
//         std::cout << "Khong the mo file de doc." << std::endl;
//         SDL_DestroyRenderer(renderer);
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//         return 5;
//     }

//     // Đóng renderer, cửa sổ và thoát SDL
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     TTF_Quit();
//     SDL_Quit();
//     return 0;
// }
