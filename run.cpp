#include <ctime>

int randomTruot(const int& x,const int& y){
    //rand ()%(b -a+ 1)+a;    [a,b]
    srand(time(NULL));
    return rand ()%(y-x+ 1)+x;
}

int ramdomDiemA(){
    srand(time(NULL));
    return rand()%1000;
}

int main(){
    khung();
    //khoiTao();
    system("pause");
    return 0;
    
}