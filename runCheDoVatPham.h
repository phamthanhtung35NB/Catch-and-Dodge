#ifndef KHOITAO_H
#define KHOITAO_H

#include "khoitao.h"
// #include "runCheDoVatPham.h"

// extern const int SCREEN_WIDTH;//1850;//rộng
// extern const int SCREEN_HEIGHT;
// extern int pxDichChuyen;
// extern const int toaDoYNhanVat;
// extern int checkHoatDong;
// extern int chieuCaoKhungNhanVat;
// extern int chieuRongKhungNhanVat;
// extern double timecu,timeXuatHien;
// extern int soLuong;//số lượng vật phẩm đang có trên màn hình
// extern int tocDoRoi;
extern int level;
// extern SDL_Rect sizeHP;
// extern sizeHP.x = 0;
// extern sizeHP.y = 0;
// extern sizeHP.w = 0;
// extern sizeHP.h = 0;

bool init();
void updateHP();
void vaTram();
void upDateAnhXuatHienTocBienVsKhien();
void checkTocBien();
void xuLyNhay();
void tatKhien();
void trangThaiNhanVat();
// void troNgaiong();
void hamTamDung();
void hamEndGame();
void hamUpdateLevel();
void close();
int runCheDoVatPham(std::string name);
// void close();
#endif
