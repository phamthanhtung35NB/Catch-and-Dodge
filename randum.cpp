#include <iostream>
#include <random>
#include <ctime>
using namespace std;

// #include <random>

// Hàm trả về một số ngẫu nhiên trong khoảng [min, max]
int random(int min, int max)
{
    srand(time(NULL));
    std::random_device rd;  // Thiết bị tạo số ngẫu nhiên
    std::mt19937 gen(rd()); // Một trình tạo số ngẫu nhiên dựa trên seed
    std::uniform_int_distribution<> dis(min, max); // Phân phối đều trên khoảng [min, max]

    return dis(gen); // Trả về một số ngẫu nhiên trong khoảng [min, max]
}


int main() {
    int rand_num = random(1,100);
    cout << "A random number rounded to the nearest hundred: " << rand_num << endl;
    return 0;
}
