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
// extern SDL_Rect sizeHP;
// extern sizeHP.x = 0;
// extern sizeHP.y = 0;
// extern sizeHP.w = 0;
// extern sizeHP.h = 0;

bool init();
void updateHP();
void vaTram();
void trangThaiNhanVat();
void troNgaiong();
void hamEndGame();
int hamLevel();
long runCheDoVatPham(std::string name);
// void close();
#endif
