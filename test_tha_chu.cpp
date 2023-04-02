#include <iostream>
#include <fstream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    if (TTF_Init() == -1)
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Display Text File", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) 
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    // if (argc < 2)
    // {
    //     std::cout << "file" << std::endl;
    //     return 1;
    // }
    std::string filename = "data/dataLuuTam.txt";//argv[1];

    std::ifstream input_file(filename);


    std::vector<std::string> lines;
    std::string line;
    while (getline(input_file, line))
    {
        lines.push_back(line);
    }

    TTF_Font* font = TTF_OpenFont("arial.ttf", 24);
    if (!font) 
    {
        std::cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return 1;
    }
    SDL_Color textColor = { 255, 255, 255};
    int y = 0;
    int x = 640 / 2;
    for (std::string line : lines)
    {    
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, line.c_str(), textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);

        SDL_Rect textRect;
        textRect.x = x;
        textRect.y = y;
        textRect.w = textSurface->w;
        textRect.h = textSurface->h;

        SDL_RenderCopy(renderer, texture, NULL, &textRect);

        y += textSurface->h + 10;

        SDL_DestroyTexture(texture);
        SDL_FreeSurface(textSurface);
    }

    // Hiển thị các từ ra màn hình
    SDL_RenderPresent(renderer);

    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_CloseFont(font);
    TTF_Quit();

    SDL_Quit();
    return 0;
}
