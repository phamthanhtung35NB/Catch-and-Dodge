#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <exception>
#include <string>
#include <windows.h>

//check cos tk chua
bool check(const std::string& name_login,const std::string& pass_login);

// tao tk or dang nhap
int loginTK(std::string& name_login,std::string& pass_login);

void nhap();

int login(){
	//nhap name + pass
	std::string name_login;
	std::string pass_login;
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
int loginTK(std::string& name_login,std::string& pass_login){
	if (check(name_login,pass_login))
	{
		name=name_login;
		pass=pass_login;
		//return diemMax

	}
	else{
		//chuwa cos tk
		char ktr='n';
		// chon dang nhap lai

		// lap tk moi 
		if (ktr=='Y'||ktr=='y')
		{
			//khoi tao tk
			name=name_login;
			pass=pass_login;
			diemmax=0;
			//luu thong tin name,pass,diemmax;
			return 0;
		}
		else
		{
			std::goto dangNhapLai;
			//ra dang nhap lai
		}
	}
	
}

bool check(const std::string& name,const std::string& password){
    //check excel xem co tk chua
    if (/*neu co roi*/true)
    {
        return true;
    }
    else
    {
        return false;
    }
}


