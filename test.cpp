
#include<iostream>
#include<stdlib.h>

std::string arr16Surface[16];
std::string intTostring(int a){
    std::string s;
    a++;
    while (a>0)
    {
        s=char((a%10)+48)+s;
        a/=10;
    }
    return s;
}
int main( int argc, char* args[] ){
    for (int i = 0; i < 16; i++)
    {
        arr16Surface[i]="right"+intTostring(i)+".png";
    }
    for (int i = 0; i < 16; i++)
    {
        std::cout<<arr16Surface[i];
    }
}
