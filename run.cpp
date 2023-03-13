//#include "erom.h"
#include <windows.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <ctime>
const int SCREEN_WIDTH = 1500;//1850;//rộng
const int SCREEN_HEIGHT = 1000;
bool init();
bool loadMedia();
void close();
int randomDiemA();
int randomTruot();
const int pxDichChuyen = 10;

// std::string garr16Surface[16];
std::string intTostring(int a){
    std::string s;
    a++;
    while (a>0)
    {
        s=char((a%10)+48)+s;
        a/=10;
    }
    return s;
}
// cua so win
SDL_Window* gWindow = NULL;
SDL_Surface* gALL = NULL;
SDL_Surface* gBackground = NULL;
SDL_Surface* gNhanVatLeft = NULL;
SDL_Surface* gNhanVatRight = NULL;
SDL_Surface* garr16Surface1=NULL;
SDL_Surface* garr16Surface2=NULL;
SDL_Surface* garr16Surface3=NULL;
SDL_Surface* garr16Surface4=NULL;
SDL_Surface* garr16Surface5=NULL;
SDL_Surface* garr16Surface6=NULL;
SDL_Surface* garr16Surface7=NULL;
SDL_Surface* garr16Surface8=NULL;
SDL_Surface* garr16Surface9=NULL;
SDL_Surface* garr16Surface10=NULL;
SDL_Surface* garr16Surface11=NULL;
SDL_Surface* garr16Surface12=NULL;
SDL_Surface* garr16Surface13=NULL;
SDL_Surface* garr16Surface14=NULL;
SDL_Surface* garr16Surface15=NULL;
SDL_Surface* garr16Surface16=NULL;
int main( int argc, char* args[] )
{
	if( !init() )
	{
		std::cout<<( "Khong khoi tao duoc.\n" );
	}
	else
	{
        if (!loadMedia())
        {
            std::cout<<("Khong Load duoc.\n");
        }
        else
        {
            SDL_Rect ToaDo;
            ToaDo.x = 750.5;
            ToaDo.y = 580;
            bool huongDiTrai=true;  //true sang trái
                                    //false sang phải
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
						// 	ToaDo.y -= pxDichChuyen;
						// 	break;
						// case SDLK_DOWN:
						// 	ToaDo.y += pxDichChuyen;
						// 	break;

                        //kich thươc nhân vật w=328px
						case SDLK_LEFT:
							ToaDo.x -= pxDichChuyen;
                            if (huongDiTrai==false)
                            {
                                huongDiTrai=true;
                                ToaDo.x += 335;
                            }
							break;
						case SDLK_RIGHT:
							ToaDo.x += pxDichChuyen;
                            if (huongDiTrai==true)
                            {
                                huongDiTrai=false;
                                ToaDo.x -=328;
                            }
                            if (ToaDo.x>480)
                            {
                                ToaDo.x=480;
                            }
                            // else if (huongDiTrai==true&&ToaDo.x==0)
                            // {
                            //     ToaDo.x -= pxDichChuyen-328;
                            //     huongDiTrai=false;
                            // }
                            
                            
							break;
                        default:
                            if (huongDiTrai==true)
                            {
                                ToaDo.x -=0.1;
                            }
                            else{
                                ToaDo.x +=0.1;
                            }
						}
                        
                        
                        
					}
                    
                }
                // if (huongDiTrai==true){
                //     ToaDo.x -=1;
                //     if (ToaDo.x>500)
                //     {
                //         ToaDo.x-=21;
                //     }
                // }
                // else if(huongDiTrai==false){
                //     ToaDo.x +=1;
                //     if (ToaDo.x>480)
                //     {
                //         ToaDo.x=480;
                //     }
                // }
                
                std::cout <<ToaDo.x<<" "<<ToaDo.y<<" "<<huongDiTrai<<"\n";
				//Apply the gBackground image
				SDL_BlitSurface(gBackground, NULL, gALL, NULL);
                // trái
				if (huongDiTrai==true)
                {
                    SDL_BlitSurface(gNhanVatLeft, NULL, gALL, &ToaDo);
                }
                // phải
                else if (huongDiTrai==false)
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
		std::cout<<"SDL_ERROR: \n"<<SDL_GetError();
		check = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			std::cout<<( "Window could not be created! SDL_Error:\n", SDL_GetError() );
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
		std::cout<<( "Khong load duoc anh Background.\n");
		check = false;
	}
	//nhan vat di sang bên trái
    gNhanVatLeft = IMG_Load("data/Left.png");
    if (gNhanVatLeft == NULL)
    {
        std::cout<<("Khong load duoc anh NhanVatLeft.\n", SDL_GetError());
        check = false;
    }
	//nhan vat di sang bên phai
    gNhanVatRight = IMG_Load("data/Right.png");
    if (gNhanVatRight == NULL)
    {
        std::cout<<("Khong load duoc anh NhanVatRight.\n", SDL_GetError());
        check = false;
    }
    garr16Surface1=IMG_Load("data/right1.png");
    garr16Surface2=IMG_Load("data/right2.png");
    garr16Surface3=IMG_Load("data/right3.png");
    garr16Surface4=IMG_Load("data/right4.png");
    garr16Surface5=IMG_Load("data/right5.png");
    garr16Surface6=IMG_Load("data/right6.png");
    garr16Surface7=IMG_Load("data/right7.png");
    garr16Surface8=IMG_Load("data/right8.png");
    garr16Surface9=IMG_Load("data/right9.png");
    garr16Surface10=IMG_Load("data/right10.png");
    garr16Surface11=IMG_Load("data/right11.png");
    garr16Surface12=IMG_Load("data/right12.png");
    garr16Surface13=IMG_Load("data/right13.png");
    garr16Surface14=IMG_Load("data/right14.png");
    garr16Surface15=IMG_Load("data/right15.png");
    garr16Surface16=IMG_Load("data/right16.png");


    if (garr16Surface1==NULL||garr16Surface2==NULL||garr16Surface3==NULL||garr16Surface4==NULL||garr16Surface5==NULL||garr16Surface6==NULL||garr16Surface7==NULL||garr16Surface8==NULL)
    {
        std::cout<<("Khong load duoc anh NhanVat arr16.\n", SDL_GetError());
        check = false;
    }
    if (garr16Surface9==NULL||garr16Surface10==NULL||garr16Surface11==NULL||garr16Surface12==NULL||garr16Surface13==NULL||garr16Surface14==NULL||garr16Surface15==NULL||garr16Surface16==NULL)
    {
        std::cout<<("Khong load duoc anh NhanVat arr16.\n", SDL_GetError());
        check = false;
    }    
    // }
    
    
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

int randomDiemA(){
    srand(time(NULL));
    return rand()%1000;
}

int randomTruot()
{
    return 0;
}
