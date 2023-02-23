#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "erom.h"
// khiểmtra tk mk trong data
std::string check();
void updateFile();

std::string line, name_, pass_,diem_,stt_;

std::string checkTrongFile(){
    std::ifstream file_data("data/dataLuuTam.txt");
   
    if (!file_data.is_open())   {std::cout << "Failed to open file" << std::endl;}

    //check tung dong
    while (std::getline(file_data, line)) 
    {
        std::istringstream iss(line);
        iss >> stt_ >> name_ >> pass_ >> diem_;
        std::cout << "STT: " << stt_ << "Name: " << name_ << ", Pas: " << pass_ << ", Age: " << diem_ << std::endl;
        if (name_==arr_login[0])
        {
            //pass true
            if (pass_==arr_login[1])
            {
                arr[0]=stt_;
                arr[1]=arr_login[0];
                arr[2]=arr_login[1];
                arr[3]=diem_;
                return diem_;
            }
            //pass F
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

void updateFile()
{
    std::ofstream outfile2;
    outfile2.open("data/dataLuuTam.txt", std::ios::out|std::ios::app);
    std::string line2;
    while (std::getline(outfile2, line2)) 
    {
        std::istringstream iss(line2);
        iss >> stt_ >> name_ >> pass_ >> diem_;
        std::cout << "STT: " << stt_ << "Name: " << name_ << ", Pas: " << pass_ << ", Age: " << diem_ << std::endl;
        if (stt_==arr[0])
        {
            arr[0]=stt_;
            arr[1]=arr_login[0];
            arr[2]=arr_login[1];
            arr[3]=diem_;
            outfile2 << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << std::endl;
        }
    }
    // đóng file
    outfile2.close();
}
void taoTK(){
    std::ofstream outfileTaoTK("data/dataLuuTam.txt", std::ios::app);
    outfileTaoTK << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << std::endl;
    // đóng file
    outfileTaoTK.close();
}
