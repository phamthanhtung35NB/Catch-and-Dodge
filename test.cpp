#include <windows.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

const int SCREEN_WIDTH = 800;//rộng
const int SCREEN_HEIGHT = 1000;

bool init();

bool loadMedia();

void close();

// cua so win
SDL_Window* gWindow = NULL;
	
// Bề mặt chứa bởi cửa sổ
SDL_Surface* gALL = NULL;

//The image we will load and show on the screen
SDL_Surface* gBackground = NULL;
SDL_Surface* gNhanVatLeft = NULL;
SDL_Surface* gNhanVatRight = NULL;
SDL_Rect characterRect;
characterRect.x = 500;
characterRect.y = 580;
int main( int argc, char* args[] )
{
	// Start up SDL and create window
	if( !init() )
	{
		std::cout<<( "Không thể khởi tạo!\n" );
	}
	else
	{
		//Load media
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            //Apply the character image
            
            

            //Hack to get window to stay up
            SDL_Event e;
            bool quit = false;
            while (quit == false)
            {
                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT)
            			quit = true;
					else if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							characterRect.y -= 10;
							break;
						case SDLK_DOWN:
							characterRect.y += 10;
							break;
						case SDLK_LEFT:
							characterRect.x -= 10;
							break;
						case SDLK_RIGHT:
							characterRect.x += 10;
							break;
						}
					}
                }
				//Apply the gBackground image
				SDL_BlitSurface(gBackground, NULL, gALL, NULL);
				SDL_BlitSurface(gNhanVatLeft, NULL, gALL, &characterRect);

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
            }
		}
	
	}

	close();

	return 0;
}
bool init()
{
	//Initialization flag
	bool check = true;

	//Khởi tạo SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cout<<"SDL không thể khởi tạo!SDL_ERROR: \n"<<SDL_GetError();
		check = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			std::cout<<( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			check = false;
		}
		else
		{
			//Get window surface
			gALL = SDL_GetWindowSurface( gWindow );
		}
	}

	return check;
}

bool loadMedia()
{
	bool check = true;

	// gBackground
	gBackground = IMG_Load( "data/gBackground.jpg" );
	if( gBackground == NULL )
	{
		std::cout<<( "khong load đc gBackground.", SDL_GetError() );
		check = false;
	}
	//nhan vat di sang bên trái
    gNhanVatLeft = IMG_Load("data/Left.png");
    if (gNhanVatLeft == NULL)
    {
        printf("khong load đc gNhanVatLeft.", SDL_GetError());
        check = false;
    }
	//nhan vat di sang bên phai
    gNhanVatRight = IMG_Load("data/Right.png");
    if (gNhanVatRight == NULL)
    {
        printf("khong load đc gNhanVatRight.", SDL_GetError());
        check = false;
    }
	return check;
}
void close()
{
	//Deallocate surface
	SDL_FreeSurface( gBackground );
	gBackground = NULL;
    
    //
    SDL_FreeSurface(gNhanVatLeft);
    gNhanVatLeft = NULL;

    SDL_FreeSurface(gNhanVatRight);
    gNhanVatRight = NULL;
	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}