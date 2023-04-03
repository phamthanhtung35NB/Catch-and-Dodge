// #include "erom.h"
#include "vatpham.h"
#include"nhanvat.h"
// #include <windows.h>
// #include <string>
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
// #include <iostream>
// #include <ctime>
const int SCREEN_WIDTH = 1850;//1850;//rộng
const int SCREEN_HEIGHT = 1000;

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

int main( int argc, char* args[] )
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){std::cout<<"SDL_ERROR: \n"<<SDL_GetError();}
	gWindow = SDL_CreateWindow( "game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN );
	if( gWindow == NULL ){std::cout<<( "Window could not be created! SDL_Error:\n", SDL_GetError() );}
    gALL = SDL_GetWindowSurface( gWindow );
    nhanvat gBackground(gALL,"data/Backgroundfull.png",NULL,NULL);
    nhanvat gNhanVatLeft(gALL,"data/Left.png",750,580);
    nhanvat gNhanVatRight(gALL,"data/Right.png",750,580);
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
                case SDLK_LEFT:
                    // ToaDo.x -= pxDichChuyen;
                    if (huongDiTrai==false)
                    {
                        huongDiTrai=true;
                        gNhanVatLeft.updateToado(gNhanVatLeft.returnToaDoXY+=328);
                        // ToaDo.x += 335;
                    }
                    break;
                case SDLK_RIGHT:
                    // ToaDo.x += pxDichChuyen;
                    if (huongDiTrai==true)
                    {
                        huongDiTrai=false;
                        gNhanVatRight.updateToado(gNhanVatRight.returnToaDoXY-=328);
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
                        gNhanVatRight.updateToado(gNhanVatRight.returnToaDoXY-=1);
                    }
                    else{
                        gNhanVatLeft.updateToado(gNhanVatLeft.returnToaDoXY+=1);
                    }
                }
                
                
                
            }
            
        }
                
                // std::cout <<ToaDo.x<<" "<<ToaDo.y<<" "<<huongDiTrai<<"\n";
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
		
	
// }

	// close();

	return 0;
}

// void close()
// {
// 	//Deallocate surface
// 	SDL_FreeSurface( gBackground );
// 	gBackground = NULL;
    
//     //
//     SDL_FreeSurface(gNhanVatLeft);
//     gNhanVatLeft = NULL;

//     SDL_FreeSurface(gNhanVatRight);
//     gNhanVatRight = NULL;
// 	//Destroy window
// 	SDL_DestroyWindow( gWindow );
// 	gWindow = NULL;

// 	//Quit SDL subsystems
// 	SDL_Quit();
// }
// int randomTruot(const int& x,const int& y){
//     //rand ()%(b -a+ 1)+a;    [a,b]
//     srand(time(NULL));
//     return rand ()%(y-x+ 1)+x;
// }

// int randomDiemA(){
//     srand(time(NULL));
//     return rand()%1000;
// }

// int randomTruot()
// {
//     return 0;
// }
