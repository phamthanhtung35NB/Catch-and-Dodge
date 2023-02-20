
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;
void run(){
//Cửa sổ chúng tôi sẽ kết xuất
    SDL_Window* window = NULL;
    
    //Bề mặt chứa bởi cửa sổ
    SDL_Surface* screenSurface = NULL;

    //Khởi tạo SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL không thể khởi tạo!SDL_ERROR: %s\n", SDL_GetError() );
    }
     else
    {
        //Tạo cửa sổ
        window = SDL_CreateWindow( "Pham Thanh Tung 22021128", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Không thể tạo cửa sổ!SDL_ERROR: %s\n", SDL_GetError() );
        }else
        {
            //Nhận bề mặt cửa sổ
            screenSurface = SDL_GetWindowSurface( window );

            //Lấp đầy bề mặt trắng
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format,255, 0, 0xFF ) );
            
            //Cập nhật bề mặt
            SDL_UpdateWindowSurface( window );

            //Hack để có cửa sổ ở lại
            SDL_Event e; 
            bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }//Phá hủy cửa sổ
    SDL_DestroyWindow( window );

    //Thoát khỏi hệ thống con SDL
    SDL_Quit();

}