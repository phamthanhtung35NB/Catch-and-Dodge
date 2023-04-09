#include"khoitao.h"


const int SCREEN_WIDTH = 1850;//1850;//rộng
const int SCREEN_HEIGHT = 1000;
const int pxDichChuyen = 10;
// cua so win
SDL_Window* gWindow = NULL;
SDL_Surface* gALL = NULL;

double timecu=0;
std::ifstream infile("dataLuuTam.txt");
std::vector<std::string> lineVecToTrue={};
std::vector<std::string> lineVecToFalse={};
int soLuong;//số lượng vật phẩm đang có trên màn hình
bool arrTrueFalse[5]{
    arrTrueFalse[0]=false,
    arrTrueFalse[1]=false,
    arrTrueFalse[2]=false,
    arrTrueFalse[3]=false,
    arrTrueFalse[4]=false
};//vvật phẩm nài còn trên màn hình
bool init(){
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        std::cout<<"SDL_ERROR: \n"<<SDL_GetError();
        return false;
    }
	if (TTF_Init()<0)
    {
        return false;
    }
    gWindow = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN );
	if( gWindow == NULL ){
        std::cout<<( "Window could not be created! SDL_Error:\n", SDL_GetError() );
        return false;
    }
    gALL = SDL_GetWindowSurface( gWindow );
    return true;
}

void khongCheVatPham(){
}

int main( int argc, char* args[] )
{
    if (!init())
    {
        std::cout<<"khong the khoi tao.";   
        return 1;
    }
    nhanvat bia[5]{
        nhanvat(gALL,"bom.png",0,0),
        nhanvat(gALL,"bianho.png",0,0),
        nhanvat(gALL,"bianho.png",0,0),
        nhanvat(gALL,"bianho.png",0,0),
        nhanvat(gALL,"bianho.png",0,0)
    };
    nhanvat gBackgroundphu(gALL,"nenphu.png",1500,0);
    nhanvat gBackground(gALL,"anhnenchuan.png",0,0);
    nhanvat NhanVatLeft(gALL,"data/Left.png",750,580);
    nhanvat NhanVatRight(gALL,"data/Right.png",750,580);
    bool huongDiTrai=true;  //true sang trái
                            //false sang phải
    SDL_Event e;
    bool quit = false;
    // Xóa bộ đệm hiển thị
    // SDL_FillRect(ga, NULL, SDL_MapRGB(textSurface->format, 0x00, 0x00, 0x00));

    double x=ranDom();
    // while (x==timecu)
    // {
    //     x=ranDom();
    // }
    SDL_Delay(1207);
    timecu=x;
    std::cout<<x;
    bia[0].updateToaDoX(x);
    
    while (quit == false)
    {
        while (SDL_PollEvent(&e))
        // if (SDL_PollEvent(&e))
        {
            
            if (e.type == SDL_QUIT)quit = true;
            else if(e.key.keysym.sym== SDLK_LEFT){
                if (huongDiTrai==false){
                    huongDiTrai=true;
                    NhanVatLeft.updateToaDoX(NhanVatRight.returnToaDoX()+330);
                }
                else{
                NhanVatLeft.updateToaDoX(NhanVatLeft.returnToaDoX()-pxDichChuyen);
                }
            }
            else if(e.key.keysym.sym==SDLK_RIGHT){
                if (huongDiTrai==true){
                    huongDiTrai=false;
                    NhanVatRight.updateToaDoX(NhanVatLeft.returnToaDoX()-330);
                }
                else{
                    NhanVatRight.updateToaDoX(NhanVatRight.returnToaDoX()+pxDichChuyen);
                }
            }
        }
        //Apply the gBackground image
        gBackgroundphu.updateBeMat(gALL);
        gBackground.updateBeMat(gALL);
        // trái
        if (huongDiTrai==true)
        {
            // NhanVatLeft.updateToado(NhanVatLeft.returnToaDoX()-2);
            NhanVatLeft.updateBeMat(gALL);
        }
        // phải
        else if (huongDiTrai==false)
        {
            // NhanVatRight.updateToado(NhanVatRight.returnToaDoX()+2);
            if (NhanVatRight.returnToaDoX()>1180)
            {
                NhanVatRight.updateToaDoX(1180);
            }
            NhanVatRight.updateBeMat(gALL);
        }
        if (((NhanVatLeft.returnToaDoX()==bia[0].returnToaDoX()) && (bia[0].returnToaDoY()<800))||((NhanVatRight.returnToaDoX()==bia[0].returnToaDoX()) && (bia[0].returnToaDoY()<800)))
        {
            bia[0].updateToaDoX(ranDom());
            bia[0].updateToaDoY(1);
        }
        
    if (bia[0].returnToaDoY()>1000)
    {
        bia[0].updateToaDoX(ranDom());
        bia[0].updateToaDoY(1);
    }
        bia[0].updateToaDoY(bia[0].returnToaDoY()+1);
        
        
        for (int i = 0; i < 5; i++)
        {   
            bia[i].updateBeMat(gALL);
        }
        

    // Cập nhật
    SDL_UpdateWindowSurface(gWindow);
    SDL_FillRect(gALL, NULL, SDL_MapRGB(gALL->format, 0x00, 0x00, 0x00));
    // SDL_Delay(50);
    }
	// close();100/3
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
