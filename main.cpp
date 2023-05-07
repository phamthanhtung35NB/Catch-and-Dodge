#include "runCheDoVatPham.h"
#include "manHinhKhoiDong.h"
#include "endGame.h"
std::string Name;//tên người chơi
long diemdadat=0;//điểm đạt được
int chedo=1;//chọn chế độ chơi
bool checkLoa=true;
Mix_Music* music=NULL;
bool initMain(){
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 ){
        std::cout<<"Khong khoi tao duoc SDL: \n"<<SDL_GetError();
        return false;
    }
    if (TTF_Init()<0)
    {
        std::cout<<"Khong khoi tao duoc TTF: \n";
        return false;
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout<<"Khong khoi tao duoc SDL: \n"<< IMG_GetError();
        return false;
    }
    
    return true;
}

int main( int argc, char* args[] )
{
    if (initMain())
    {
        //màn đăng nhập
        tieptuc:
        Name=manHinhKhoiDong();
        std::cout<<Name;
        //chọn chế độ
        ///////chedo=hàm chọn chế độ
        
        
        //Name!="        " //ấn nút thoát ngay trong màn hình đăng nhập
        if (chedo==1&&Name!="        ")
        {
            //chế độ vât phẩm
            diemdadat=runCheDoVatPham(Name);
            close();
            chedo=0;
        }else if (chedo==2)
        {
            //che độ text
            chedo=0;
            return 0;
        }
        //khi ấn thoát ở trong game
        if (diemdadat==-1000)
        {
            SDL_Quit();
            return 0;
        }
        
        bool luaChon=false;
        luaChon=endGame(level,diemdadat,Name);
        if (luaChon==true&&chedo==0)
        {   
            chedo=1;
            goto tieptuc;
        }
        // else if (luaChon==false&&chedo==0)
        // {
            
        //     goto tieptuc;
        // }
    }
    SDL_Quit();
    return 0;
}