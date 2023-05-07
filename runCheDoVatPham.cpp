#include "runCheDoVatPham.h"
const int SCREEN_WIDTH = 1850;//1850;//rộng
const int SCREEN_HEIGHT = 1000;
const int pxDichChuyen = 1500;
const int timeHoiTocBien=5000;
const int timeHoiKhien=20000;

int timeTextHoiTocBien;
int timeTextHoiKhien;
int toaDoYNhanVat=760;
int HP=3;
int level=1;
int tocDoRoi=3;
int buocNhay=0;
int pxDiChuyen = 11;
int timeKhienDuyTri=10000;
int chieuCaoKhungNhanVat = 150;
int chieuRongKhungNhanVat = 90;
int soLuongCoin=0;//số lượng vật phẩm đang có trên màn hình
int soLuongBom=0;
int diem=0;
int checkHoatDong=0;
//0=quay mặt sang phải
// 1 = quay mặt sang trái
// 2 = chạy sang phải
// 3 = chạy sang trái
// 4 = nhảy
// 5 = ngã

double timeTocBien=clock();
double timeKhien=-5000;
double timecu,timeXuatHien,timeXuatHienBom=0;
double timeBossXuatHienLanTiep;

bool nhay=false;
bool dangBaoVe=false;
// 
bool arrCoinTrueFalse[5]{false,false,false,false,false};//vvật phẩm nài còn trên màn hình
bool arrBomTrueFalse[3]{false,false,false};
bool checkBossDangHoatDong=false;
// cua so win
SDL_Window* gWindow = NULL;
//be mat de ve
SDL_Surface* gALL = NULL;
Mix_Chunk* soundCoi=NULL;
Mix_Chunk* soundNo=NULL;


nhanvat bia[5]{
nhanvat(gALL,"data/coin1.png",1850,0),
nhanvat(gALL,"data/coin2.png",1850,0),
nhanvat(gALL,"data/coin3.png",1850,0),
nhanvat(gALL,"data/coin4.png",1850,0),
nhanvat(gALL,"data/coin1.png",1850,0)
};
nhanvat bom[3]{
nhanvat(gALL,"data/bom.png",1850,0),
nhanvat(gALL,"data/bomDai.png",1850,0),
nhanvat(gALL,"data/boBom.png",1850,0),
};

bossG troNgaiOng(gALL,"data/ong.png",0,0);
nhanvat khien(gALL,"data/khien.png",150,915);
nhanvat tocBien(gALL,"data/tocBien.png",250,915);
nhanvat gBackground(gALL,"data/anhnenchuan.png",0,0);
nhanvat thanhHP(gALL,"data/3timmau.png", 1607,361);
nhanvat nutChucNang(gALL,"data/nutchucnangTrong.png",1754,0);
nhanvat khungNoi(gALL,"data/khunganhnenchuan.png",0,0);
nhanvat nhanVatgame(gALL,"data/nhanvatgame.png",600,toaDoYNhanVat);
nhanvat khienChoNhanVat(gALL,"data/khienchonhanvat.png",600,toaDoYNhanVat);
nhanvat endGame(gALL,"data/manEndGame.png",688,200);
nhanvat nutNext(gALL,"data/nutnext.png",841,738);
// sao moix khi tawng lv
nhanvat sao[4]{
nhanvat(gALL," ",0,0),
nhanvat(gALL,"data/1sao.png",872,295),
nhanvat(gALL,"data/2sao.png",767,322),
nhanvat(gALL,"data/3sao.png",767,300)
};
Text textDiem(gALL, "data/KOMIKAX_.ttf", 65,  intToString(diem).c_str(),  { 255, 255, 255,255 },  1600, 490);
Text textLevel(gALL, "data/KOMIKAX_.ttf", 65,  ("level "+intToString(level)).c_str(),  { 255, 255, 255,255 },  1580, 770);
Text textTimeHoiKhien(gALL,"data/arial.ttf",30,(intToString(timeTextHoiKhien)+"S").c_str(),{ 255, 255, 255 },143,963);
Text textTimeHoiTocBien(gALL,"data/arial.ttf",30,(intToString(timeTextHoiTocBien)+"s").c_str(),{ 255, 255, 255 },243,963);
Text textTamDung(gALL, "data/KOMIKAX_.ttf", 75,"press \"T\" to continue",  { 255, 255, 255,255 },  400, 490);

