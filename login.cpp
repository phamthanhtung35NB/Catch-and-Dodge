/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <exception>
#include <string>
//Screen dimension constants
#include <windows.h>

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cout<<( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 629, 416, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			std::cout<<( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool loadMedia()
{
	//Tải cờ thành công
	bool success = true;

	//Tải hình ảnh giật gân
	gHelloWorld = SDL_LoadBMP( "cong_uet2.bmp" );
	if( gHelloWorld == NULL )
	{
		std::cout<<( "Không thể tải hình ảnh %s!!Lỗi SDL: %s\n", "PHAMTHANHTUNG_22021128", SDL_GetError() );
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int login()
{
	//Start up SDL and create window
	if( !init() )
	{
		std::cout<<( "Không thể khởi tạo!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			std::cout<<( "Không tải phương tiện truyền thông!\n" );
		}
		else
		{
			//Áp dụng hình ảnh
			SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
			
			//Cập nhật bề mặt
			SDL_UpdateWindowSurface( gWindow );

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
		}
	}
	// Sleep( 3000 );
	//system("pouw")
	//Free resources and close SDL
	close();

	return 0;
}