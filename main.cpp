
#include "runCheDoVatPham.h"
#include "manHinhKhoiDong.h"
std::string Name;//tên người chơi
long diemdadat=0;//điểm đạt được
int chedo=1;//chọn chế độ chơi

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
        Name=manHinhKhoiDong();
        std::cout<<Name;
        //chọn chế độ
        ///////chedo=hàm chọn chế độ
        
        
        
        if (chedo==1&&Name!="        ")
        {
            //chế độ vât phẩm
            diemdadat=runCheDoVatPham(Name);
            std::cout<<diemdadat;
        }else if (chedo==2)
        {
            //che độ text
            return 0;
        }
    
        
    }
    return 0;
}