//huong dan
Text QE(gALL,"data/3Dumb.ttf",30,"Q-E",{ 255, 255, 255 },245,970);
Text B(gALL,"data/3Dumb.ttf",30," B ",{ 255, 255, 255 },153,970);

SDL_Rect sizeHP;
SDL_Rect sizeCat;
SDL_Rect khungXYWHnhanVat;
SDL_Rect khungXYWHbia[5];
SDL_Rect khungXYWHbom[3];
const Uint8 * keyState;

int runCheDoVatPham(std::string name)
{
    sizeCat.x = 0;
    sizeCat.y = 0;
    sizeCat.w = chieuRongKhungNhanVat;
    sizeCat.h = chieuCaoKhungNhanVat;
    
    khungXYWHnhanVat.w=chieuRongKhungNhanVat;
    khungXYWHnhanVat.h=70;

    khungXYWHbom[0].w=69;
    khungXYWHbom[0].h=96;
    khungXYWHbom[1].w=99;
    khungXYWHbom[1].h=82;////82
    khungXYWHbom[2].w=83;
    khungXYWHbom[2].h=83;
    bool quit = false;
    
    if (!init())
    {
        std::cout<<"khong the khoi tao.";   
        return 1;
    }
    Text textName(gALL, "data/3Dumb.ttf", 35,  name.c_str(),  { 255, 255, 255,255 },  1550, 230);
    SDL_Event e;
    
    while (quit == false)
    {
        if (clock()-timeXuatHien>1000 && soLuongCoin<5&&arrCoinTrueFalse[soLuongCoin]==false)
        {
            timeXuatHien=clock();
            bia[soLuongCoin].updateToaDoX(ranDom());
            arrCoinTrueFalse[soLuongCoin]=true;
            // bia[soLuongCoin].updateToaDoX(ranDom());
            soLuongCoin++;
        }
        if (clock()-timeXuatHienBom>600 && soLuongBom<3&&arrBomTrueFalse[soLuongBom]==false)
        {
            timeXuatHienBom=clock();
            bom[soLuongBom].updateToaDoX(ranDom());
            arrBomTrueFalse[soLuongBom]=true;
            soLuongBom++;
        }
        if (soLuongCoin==5)
        {
            soLuongCoin=0;
        }
        if (soLuongBom==3)
        {
            soLuongBom=0;
        }
        
        keyState = SDL_GetKeyboardState(NULL);
        //Background
        gBackground.updateBeMat(gALL);
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT){
                quit = true;
                diem=-1000;
            }
            // int x, y;
            // SDL_GetMouseState(&x, &y);
            // if (e.type == SDL_MOUSEBUTTONDOWN) std::cout<<x<<" "<<y<<"\n";
        }
    
        //chay sang trai
        if(keyState[SDL_SCANCODE_A]||keyState[SDL_SCANCODE_LEFT]){
            //dang nghi,chay sang phai
            if (checkHoatDong==1||checkHoatDong==0||checkHoatDong==2){
                checkHoatDong=3;
                nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()-60);
                if (clock()-timecu>30)
                {
                    sizeCat.x += 90;
                    if (sizeCat.x >= 430)sizeCat.x = 0;
                    timecu=clock();
                }
            }
            //dang chay sang trai
            else if (checkHoatDong==3){
            nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()-pxDiChuyen);
            if (clock()-timecu>30)
                {
                    sizeCat.x += 90;
                    if (sizeCat.x >= 430)sizeCat.x = 0;
                    timecu=clock();
                }
            }
        }
        //chay sang phai
        else if(keyState[SDL_SCANCODE_D]||keyState[SDL_SCANCODE_RIGHT]){
            //dang nghi,chay sang trai
            if (checkHoatDong==0||checkHoatDong==1||checkHoatDong==3){
                checkHoatDong=2;
                nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()+60);
                if (clock()-timecu>1)
                {
                    sizeCat.x += 90;
                    if (sizeCat.x >= 430)sizeCat.x = 0;
                    timecu=clock();
                }
            }
            //dang chay sang phai
            else if(checkHoatDong==2){
                checkHoatDong=2;
                nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()+pxDiChuyen);
                if (clock()-timecu>1)
                {
                    sizeCat.x += 90;
                    if (sizeCat.x >= 430)sizeCat.x = 0;
                    timecu=clock();
                }
            }
        }
        //khien
        else if(keyState[SDL_SCANCODE_B]&&dangBaoVe==false&&clock()-timeKhien>timeHoiKhien){
            timeKhien=clock();
            dangBaoVe=true;
        }
        //tam dung
        else if (keyState[SDL_SCANCODE_ESCAPE]||keyState[SDL_SCANCODE_T])
        {
            hamTamDung(); 
              
        }
        
        //nhay
        if(keyState[SDL_SCANCODE_SPACE]&&nhay==false){
            nhay=true;
        }
        tatKhien();
        checkTocBien();
        xuLyNhay();
        trangThaiNhanVat();
        hamUpdateLevel();
        vaTram();
        //update toa do bom + vat pham
        for (int i = 0; i < 5; i++)
        {
            if (i<3)
            {
                if (arrBomTrueFalse[i]==true)
                {
                    bom[i].updateToaDoY(bom[i].returnToaDoY()+tocDoRoi+1);
                    
                }
            }
            
            if (arrCoinTrueFalse[i]==true)
            {
                bia[i].updateToaDoY(bia[i].returnToaDoY()+tocDoRoi);
            }
            
        }

        //update be mat
        
        //Tiền + bom
        for (int i = 0; i < 5; i++)
        {   
            bia[i].updateBeMat(gALL);
            if (i<3)
            {
                bom[i].updateBeMat(gALL);
            }
        }
        //nhân vật
        nhanVatgame.updateBeMat(gALL,sizeCat);
        //khien
        if (dangBaoVe==true)
        {
            khienChoNhanVat.updateToaDoX(nhanVatgame.returnToaDoX());
            khienChoNhanVat.updateToaDoY(nhanVatgame.returnToaDoY());
            khienChoNhanVat.updateBeMat(gALL);
        }
        //boss
        troNgaiOng.updateToaDoBosVaVaTram(gALL);
        //khung
        khungNoi.updateBeMat(gALL);
        // toc bien+khien
        upDateAnhXuatHienTocBienVsKhien();
        //nut chuc nang khi ddang choi
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x>1754&&x<1850&&y>0&&y<100)
        {
            nutChucNang.updateBeMat(gALL);
            
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                Mix_PlayChannel(-1, soundCoi, 0);    
            }
    
        }
        
        //thanh HP
        updateHP();
        //điểm
        textDiem.updateBeMatText(gALL, intToString(diem).c_str(),{ 255, 255, 255 });
        //leve
        textLevel.updateBeMatText(gALL,("Level "+intToString(level)).c_str(),{ 0, 0, 0 });
        //ten nguoi choi
        textName.updateBeMatText(gALL);

        //////////////
        // Cập nhật all
        SDL_UpdateWindowSurface(gWindow);
        // het mang
        if (HP==0)
        {
            quit=true;
        }
        //xoa
        SDL_FillRect(gALL, NULL, SDL_MapRGB(gALL->format, 0x00, 0x00, 0x00));
        SDL_Delay(7);
        
    }
	return diem;
}

