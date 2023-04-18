#include"khoitao.h"
// #include "runCheDoVatPham.h"
const int SCREEN_WIDTH = 1850;//1850;//rộng
const int SCREEN_HEIGHT = 1000;
const int pxDichChuyen = 15;
const int toaDoYNhanVat=760;
//0=quay mặt sang phải
// 1 = quay mặt sang trái
// 2 = chạy sang phải
// 3 = chạy sang trái
// 4 = nhảy
// 5 = ngã
int checkHoatDong=0;
int chieuCaoKhungNhanVat = 150;
int chieuRongKhungNhanVat = 90;

// cua so win
SDL_Window* gWindow = NULL;
SDL_Surface* gALL = NULL;

double timecu,timeXuatHien=0;
int soLuong=0;//số lượng vật phẩm đang có trên màn hình
int tocDoRoi=1;
bool arrTrueFalse[5]{false,false,false,false,false};//vvật phẩm nài còn trên màn hình
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



// int main( int argc, char* args[] )
int runCheDoVatPham()
{
    SDL_Rect sizeCat;
sizeCat.x = 0;
sizeCat.y = 0;
sizeCat.w = chieuRongKhungNhanVat;
sizeCat.h = chieuCaoKhungNhanVat;

    const Uint8 * keyState;
    long diem=0;
    if (!init())
    {
        std::cout<<"khong the khoi tao.";   
        return 1;
    }
    nhanvat bia[5]{
        nhanvat(gALL,"bianho.png",1850,0),
        nhanvat(gALL,"bianho.png",1850,0),
        nhanvat(gALL,"bom.png",1850,0),
        nhanvat(gALL,"bianho.png",1850,0),
        nhanvat(gALL,"bom.png",1850,0)
    };
    Text textTrue1(gALL, "data/arial.ttf", 65,  intToString(diem).c_str(),  { 255, 0, 0 },  1600, 600);

        // SDL_Surface* nhanvatll=IMG_Load("nhanvatRnho.png");
    // nhanvat gBackgroundphu(gALL,"nenphu.png",1500,0);
    nhanvat gBackground(gALL,"anhnenchuan.png",0,0);
    // nhanvat nhanVatgame(gALL,"nhanvatLnho.png",600,toaDoYNhanVat);
    // nhanvat nhanVatgame(gALL,"data/nhanvatgame.png",600,toaDoYNhanVat);
    nhanvat nhanVatgame(gALL,"data/nhanvatgame.png",600,toaDoYNhanVat);
    SDL_Event e;
    bool quit = false;
    // Xóa bộ đệm hiển thị
    // SDL_FillRect(ga, NULL, SDL_MapRGB(textSurface->format, 0x00, 0x00, 0x00));


    
    while (quit == false)
    {
        // Xóa màn hình
        // SDL_FillRect(gALL, NULL, SDL_MapRGB(gALL->format, 0xFF, 0xFF, 0xFF));
        // if (checkHoatDong==2)checkHoatDong=0;
        // else checkHoatDong=1;
        if (clock()-timeXuatHien>1000 && soLuong<5&&arrTrueFalse[soLuong]==false)
        {
            timeXuatHien=clock();
            bia[soLuong].updateToaDoX(ranDom());
            arrTrueFalse[soLuong]=true;
            // bia[soLuong].updateToaDoX(ranDom());
            soLuong++;
        }
        if (soLuong==5)
        {
            soLuong=0;
        }
        
        
            keyState = SDL_GetKeyboardState(NULL);

        while (SDL_PollEvent(&e))
        // if (SDL_PollEvent(&e))
        {
            
            if (e.type == SDL_QUIT)quit = true;
            // else if(e.key.keysym.sym== SDLK_LEFT){
            //     if (checkHoatDong==){
            //         checkHoatDong=true;
            //         nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()-60);
            //     }
            //     else{
            //     nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()-pxDichChuyen);
            //     }
            // }
            // else if(e.key.keysym.sym==SDLK_RIGHT){
            //     if (checkHoatDong==true){
            //         checkHoatDong=false;
            //         nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()+60);
            //     }
            //     else{
            //         nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()+pxDichChuyen);
            //         // SDL_BlitSurface(nhanvatll, NULL, gALL, &{100,100});
            //     }
            // }
            //phai
        }
            if(keyState[SDL_SCANCODE_A]||keyState[SDL_SCANCODE_LEFT]){
                if (checkHoatDong==1){
                    checkHoatDong=3;
                    nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()-60);
                    if (clock()-timecu>30)
                    {
                        sizeCat.x += 89;
                        if (sizeCat.x >= 430)sizeCat.x = 0;
                        timecu=clock();
                    }
                }
                else{
                    checkHoatDong=3;
                nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()-pxDichChuyen);
                if (clock()-timecu>30)
                    {
                        sizeCat.x += 87;
                        if (sizeCat.x >= 430)sizeCat.x = 0;
                        timecu=clock();
                    }
                }
            }
            
            
            //trai
            else if(keyState[SDL_SCANCODE_D]||keyState[SDL_SCANCODE_RIGHT]){
                if (checkHoatDong==0){
                    checkHoatDong=2;
                    nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()+60);
                    if (clock()-timecu>30)
                    {
                        sizeCat.x += 87;
                        if (sizeCat.x >= 430)sizeCat.x = 0;
                        timecu=clock();
                    }
                }
                else{
                    checkHoatDong=2;
                    nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()+pxDichChuyen);
                    if (clock()-timecu>30)
                    {
                        sizeCat.x += 87;
                        if (sizeCat.x >= 430)sizeCat.x = 0;
                        timecu=clock();
                    }
                    // SDL_BlitSurface(nhanvatll, NULL, gALL, &{100,100});
                }
            }
        // 0 = quay mặt sang phải
        // 1 = quay mặt sang trái
        // 2 = chạy sang phải
        // 3 = chạy sang trái
        // 4 = nhảy
        // 5 = ngã
        if (checkHoatDong==0)
        {
            sizeCat.y = 0;
        }
        else if (checkHoatDong==1)
        {
            sizeCat.y= chieuCaoKhungNhanVat*1;
        }
        else if (checkHoatDong==2)
        {
            sizeCat.y = chieuCaoKhungNhanVat*2;
        }
        else if (checkHoatDong==3)
        {
            sizeCat.y = chieuCaoKhungNhanVat*3;
        }
        else if (checkHoatDong==4)
        {
            sizeCat.y = chieuCaoKhungNhanVat*4;
        }
        else if (checkHoatDong==5)
        {
            sizeCat.y = chieuCaoKhungNhanVat*5;
        }

        //Apply the gBackground image
        // gBackgroundphu.updateBeMat(gALL);
        gBackground.updateBeMat(gALL);
        if (clock()-timecu>100)
        {
            sizeCat.x += 89;
            if (sizeCat.x >= 450)sizeCat.x = 0;
            timecu=clock();
        }
            // nhanVatgame.updateToado(nhanVatgame.returnToaDoX()+2);
            if (nhanVatgame.returnToaDoX()>1450)
            {
                nhanVatgame.updateToaDoX(1450);
            }
            nhanVatgame.updateBeMat(gALL,sizeCat);

        for (int i = 0; i < 5; i++)
        {
        if ((nhanVatgame.returnToaDoX()+30<=bia[i].returnToaDoX()&&(nhanVatgame.returnToaDoX()+120>=bia[i].returnToaDoX())) && ((bia[i].returnToaDoY()<900)&&(bia[i].returnToaDoY()>600))||
        (nhanVatgame.returnToaDoX()+30<=bia[i].returnToaDoX()&&(nhanVatgame.returnToaDoX()+120>=bia[i].returnToaDoX())) && ((bia[i].returnToaDoY()<toaDoYNhanVat+50)&&(bia[i].returnToaDoY()>toaDoYNhanVat)))
        {
            // bia[i].updateToaDoX(ranDom());
            // bia[i].updateToaDoY(1);
            arrTrueFalse[i]=false;
            diem+=100;
            bia[i].updateToaDoX(1900);
            bia[i].updateToaDoY(1);
        }
        
        if (bia[i].returnToaDoY()>1000)
        {
            int x=ranDom();
            arrTrueFalse[i]=false;
            bia[i].updateToaDoX(1900);
            bia[i].updateToaDoY(1);
        }
            if (arrTrueFalse[i]==true)
            {
                bia[i].updateToaDoY(bia[i].returnToaDoY()+tocDoRoi);    
        // bia[i].updateToaDoY(bia[i].returnToaDoY()+2);
            }
        }
        
        //update vatpham bia
        for (int i = 0; i < 5; i++)
        {   
            bia[i].updateBeMat(gALL);
        }
        
        
        
        

        
        // std::cout<<diem;
            // Text textTrue1(gALL, "data/arial.ttf", 65,  intToString(diem).c_str(),  { 255, 0, 0 },  1600, 600);
        textTrue1.updateBeMatText(gALL, intToString(diem).c_str(),{ 255, 0, 0 });

    // Cập nhật
    SDL_UpdateWindowSurface(gWindow);
    SDL_FillRect(gALL, NULL, SDL_MapRGB(gALL->format, 0x00, 0x00, 0x00));
    SDL_Delay(1);
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
//     SDL_FreeSurface(nhanVatgame);
//     nhanVatgame = NULL;

//     SDL_FreeSurface(nhanVatgame);
//     nhanVatgame = NULL;
// 	//Destroy window
// 	SDL_DestroyWindow( gWindow );
// 	gWindow = NULL;

// 	//Quit SDL subsystems
// 	SDL_Quit();
// }
