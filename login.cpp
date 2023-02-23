#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <exception>
#include <string>
#include <windows.h>
#include "docGhiFile.cpp"
#include "erom.h"


// std::string& name_login,std::string& pass_login

//check cos tk chua
bool check();
// tao tk or dang nhap
std::string loginTK();
// nhập thông tin tk
void nhap();


std::string login(){
	//nhap name + pass
	dangNhapLai:
	nhap();
	// kiem tra
	
	//tao tk or login
	//tra lai so diem
	return loginTK();
}
void nhap(){
	getline(std::cin,arr_login[0]);
	getline(std::cin,arr_login[1]);
}
std::string loginTK(){
	
	bool a=check();
	if (a==1)
	{
		arr[1]=arr_login[0];
		arr[2]=arr_login[1];
		//return diemMax

	}
	else
	{
		//chuwa cos tk
		char ktr='n';
		// chon dang nhap lai

		// lap tk moi 
		if (ktr=='Y'||ktr=='y')
		{
			//khoi tao tk
			arr[1]=arr_login[0];
			arr[2]=arr_login[1];
			diemmax="0";
			//luu thong tin name,pass,diemmax;
			return diemmax;
		}
		else
		{
			std::goto dangNhapLai;
			//ra dang nhap lai
		}
	}
	
}

bool check(){
    //check excel xem co tk chua
	std::string KQcheck=checkTrongFile();
    if (KQcheck=="MK_SAI")
    {
        return false;
    }
	else if (KQcheck=="CHUA_CO")
	{
		return false;
	}
    return true;
    
}