void hamUpdateLevel(){
    if( (diem>=500&&level==1)||(diem>=1000&&level==2)||(diem>=1500&&level==3))
    {
        HP++;
        level++;
        hamEndGame();
        if (level==3)
        {
            tocDoRoi++;
        }
    }
    else if ((diem>=2000&&level==4)||(diem>=3000&&level==5)
    ||(diem>=5000&&level==6))
    {
        
        HP++;
        hamEndGame();
        level++;
        tocDoRoi++;
    }
    else if ((diem>=5500&&level==7)||(diem>=6000&&level==8))
    {
        HP++;
        hamEndGame();
        level++;
    }
    else if (diem>=7000&&level==9)
    {
        HP++;
        hamEndGame();
        level++;
        tocDoRoi++;
        pxDiChuyen++;
    }
    if ((diem>=2100&&level>=4)&&clock()-timeBossXuatHienLanTiep>10000)
    {
        timeBossXuatHienLanTiep=clock();
        checkBossDangHoatDong=true;
        troNgaiOng.khoiTaoLaiToaDo();
    } 
}

bool init(){
    gWindow = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN );
	if( gWindow == NULL ){
        std::cout<<( "Window could not be created! SDL_Error:\n", SDL_GetError() );
        return false;
    }
    gALL = SDL_GetWindowSurface( gWindow );
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)){
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);//
    music = Mix_LoadMUS("data/nhacnendotoc.mp3");
    Mix_PlayMusic(music, -1);
    soundCoi = Mix_LoadWAV("data/coin.wav");
    soundNo = Mix_LoadWAV("data/bomNo.wav");
    return true;
}
void hamTamDung(){
    bool quit=false;
    
    SDL_Delay(20);
    while (quit==false)
    {
        keyState = SDL_GetKeyboardState(NULL);
        SDL_Event e;
        if (keyState[SDL_SCANCODE_T])
        {
            Mix_PlayChannel(-1, soundCoi, 0);
            quit=true;
        }
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT){
                quit = true;
                diem=-1000;
            }        
        }
        gBackground.updateBeMat(gALL);
        nhanVatgame.updateBeMat(gALL,sizeCat);
        troNgaiOng.updateToaDoBosVaVaTram(gALL);
        //khung
        khungNoi.updateBeMat(gALL);
        upDateAnhXuatHienTocBienVsKhien();
        //thanh HP
        updateHP();
        //điểm
        textDiem.updateBeMatText(gALL, intToString(diem).c_str(),{ 255, 255, 255 });
        //leve
        textLevel.updateBeMatText(gALL,("Level "+intToString(level)).c_str(),{ 0, 0, 0 });
        textTamDung.updateBeMatText(gALL);
        SDL_UpdateWindowSurface(gWindow);
    }
}
void vaTram(){
    khungXYWHnhanVat.x=nhanVatgame.returnToaDoX();
    khungXYWHnhanVat.y=nhanVatgame.returnToaDoY();
    //khi va tram voi ong
    if((troNgaiOng.updateToaDoBosVaVaTram(gALL,khungXYWHnhanVat))==1&&checkBossDangHoatDong==true)
    {
        checkBossDangHoatDong=false;
        Mix_PlayChannel(-1, soundNo, 0);
        diem-=500;
        HP--;
    }
    for (int i = 0; i < 5; i++)
    {
        //lay toa do vat pham cho vao rect
        khungXYWHbia[i].x=bia[i].returnToaDoX();
        khungXYWHbia[i].y=bia[i].returnToaDoY();
        khungXYWHbia[i].w=50;
        khungXYWHbia[i].h=97;
        //lay toa do bom cho vao rect
        if (i<3)
        {
            khungXYWHbom[i].x=bom[i].returnToaDoX();
        }
        if (i==1)
        {
            khungXYWHbom[i].y=bom[i].returnToaDoY()+80;
        }
        else if (i==0||i==2){
            khungXYWHbom[i].y=bom[i].returnToaDoY();
        }
        //va tram voi vat pham
        if (SDL_HasIntersection(&khungXYWHnhanVat, &khungXYWHbia[i]))
        {
            Mix_PlayChannel(-1, soundCoi, 0);
            arrCoinTrueFalse[i]=false;
            diem+=100;
            bia[i].updateToaDoX(1900);
            bia[i].updateToaDoY(1);
            
        }
        //va tram voi bom
        if (i<3)
        {
            if (SDL_HasIntersection(&khungXYWHnhanVat, &khungXYWHbom[i]))
            {
                if (dangBaoVe==true)
                {
                    Mix_PlayChannel(-1, soundNo, 0);
                    arrBomTrueFalse[i]=false;
                    bom[i].updateToaDoX(1900);
                    bom[i].updateToaDoY(1);
                }
                else{
                    Mix_PlayChannel(-1, soundNo, 0);
                    arrBomTrueFalse[i]=false;
                    diem-=100;
                    HP--;
                    bom[i].updateToaDoX(1900);
                    bom[i].updateToaDoY(1);
                }
            }
        }
        
        if (bia[i].returnToaDoY()>1000)
        {
            int x=ranDom();
            arrCoinTrueFalse[i]=false;
            bia[i].updateToaDoX(1900);
            bia[i].updateToaDoY(1);
        }
        if (bom[i].returnToaDoY()>1000&&i<3)
        {
            int x=ranDom();
            arrBomTrueFalse[i]=false;
            bom[i].updateToaDoX(1900);
            bom[i].updateToaDoY(1);
        }
    }
    if (nhanVatgame.returnToaDoX()>1450)
    {
        nhanVatgame.updateToaDoX(1450);
    }
        
}
void trangThaiNhanVat(){
    // 0 = quay mặt sang phải
    // 1 = quay mặt sang trái
    // 2 = chạy sang phải
    // 3 = chạy sang trái
    // 4 = nhảy
    // 5 = ngã
    if (checkHoatDong==0)
    {
        sizeCat.y = 0;
    }
    else if (checkHoatDong==1)
    {
        sizeCat.y= chieuCaoKhungNhanVat*1;
    }
    else if (checkHoatDong==2)
    {
        sizeCat.y = chieuCaoKhungNhanVat*2;
    }
    else if (checkHoatDong==3)
    {
        sizeCat.y = chieuCaoKhungNhanVat*3;
    }
    else if (checkHoatDong==4)
    {
        sizeCat.y = chieuCaoKhungNhanVat*4;
    }
    else if (checkHoatDong==5)
    {
        sizeCat.y = chieuCaoKhungNhanVat*5;
    }
    if (clock()-timecu>100)
    {
        sizeCat.x += 90;
        timecu=clock();
        if (sizeCat.x >= 449)sizeCat.x = 0;
    }
}
void updateHP(){
    if (HP==3)
        {
            sizeHP.w = 158;
            sizeHP.h = 49;
            thanhHP.updateBeMat(gALL);
            
        }else if(HP==2)
        {
            
            sizeHP.w = 53*2;
            sizeHP.h = 49;
            thanhHP.updateBeMat(gALL,sizeHP);
        }
        else if (HP==1)
        {
            sizeHP.w = 53;
            sizeHP.h = 49;
            thanhHP.updateBeMat(gALL,sizeHP);
        }
        else if (HP==0)
        {
            sizeHP.w = 0;
            sizeHP.h = 0;
            thanhHP.updateBeMat(gALL,sizeHP);
        }
}

