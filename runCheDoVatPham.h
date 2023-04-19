#ifndef KHOITAO_H
#define KHOITAO_H

#include"khoitao.h"
// #include "runCheDoVatPham.h"

extern const int SCREEN_WIDTH;//1850;//rộng
extern const int SCREEN_HEIGHT;
extern const int pxDichChuyen;
extern const int toaDoYNhanVat;
extern int checkHoatDong;
extern int chieuCaoKhungNhanVat;
extern int chieuRongKhungNhanVat;
extern double timecu,timeXuatHien;
extern int soLuong;//số lượng vật phẩm đang có trên màn hình
extern int tocDoRoi;

bool init();
long runCheDoVatPham(std::string name);
// void close();
#endif
