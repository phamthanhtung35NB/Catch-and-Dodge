
#include "runCheDoVatPham.h"
#include "manHinhKhoiDong.h"
std::string Name;
long diemdadat=0;
int chedo=1;
int main( int argc, char* args[] )
{
    //màn đăng nhập
    Name=manHinhKhoiDong();
    std::cout<<Name;
    //chọn chế độ
    ///////chedo=hàm chọn chế độ
    
    
    
    
    if (chedo==1)
    {
        //chế độ vât phẩm
        diemdadat=runCheDoVatPham(Name);
        std::cout<<diemdadat;
    }else if (chedo==2)
    {
        //che độ text
        return 0;
    }
    
    

    
    return 0;
}