void close()
{
	bool arrCoinTrueFalse[5]{false,false,false,false,false};//vvật phẩm nài còn trên màn hình
    bool arrBomTrueFalse[3]{false,false,false};
    for (int i = 0; i < 5; i++)
    {
        bia[i].updateToaDoX(1850);
        if (i<3){
            bom[i].updateToaDoX(1850);
        }
    }
    diem=0;
    HP=3;
	SDL_DestroyWindow( gWindow );
}
void hamEndGame(){
    Text textLevelTruoc(gALL,"data/KOMIKAX_.ttf", 50,  ("level "+intToString(level)).c_str(),  { 255, 255, 255,255 },  820, 440);
    Text gach2soc(gALL,"data/KOMIKAX_.ttf", 50,  "||",  { 0, 0, 0,255 },  980, 500);
    Text V(gALL,"data/KOMIKAX_.ttf", 50,  "V",  { 0, 0, 0,255 },  984, 550);
    Text textLevelUp(gALL,"data/KOMIKAX_.ttf", 50,  ("level "+intToString(level)).c_str(),  { 0, 0, 255,255 },  820, 615);

    bool quit=false;
    int x, y;
    if (HP>3)
    {
        HP=3;
    }
    while (quit==false)
    {
    SDL_Event e;
        keyState = SDL_GetKeyboardState(NULL);
        if (keyState[SDL_SCANCODE_KP_ENTER])
        {
            Mix_PlayChannel(-1, soundCoi, 0);
            quit=true;  
        }
        endGame.updateBeMat(gALL);
        if (SDL_PollEvent(&e)){
            SDL_GetMouseState(&x, &y);
            if (x>841&&x<841+177&&y>738&&y<63+738)
            {
                nutNext.updateBeMat(gALL);
                if (e.type == SDL_MOUSEBUTTONDOWN) {
                    Mix_PlayChannel(-1, soundCoi, 0);
                    quit=true;              
                }                
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
            {
                Mix_PlayChannel(-1, soundCoi, 0);
                quit=true;  
            }
        }
        textLevelTruoc.updateBeMatText(gALL,("Level "+intToString(level)).c_str(),{ 0, 0, 0 });
        gach2soc.updateBeMatText(gALL);
        V.updateBeMatText(gALL);
        textLevelUp.updateBeMatText(gALL,("Level "+intToString(level+1)).c_str(),{ 0, 0, 255 });
        sao[HP].updateBeMat(gALL);
        SDL_UpdateWindowSurface(gWindow);
    }
}
void upDateAnhXuatHienTocBienVsKhien(){
    timeTextHoiTocBien=(int)(timeHoiTocBien-(clock()-timeTocBien));
    timeTextHoiKhien=(int)(timeHoiKhien-(clock()-timeKhien));
    tocBien.updateBeMat(gALL);
    khien.updateBeMat(gALL);
    if (timeTextHoiTocBien>0)
    {
        textTimeHoiTocBien.updateBeMatText(gALL,(intToString(timeTextHoiTocBien/1000)+","+intToString((timeTextHoiTocBien/10)%100)+"s").c_str(),{ 255, 255, 255 });    
    }
    else{
        QE.updateBeMatText(gALL);
    }
    if (timeTextHoiKhien>0)
    {
        textTimeHoiKhien.updateBeMatText(gALL,(intToString(timeTextHoiKhien/1000)+","+intToString((timeTextHoiKhien/10)%100)+"s").c_str(),{ 255, 255, 255 });
    }
    else
    {
        B.updateBeMatText(gALL);
    }
}
void checkTocBien(){
    // tocBientrai
    if(keyState[SDL_SCANCODE_Q]&&clock()-timeTocBien>timeHoiTocBien){
        timeTocBien=clock();
        //dang nghi,chay sang phai
        if (checkHoatDong==1||checkHoatDong==0||checkHoatDong==2){
            checkHoatDong=3;
            nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()-60-pxDichChuyen);
            if (clock()-timecu>30)
            {
                sizeCat.x += 90;
                if (sizeCat.x >= 430)sizeCat.x = 0;
                timecu=clock();
            }
        }
        //dang chay sang trai
        else if (checkHoatDong==3){
        nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()-pxDiChuyen-pxDichChuyen);
        if (clock()-timecu>30)
            {
                sizeCat.x += 90;
                if (sizeCat.x >= 430)sizeCat.x = 0;
                timecu=clock();
            }
        }
    }
    // tocbienphai
    else if(keyState[SDL_SCANCODE_E]&&clock()-timeTocBien>timeHoiTocBien){
        timeTocBien=clock();
        //dang nghi,chay sang trai
        if (checkHoatDong==0||checkHoatDong==1||checkHoatDong==3){
            checkHoatDong=2;
            nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()+60+pxDichChuyen);
            if (clock()-timecu>1)
            {
                sizeCat.x += 90;
                if (sizeCat.x >= 430)sizeCat.x = 0;
                timecu=clock();
            }
        }
        //dang chay sang phai
        else if(checkHoatDong==2){
            nhanVatgame.updateToaDoX(nhanVatgame.returnToaDoX()+pxDiChuyen+pxDichChuyen);
            if (clock()-timecu>1)
            {
                sizeCat.x += 90;
                if (sizeCat.x >= 430)sizeCat.x = 0;
                timecu=clock();
            }
        }
    }
}
void xuLyNhay(){
    //nhay len
    if (nhay==true&&buocNhay<=3)
    {
        nhanVatgame.updateToaDoY(nhanVatgame.returnToaDoY()-7);
        buocNhay++;
    }
    else if (buocNhay>3)
    {
        buocNhay=0;
        nhay=false;
    }
    //roi xuong
    if (nhay==false&&nhanVatgame.returnToaDoY()<=760)
    {
        nhanVatgame.updateToaDoY(nhanVatgame.returnToaDoY()+7);
    }
}
void tatKhien(){
    if (clock()-timeKhien>timeKhienDuyTri)
    {
        dangBaoVe=false;
    }
}


