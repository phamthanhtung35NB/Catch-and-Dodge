#include"khoitao.h"


const int SCREEN_WIDTH = 1850;//1850;//rộng
const int SCREEN_HEIGHT = 1000;

const int pxDichChuyen = 5;
// cua so win
SDL_Window* gWindow = NULL;
SDL_Surface* gALL = NULL;

int main( int argc, char* args[] )
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){std::cout<<"SDL_ERROR: \n"<<SDL_GetError();}
	
    gWindow = SDL_CreateWindow( "game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN );
	if( gWindow == NULL ){std::cout<<( "Window could not be created! SDL_Error:\n", SDL_GetError() );}
    gALL = SDL_GetWindowSurface( gWindow );

    TTF_Init();
    SDL_Renderer* renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    nhanvat gBackground(gALL,"data/Backgroundfull.png",0,0);
    nhanvat NhanVatLeft(gALL,"data/Left.png",750,580);
    nhanvat NhanVatRight(gALL,"data/Right.png",750,580);
    bool huongDiTrai=true;  //true sang trái
                            //false sang phải
    SDL_Event e;
    bool quit = false;
    while (quit == false)
    {
        // while (SDL_PollEvent(&e))
        if (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)quit = true;
            else if(e.key.keysym.sym== SDLK_LEFT){
                if (huongDiTrai==false){
                    huongDiTrai=true;
                    NhanVatLeft.updateToado(NhanVatRight.returnToaDoX()+330);
                }
                else{
                NhanVatLeft.updateToado(NhanVatLeft.returnToaDoX()-pxDichChuyen);
                }
            }
            else if(e.key.keysym.sym==SDLK_RIGHT){
                if (huongDiTrai==true){
                    huongDiTrai=false;
                    NhanVatRight.updateToado(NhanVatLeft.returnToaDoX()-330);
                }
                else{
                    NhanVatRight.updateToado(NhanVatRight.returnToaDoX()+pxDichChuyen);
                }
            }
        }
        //Apply the gBackground image
        gBackground.updateBeMat(gALL);
        // trái
        if (huongDiTrai==true)
        {
            NhanVatLeft.updateToado(NhanVatLeft.returnToaDoX()-1);
            NhanVatLeft.updateBeMat(gALL);
        }
        // phải
        else if (huongDiTrai==false)
        {
            NhanVatRight.updateToado(NhanVatRight.returnToaDoX()+1);
            if (NhanVatRight.returnToaDoX()>1180)
            {
                NhanVatRight.updateToado(1180);
            }
            NhanVatRight.updateBeMat(gALL);
        }
    // Cập nhật
    SDL_UpdateWindowSurface(gWindow);
    }
	// close();
	return 0;
}

// void close()
// {
// 	//Deallocate surface
// 	SDL_FreeSurface( gBackground );
// 	gBackground = NULL;
    
//     //
//     SDL_FreeSurface(NhanVatLeft);
//     NhanVatLeft = NULL;

//     SDL_FreeSurface(NhanVatRight);
//     NhanVatRight = NULL;
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
