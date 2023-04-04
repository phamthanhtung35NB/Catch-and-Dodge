#include"khoitao.h"


const int SCREEN_WIDTH = 1850;//1850;//rộng
const int SCREEN_HEIGHT = 1000;
std::vector<std::string> lineVT={"o"};
const int pxDichChuyen = 5;
// cua so win
SDL_Window* gWindow = NULL;
SDL_Surface* gALL = NULL;

int randomTruot(const int& x,const int& y){
    //rand ()%(b -a+ 1)+a;    [a,b]
    srand(time(NULL));
    return rand ()%(y-x+ 1)+x;
}
int main( int argc, char* args[] )
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){std::cout<<"SDL_ERROR: \n"<<SDL_GetError();}
	TTF_Init();
    gWindow = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN );
	if( gWindow == NULL ){std::cout<<( "Window could not be created! SDL_Error:\n", SDL_GetError() );}
    //vẽ ảnh. Tạo surface để vẽ lên
    gALL = SDL_GetWindowSurface( gWindow );
    //vẽ tex
    // Tạo surface để vẽ lên
    // textSurface = SDL_GetWindowSurface(gWindow);
    // màu
    // SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    std::ifstream infile("dataLuuTam.txt");
    
    nhanvat gBackground(gALL,"data/Backgroundfull.png",0,0);
    nhanvat NhanVatLeft(gALL,"data/Left.png",750,580);
    nhanvat NhanVatRight(gALL,"data/Right.png",750,580);
    bool huongDiTrai=true;  //true sang trái
                            //false sang phải
    SDL_Event e;
    bool quit = false;
    int soLuong=0;
    if(infile.is_open())
    {
        
        std::string line;
        
        while (getline(infile, line)) {
            lineVT.push_back(line);
            soLuong++;
        }
    }
    std::cout<<soLuong;
    // Xóa bộ đệm hiển thị
    // SDL_FillRect(ga, NULL, SDL_MapRGB(textSurface->format, 0x00, 0x00, 0x00));
    Text text1(gALL, "data/arial.ttf", 55, lineVT[1].c_str(),  { 255, 0, 0 },  100, 1);
    // Text text2(gALL, "data/arial.ttf", 55, lineVT[2].c_str(),  { 0, 255, 0 },  400, 522);

    // Text text3(gALL, "data/arial.ttf", 55,lineVT[3].c_str(),  { 0, 0, 255 },  600, 522);

    // Text text4(gALL, "data/arial.ttf", 55, lineVT[4].c_str(),  { 255, 255, 255 },  700, 522);

    
    
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
            NhanVatLeft.updateToado(NhanVatLeft.returnToaDoX()-2);
            NhanVatLeft.updateBeMat(gALL);
        }
        // phải
        else if (huongDiTrai==false)
        {
            NhanVatRight.updateToado(NhanVatRight.returnToaDoX()+2);
            if (NhanVatRight.returnToaDoX()>1180)
            {
                NhanVatRight.updateToado(1180);
            }
            NhanVatRight.updateBeMat(gALL);
        }
        int x=randomTruot(1,15)*100;
            text1.updateToadoX(x);
            text1.updateToadoY(text1.returnToaDoY()+1);
            if (text1.returnToaDoY()>1000)
            {
                text1.updateToadoY(1);
            }
            
    // Xóa bộ đệm hiển thị
    // 
    text1.updateBeMatText(gALL);
    // text2.updateBeMatText(gALL);
    // text3.updateBeMatText(gALL);
    // text4.updateBeMatText(gALL);
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
