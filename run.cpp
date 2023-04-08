#include"khoitao.h"


const int SCREEN_WIDTH = 1850;//1850;//rộng
const int SCREEN_HEIGHT = 1000;
std::vector<std::string> lineVecToTrue={};
std::vector<std::string> lineVecToFalse={};
const int pxDichChuyen = 5;
// cua so win
SDL_Window* gWindow = NULL;
SDL_Surface* gALL = NULL;





int randomTruot(){
    //rand ()%(b -a+ 1)+a;    [a,b]
    clock_t start, end;   // Khai báo biến thời gian
    double time_use;      // Thời gian sử dụng
    start = clock();  
    end = clock();  // lấy thời gian sau khi thực hiện 
    time_use = (double)(end - start) / CLOCKS_PER_SEC; 
    int ran;
    srand(time(0));
    ran=rand ()%(100)+5;
    return ran;
}
int main( int argc, char* args[] )
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){std::cout<<"SDL_ERROR: \n"<<SDL_GetError();}
	TTF_Init();
    gWindow = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN );
	if( gWindow == NULL ){std::cout<<( "Window could not be created! SDL_Error:\n", SDL_GetError() );}
    gALL = SDL_GetWindowSurface( gWindow );
    std::ifstream infile("dataLuuTam.txt");
    nhanvat bia(gALL,"bianho.png",0,0);
    nhanvat gBackground(gALL,"data/Backgroundfull.png",0,0);
    nhanvat NhanVatLeft(gALL,"data/Left.png",750,580);
    nhanvat NhanVatRight(gALL,"data/Right.png",750,580);
    bool huongDiTrai=true;  //true sang trái
                            //false sang phải
    SDL_Event e;
    bool quit = false;
    int soLuong=0;
    if(infile.is_open()){
        std::string line;
        while (getline(infile, line)) {
            lineVecToTrue.push_back(line);
            soLuong++;
        }
    }
    std::cout<<soLuong;
    // Xóa bộ đệm hiển thị
    // SDL_FillRect(ga, NULL, SDL_MapRGB(textSurface->format, 0x00, 0x00, 0x00));
    Text textTrue1(gALL, "data/arial.ttf", 55, lineVecToTrue[0].c_str(),  { 255, 0, 0 },  100, 1);
    // Text textTrue2(gALL, "data/arial.ttf", 55, lineVecToTrue[2].c_str(),  { 0, 255, 0 },  400, 522);
    // Text textTrue3(gALL, "data/arial.ttf", 55,lineVecToTrue[3].c_str(),  { 0, 0, 255 },  600, 522);
    // Text textFalse1(gALL, "data/arial.ttf", 55, lineVecToTrue[4].c_str(),  { 255, 255, 255 },  700, 522);
    while (quit == false)
    {
        // while (SDL_PollEvent(&e))
        if (SDL_PollEvent(&e))
        {
            
            if (e.type == SDL_QUIT)quit = true;
            else if(e.key.keysym.sym== SDLK_LEFT){
                if (huongDiTrai==false){
                    huongDiTrai=true;
                    NhanVatLeft.updateToadoX(NhanVatRight.returnToaDoX()+330);
                }
                else{
                NhanVatLeft.updateToadoX(NhanVatLeft.returnToaDoX()-pxDichChuyen);
                }
            }
            else if(e.key.keysym.sym==SDLK_RIGHT){
                if (huongDiTrai==true){
                    huongDiTrai=false;
                    NhanVatRight.updateToadoX(NhanVatLeft.returnToaDoX()-330);
                }
                else{
                    NhanVatRight.updateToadoX(NhanVatRight.returnToaDoX()+pxDichChuyen);
                }
            }
        }
        //Apply the gBackground image
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
                NhanVatRight.updateToadoX(1180);
            }
            NhanVatRight.updateBeMat(gALL);
        }
        int x=randomTruot()*10;
            bia.updateToadoX(x);
            bia.updateToaDoY(bia.returnToaDoY()+1);
            if (bia.returnToaDoY()>1000)
            {
                bia.updateToaDoY(1);
            }
            // std::cout<<bia.returnToaDoY;
            
    // Xóa bộ đệm hiển thị
    // 
    bia.updateBeMat(gALL);
    textTrue1.updateBeMatText(gALL);
    // textTrue2.updateBeMatText(gALL);
    // textTrue3.updateBeMatText(gALL);
    // textFalse1.updateBeMatText(gALL);
    // Cập nhật
    SDL_UpdateWindowSurface(gWindow);
    SDL_FillRect(gALL, NULL, SDL_MapRGB(gALL->format, 0x00, 0x00, 0x00));

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


// int randomDiemA(){
//     srand(time(NULL));
//     return rand()%1000;
// }

// int randomTruot()
// {
//     return 0;
// }
