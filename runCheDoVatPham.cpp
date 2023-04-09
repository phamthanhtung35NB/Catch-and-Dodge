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
    int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags)){
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                return false;
            }
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
    SDL_Rect toadotamthoi{100,600};
    SDL_Rect sizeCat;
        sizeCat.x = 0;
        sizeCat.y = 0;
        sizeCat.w = 300;
        sizeCat.h = 300;
        // SDL_Surface* nhanvatll=IMG_Load("nhanvatRnho.png");
    // nhanvat gBackgroundphu(gALL,"nenphu.png",1500,0);
    nhanvat gBackground(gALL,"anhnenchuan.png",0,0);
    nhanvat NhanVatLeft(gALL,"nhanvatLnho.png",750,600);
    nhanvat NhanVatRight(gALL,"nhanvatRnho.png",750,600);
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

    bia[0].updateToaDoX(x);
    
    while (quit == false)
    {
        // Xóa màn hình
            SDL_FillRect(gALL, NULL, SDL_MapRGB(gALL->format, 0xFF, 0xFF, 0xFF));
        while (SDL_PollEvent(&e))
        // if (SDL_PollEvent(&e))
        {
            
            if (e.type == SDL_QUIT)quit = true;
            else if(e.key.keysym.sym== SDLK_LEFT){
                if (huongDiTrai==false){
                    huongDiTrai=true;
                    NhanVatLeft.updateToaDoX(NhanVatRight.returnToaDoX()+30);
                }
                else{
                NhanVatLeft.updateToaDoX(NhanVatLeft.returnToaDoX()-pxDichChuyen);
                }
            }
            else if(e.key.keysym.sym==SDLK_RIGHT){
                if (huongDiTrai==true){
                    huongDiTrai=false;
                    NhanVatRight.updateToaDoX(NhanVatLeft.returnToaDoX()-30);
                }
                else{
                    NhanVatRight.updateToaDoX(NhanVatRight.returnToaDoX()+pxDichChuyen);
                    // SDL_BlitSurface(nhanvatll, NULL, gALL, &{100,100});
                }
            }
        }
        //Apply the gBackground image
        // gBackgroundphu.updateBeMat(gALL);
        gBackground.updateBeMat(gALL);
        // trái
        if (huongDiTrai==true)
        {
            // NhanVatLeft.updateToado(NhanVatLeft.returnToaDoX()-2);
            NhanVatLeft.updateBeMat(gALL,sizeCat);
        }
        // phải
        else if (huongDiTrai==false)
        {
            // NhanVatRight.updateToado(NhanVatRight.returnToaDoX()+2);
            if (NhanVatRight.returnToaDoX()>1180)
            {
                NhanVatRight.updateToaDoX(1180);
            }
            NhanVatRight.updateBeMat(gALL,sizeCat);

        }
        if ((NhanVatLeft.returnToaDoX()+100<=bia[0].returnToaDoX()&&(NhanVatLeft.returnToaDoX()+200>=bia[0].returnToaDoX())) && ((bia[0].returnToaDoY()<900)&&(bia[0].returnToaDoY()>600))||
        (NhanVatRight.returnToaDoX()+100<=bia[0].returnToaDoX()&&(NhanVatRight.returnToaDoX()+200>=bia[0].returnToaDoX())) && ((bia[0].returnToaDoY()<900)&&(bia[0].returnToaDoY()>600)))
        {
            bia[0].updateToaDoX(ranDom());
            bia[0].updateToaDoY(1);
        }
        
        if (bia[0].returnToaDoY()>1000)
        {
            int x=ranDom();
                std::cout<<x;
            bia[0].updateToaDoX(x);
            bia[0].updateToaDoY(1);
        }
        bia[0].updateToaDoY(bia[0].returnToaDoY()+2);
        
        
        for (int i = 0; i < 5; i++)
        {   
            bia[0].updateBeMat(gALL);
        }
        // SDL_BlitSurface(nhanvatll, &sizeCat, gALL,&toadotamthoi);
        clock_t timemoi= clock();
        if (timemoi-timecu>100)
        {
            sizeCat.x += 300;
            timecu=timemoi;
        }
        
        
        

        if (sizeCat.x >= 1800){
            sizeCat.x = 0;
            
        }

    // Cập nhật
    SDL_UpdateWindowSurface(gWindow);
    SDL_FillRect(gALL, NULL, SDL_MapRGB(gALL->format, 0x00, 0x00, 0x00));
    SDL_Delay(10);
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
