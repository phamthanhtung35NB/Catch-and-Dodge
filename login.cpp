#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <exception>
#include <string>
#include <windows.h>
#include "docGhiFile.cpp"
#include "erom.h"

//check cos tk chua
bool check(std::string& name_login,std::string& pass_login);

// tao tk or dang nhap
std::string loginTK(std::string& name_login,std::string& pass_login);
// nhập thông tin tk
void nhap();
std::string name_login;
std::string pass_login;

std::string login(){
	//nhap name + pass
	dangNhapLai:
	nhap(name_login,pass_login);
	// kiem tra
	
	//tao tk or login
	//tra lai so diem
	return loginTK(name_login,pass_login);
}
void nhap(std::string& name_login,std::string& pass_login){
	getline(std::cin,name_login);
	getline(std::cin,pass_login);
}
std::string loginTK(std::string& name_login,std::string& pass_login){
	
	
	if (check(name_login,pass_login))
	{
		name=name_login;
		pass=pass_login;
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
			name=name_login;
			pass=pass_login;
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

bool check(std::string& name_login,std::string& pass_login){
    //check excel xem co tk chua
	std::string KQcheck=checkTrongFile(name_login,pass_login);
    if (KQcheck=="MK_SAI")
    {
        return false;
    }
	else if (KQcheck=="CHUA_CO")
	{
		return false;
	}
    return 1;
    
}


