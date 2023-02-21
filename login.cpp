#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <exception>
#include <string>
#include <windows.h>

//check cos tk chua
bool check(const std::string& name,const std::string& password);

// tao tk or dang nhap
int loginTK(std::string& name,std::string& password);

void nhap();

int login(){
	//nhap name + pass
	// kiem tra
	//tao tk or login
	//tra lai so diem
	return loginTK();
}
void nhap(){
	std::cin>>name;
	std::cin>>pass;
}
int loginTK(std::string& name,std::string& password){
	if (check(name,password))
	{
		//print diem cao nhat
	}
	else{
		//chuwa cos tk
		char ktr='n';
		// chon dang nhap lai

		// lap tk moi 
		if (ktr=='Y'||ktr=='y')
		{
			//luu thong tin 
		}
		else
		{
			//ra dang nhap lai
		}
	}
	
}

bool check(const std::string& name,const std::string& password){
    //check xem co tk chua
    if (/*neu co roi*/true)
    {
        return true;
    }
    else
    {
        return false;
    }
}


