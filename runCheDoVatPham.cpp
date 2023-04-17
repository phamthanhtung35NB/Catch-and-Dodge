#include"khoitao.h"

const int SCREEN_WIDTH = 1850;//1850;//rộng
const int SCREEN_HEIGHT = 1000;
const int pxDichChuyen = 15;
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



std::string intToString(int num) {
    std::string result = "";
    bool isNegative = false;

    // xử lý số âm
    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    // chuyển đổi từng chữ số thành ký tự tương ứng
    do {
        char digit = '0' + (num % 10);
        result = digit + result;
        num /= 10;
    } while (num > 0);

    // xử lý trường hợp số âm
    if (isNegative) {
        result = '-' + result;
    }

    return result;
}

int main( int argc, char* args[] )
{
    long diem=0;
    if (!init())
    {
        std::cout<<"khong the khoi tao.";   
        return 1;
    }
    nhanvat bia[5]{
        nhanvat(gALL,"bianho.png",0,0),
        nhanvat(gALL,"bianho.png",1850,0),
        nhanvat(gALL,"bianho.png",1850,0),
        nhanvat(gALL,"bianho.png",1850,0),
        nhanvat(gALL,"bianho.png",1850,0)
    };
    Text textTrue1(gALL, "data/arial.ttf", 65,  intToString(diem).c_str(),  { 255, 0, 0 },  1600, 600);
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


    
    while (quit == false)
    {
        // Xóa màn hình
        // SDL_FillRect(gALL, NULL, SDL_MapRGB(gALL->format, 0xFF, 0xFF, 0xFF));

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
        
        

        while (SDL_PollEvent(&e))
        // if (SDL_PollEvent(&e))
        {
            
            if (e.type == SDL_QUIT)quit = true;
            else if(e.key.keysym.sym== SDLK_LEFT){
                if (huongDiTrai==false){
                    huongDiTrai=true;
                    NhanVatLeft.updateToaDoX(NhanVatRight.returnToaDoX()-100);
                }
                else{
                NhanVatLeft.updateToaDoX(NhanVatLeft.returnToaDoX()-pxDichChuyen);
                }
            }
            else if(e.key.keysym.sym==SDLK_RIGHT){
                if (huongDiTrai==true){
                    huongDiTrai=false;
                    NhanVatRight.updateToaDoX(NhanVatLeft.returnToaDoX()+100);
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
        for (int i = 0; i < 5; i++)
        {
        if ((NhanVatLeft.returnToaDoX()+100<=bia[i].returnToaDoX()&&(NhanVatLeft.returnToaDoX()+200>=bia[i].returnToaDoX())) && ((bia[i].returnToaDoY()<900)&&(bia[i].returnToaDoY()>600))||
        (NhanVatRight.returnToaDoX()+100<=bia[i].returnToaDoX()&&(NhanVatRight.returnToaDoX()+200>=bia[i].returnToaDoX())) && ((bia[i].returnToaDoY()<900)&&(bia[i].returnToaDoY()>600)))
        {
            // bia[i].updateToaDoX(ranDom());
            // bia[i].updateToaDoY(1);
            arrTrueFalse[i]=false;
            diem+=100;
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
        if (clock()-timecu>150)
        {
            sizeCat.x += 300;
            timecu=clock();
        }
        
        
        

        if (sizeCat.x >= 1800){
            sizeCat.x = 0;
            
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
