#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "erom.h"
// khiểmtra tk mk trong data
std::string check(std::string& name_login,std::string& pass_login);
void ghiFile();


std::string line, name_, pass_,diem_;
std::string checkTrongFile(std::string& name_login,std::string& pass_login){
    std::ifstream file_data("data/dataLuuTam.txt");
   

    if (!file_data.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        return "1";
    }

    std::string line, name_, pass_,diem_;
    while (std::getline(file_data, line)) {
        std::istringstream iss(line);
        iss >> name_ >> pass_ >> diem_;
        std::cout << "Name: " << name_ << ", Pas: " << pass_ << ", Age: " << diem_ << std::endl;
        if (name_==name_login)
        {
            if (pass_==pass_login)
            {
                name=name_login;
                pass=pass_login;
                diemmax=diem_;
                return diem_;
            }
            //pass sai
            else{
                return "MK_SAI";                
            }
            
        }
        //chua co tk
        else
        {
            return "CHUA_CO";
        }
        
    }
    file_data.close();
}
void ghiFile(std::string& name_login,std::string& pass_login,std::string& diem){
    std::ofstream outfile("data/dataLuuTam.txt", std::ios::app);
    outfile << name_login << " " << pass_login << " " << diem << std::endl;
    // đóng file
    outfile.close();
}
