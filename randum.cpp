#include <iostream>
#include <random>
#include<time.h>
#include <windows.h>

#include <ctime>
using namespace std;
int timecu=0;
// #include <random>

// Hàm trả về một số ngẫu nhiên trong khoảng [min, max]



int main() {
    for (int i = 0; i < 200; i++)
    {
    // cout << "Một số ngẫu nhiên được làm tròn đến hàng trăm gần nhất: 
    cout<< random() << endl;
        Sleep(1000);
    }
    
    return 0;
}
