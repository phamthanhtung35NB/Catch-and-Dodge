// #include"khoitao.h"
#include "runCheDoVatPham.h"
const int SCREEN_WIDTH = 1850;//1850;//rộng
const int SCREEN_HEIGHT = 1000;
const int pxDichChuyen = 15;
const int toaDoYNhanVat=760;

// cua so win
SDL_Window* gWindow = NULL;
SDL_Surface* gALL = NULL;
Mix_Chunk* soundCoi=NULL;
Mix_Music* musicVatpham=NULL;

//0=quay mặt sang phải
// 1 = quay mặt sang trái
// 2 = chạy sang phải
// 3 = chạy sang trái
// 4 = nhảy
// 5 = ngã
int checkHoatDong=0;

int chieuCaoKhungNhanVat = 150;
int chieuRongKhungNhanVat = 90;
int HP=1;
double timecu,timeXuatHien=0;
int soLuong=0;//số lượng vật phẩm đang có trên màn hình
int tocDoRoi=1;
bool arrTrueFalse[5]{false,false,false,false,false};//vvật phẩm nài còn trên màn hình
long diem=0;
SDL_Rect sizeHP;
SDL_Rect sizeCat;

nhanvat bia[5]{
nhanvat(gALL,"bianho.png",1850,0),
nhanvat(gALL,"bianho.png",1850,0),
nhanvat(gALL,"bom.png",1850,0),
nhanvat(gALL,"bianho.png",1850,0),
nhanvat(gALL,"bom.png",1850,0)
};


Text textTrue1(gALL, "data/3Dumb.ttf", 65,  intToString(diem).c_str(),  { 255, 255, 255,255 },  1590, 510);

// SDL_Surface* nhanvatll=IMG_Load("nhanvatRnho.png");
// nhanvat gBackgroundphu(gALL,"nenphu.png",1500,0);
nhanvat gBackground(gALL,"anhnenchuan.png",0,0);
nhanvat thanhHP(gALL,"data/3timmau.png", 1607,361);
nhanvat nutChucNang(gALL,"data/nutchucnangTrong.png",1754,0);
nhanvat khungNoi(gALL,"data/khunganhnenchuan.png",0,0);
nhanvat nhanVatgame(gALL,"data/nhanvatgame.png",600,toaDoYNhanVat);


// int main( int argc, char* args[] ){
//     runCheDoVatPham("ssss");
//     return 0;
// }
long runCheDoVatPham(std::string name)
{
    sizeCat.x = 0;
    sizeCat.y = 0;
    sizeCat.w = chieuRongKhungNhanVat;
    sizeCat.h = chieuCaoKhungNhanVat;
    const Uint8 * keyState;
    
    if (!init())
    {
        std::cout<<"khong the khoi tao.";   
        return 1;
    }
    Text textName(gALL, "data/3Dumb.ttf", 35,  name.c_str(),  { 255, 255, 255,255 },  1550, 230);
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
        //Background
        gBackground.updateBeMat(gALL);
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
                    if (clock()-timecu>1)
                    {
                        sizeCat.x += 87;
                        if (sizeCat.x >= 430)sizeCat.x = 0;
                        timecu=clock();
                    }
                }
                else{
                    checkHoatDong=2;
                    nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()+pxDichChuyen);
                    if (clock()-timecu>1)
                    {
                        sizeCat.x += 87;
                        if (sizeCat.x >= 430)sizeCat.x = 0;
                        timecu=clock();
                    }
                    // SDL_BlitSurface(nhanvatll, NULL, gALL, &{100,100});
                }
            }
        trangThaiNhanVat();
        vaTram();

        for (int i = 0; i < 5; i++)
        {
            if (arrTrueFalse[i]==true)
            {
                bia[i].updateToaDoY(bia[i].returnToaDoY()+tocDoRoi);
            }
        }
        ////////////////////////////////////////////////////////////////////////////
        //update
        
        //Tiền
        for (int i = 0; i < 5; i++)
        {   
            bia[i].updateBeMat(gALL);
        }
        //nhân vật
        nhanVatgame.updateBeMat(gALL,sizeCat);
        //khung
        khungNoi.updateBeMat(gALL);

        int x, y;
            SDL_GetMouseState(&x, &y);
            if (x>1754&&x<1850&&y>0&&y<100)
            {
                nutChucNang.updateBeMat(gALL);
                
                if (e.type == SDL_MOUSEBUTTONDOWN) {
                    Mix_PlayChannel(-1, soundCoi, 0);                  
                }
        
            }

        //thanh HP
        updateHP();
        //điểm
        textTrue1.updateBeMatText(gALL, intToString(diem).c_str(),{ 255, 255, 255 });
        //usersName
        textName.updateBeMatText(gALL);
        //////////////////////////////////////////////////////////////////////////////
        // Cập nhật
        SDL_UpdateWindowSurface(gWindow);
        SDL_FillRect(gALL, NULL, SDL_MapRGB(gALL->format, 0x00, 0x00, 0x00));
        SDL_Delay(1);
    }
	// close();100/3
	return diem;
}

bool init(){
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
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    musicVatpham = Mix_LoadMUS("nhacnendotoc.mp3");
    Mix_PlayMusic(musicVatpham, -1);
    soundCoi = Mix_LoadWAV("data/coin.wav");
    return true;
}
void vaTram(){
    for (int i = 0; i < 5; i++)
    {
    if ((nhanVatgame.returnToaDoX()+30<=bia[i].returnToaDoX()&&(nhanVatgame.returnToaDoX()+120>=bia[i].returnToaDoX())) && ((bia[i].returnToaDoY()<900)&&(bia[i].returnToaDoY()>600))||
    (nhanVatgame.returnToaDoX()+30<=bia[i].returnToaDoX()&&(nhanVatgame.returnToaDoX()+120>=bia[i].returnToaDoX())) && ((bia[i].returnToaDoY()<toaDoYNhanVat+50)&&(bia[i].returnToaDoY()>toaDoYNhanVat)))
    {
        // bia[i].updateToaDoX(ranDom());
        // bia[i].updateToaDoY(1);
        Mix_PlayChannel(-1, soundCoi, 0);
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
    }
    if (nhanVatgame.returnToaDoX()>1450)
        {
            nhanVatgame.updateToaDoX(1450);
        }
        
}
void trangThaiNhanVat(){
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
    if (clock()-timecu>100)
    {
        sizeCat.x += 90;
        timecu=clock();
        if (sizeCat.x >= 449)sizeCat.x = 0;
    }
}
void updateHP(){
    if (HP==3)
        {
            
            thanhHP.updateBeMat(gALL);
            
        }else if(HP==2)
        {
            
            sizeHP.w = 53*2;
            sizeHP.h = 49;
            thanhHP.updateBeMat(gALL,sizeHP);
        }
        else if (HP==1)
        {
            sizeHP.w = 53;
            sizeHP.h = 49;
            thanhHP.updateBeMat(gALL,sizeHP);
        }
        else if (HP==0)
        {
            sizeHP.w = 0;
            sizeHP.h = 0;
            thanhHP.updateBeMat(gALL,sizeHP);
        }
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
