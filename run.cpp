#include <windows.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <ctime>
const int SCREEN_WIDTH = 800;//rộng
const int SCREEN_HEIGHT = 1000;
bool init();
bool loadMedia();
void close();
int ramdomDiemA();
int randomTruot();
// cua so win
SDL_Window* gWindow = NULL;
SDL_Surface* gALL = NULL;
SDL_Surface* gBackground = NULL;
SDL_Surface* gNhanVatLeft = NULL;
SDL_Surface* gNhanVatRight = NULL;

int main( int argc, char* args[] )
{
	if( !init() )
	{
		std::cout<<( "Không khởi tạo đc\n" );
	}
	else
	{
        if (!loadMedia())
        {
            std::cout<<("Không tải đc\n");
        }
        else
        {
            SDL_Rect ToaDo;
            ToaDo.x = 750;
            ToaDo.y = 580;
            int huongDi=-1; //1- sang trái
                            //1 sang phải
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
						// case SDLK_UP:
						// 	ToaDo.y -= 20;
						// 	break;
						// case SDLK_DOWN:
						// 	ToaDo.y += 20;
						// 	break;

                        //kich thươc nhân vật w=328px
						case SDLK_LEFT:
							ToaDo.x -= 20;
                            if (huongDi==1)
                            {
                                huongDi=-1;
                                ToaDo.x += 348;
                            }
							break;
						case SDLK_RIGHT:
							ToaDo.x += 20;
                            if (huongDi==-1)
                            {
                                huongDi=1;
                                ToaDo.x -=348;
                            }
                            else if (huongDi==-1&&ToaDo.x==0)
                            {
                                ToaDo.x -= 20-328;
                                huongDi=1;
                            }
                            
                            if (ToaDo.x>480)
                            {
                                ToaDo.x=480;
                            }
							break;
                        default:
                            if (huongDi==-1)
                            {
                                ToaDo.x -=1;
                            }
                            else{
                                ToaDo.x +=1;
                            }
						}
                        
                        
                        
					}
                    
                }
                if (huongDi==-1)
                    {
                        ToaDo.x -=1;
                    }
                    else{
                        ToaDo.x +=1;
                    }
                std::cout <<ToaDo.x<<" "<<ToaDo.y<<"\n";
				//Apply the gBackground image
				SDL_BlitSurface(gBackground, NULL, gALL, NULL);
                // trái
				if (huongDi==-1)
                {
                    SDL_BlitSurface(gNhanVatLeft, NULL, gALL, &ToaDo);
                }
                // phải
                else if (huongDi==1)
                {
                    SDL_BlitSurface(gNhanVatRight, NULL, gALL, &ToaDo);

                }
				// Cập nhật
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
	gBackground = IMG_Load( "data/Background.jpg" );
	if( gBackground == NULL )
	{
		std::cout<<( "khong load đc gBackground.", SDL_GetError() );
		check = false;
	}
	//nhan vat di sang bên trái
    gNhanVatLeft = IMG_Load("data/Left.png");
    if (gNhanVatLeft == NULL)
    {
        std::cout<<("khong load đc gNhanVatLeft.", SDL_GetError());
        check = false;
    }
	//nhan vat di sang bên phai
    gNhanVatRight = IMG_Load("data/Right.png");
    if (gNhanVatRight == NULL)
    {
        std::cout<<("khong load đc gNhanVatRight.", SDL_GetError());
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
int randomTruot(const int& x,const int& y){
    //rand ()%(b -a+ 1)+a;    [a,b]
    srand(time(NULL));
    return rand ()%(y-x+ 1)+x;
}

int ramdomDiemA(){
    srand(time(NULL));
    return rand()%1000;
}