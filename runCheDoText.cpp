#include "khoitao.h"
const int SCREEN_WIDTH = 1850;//1850;//rộng
const int SCREEN_HEIGHT = 1000;
const int pxDichChuyen = 1500;


int toaDoYNhanVat=760;
int tocDoRoi=3;
int chieuCaoKhungNhanVat = 150;
int chieuRongKhungNhanVat = 90;
int soLuongTextTrue=0;//số lượng vật phẩm đang có trên màn hình
int diem=0;
int checkHoatDong=0;
int pxDiChuyen = 11;
int tongWordT=0;
int tongWordF=0;
int sttT=3;
int sttF=1;
//0=quay mặt sang phải
// 1 = quay mặt sang trái
// 2 = chạy sang phải
// 3 = chạy sang trái
// 4 = nhảy
// 5 = ngã

double timecu,timeXuatHien,timeXuatHienBom=0;

// 
bool arrCoinTrueFalse[3]{false,false,false};//vvật phẩm nài còn trên màn hình
bool arrBomTrueFalse=false;
bool checkLoa =true;
// cua so win
SDL_Window* gWindow = NULL;
//be mat de ve
SDL_Surface* gALL = NULL;
Mix_Music* music2 = NULL;
Mix_Chunk* soundCoi=NULL;
Mix_Chunk* soundNo=NULL;


Text textTrue[3]{
Text (gALL, "data/KOMIKAX_.ttf", 65,  intToString(diem).c_str(),  { 255, 255, 255,255 },  2000, 0),
Text (gALL, "data/KOMIKAX_.ttf", 65,  intToString(diem).c_str(),  { 255, 255, 255,255 },  2000, 0),
Text (gALL, "data/KOMIKAX_.ttf", 65,  intToString(diem).c_str(),  { 255, 255, 255,255 },  2000, 0),
};
Text textFalse(gALL, "data/KOMIKAX_.ttf", 65,  intToString(diem+2).c_str(),  { 255, 255, 255,255 },  2000, 0);

nhanvat khien(gALL,"data/khien.png",150,915);
nhanvat tocBien(gALL,"data/tocBien.png",250,915);
nhanvat gBackground(gALL,"data/anhnenchuan.png",0,0);
// nhanvat thanhHP(gALL,"data/3timmau.png", 1607,361);
nhanvat nutChucNang(gALL,"data/nutchucnangTrong.png",1754,0);
nhanvat khungNoi(gALL,"data/khunganhnenchuan.png",0,0);
nhanvat nhanVatgame(gALL,"data/nhanvatgame.png",600,toaDoYNhanVat);
// nhanvat khienChoNhanVat(gALL,"data/khienchonhanvat.png",600,toaDoYNhanVat);
nhanvat endGame(gALL,"data/manEndGame.png",688,200);
nhanvat nutNext(gALL,"data/nutnext.png",841,738);
// sao moix khi tawng lv

Text textDiem(gALL, "data/KOMIKAX_.ttf", 65,  intToString(diem).c_str(),  { 255, 255, 255,255 },  1600, 490);
Text textTamDung(gALL, "data/KOMIKAX_.ttf", 75,"press \"T\" to continue",  { 255, 255, 255,255 },  400, 490);

SDL_Rect sizeCat;
SDL_Rect khungXYWHnhanVat;
SDL_Rect khungXYWHtextTrue[3];
SDL_Rect khungXYWHtextFalse;
const Uint8 * keyState;
std::string arrT[3];
std::string arrF;
std::vector<std::string> wordsTrue;
std::vector<std::string> wordsFalse;

bool init(){
    gWindow = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN );
	if( gWindow == NULL ){
        std::cout<<( "Window could not be created! SDL_Error:\n", SDL_GetError() );
        return false;
    }
    gALL = SDL_GetWindowSurface( gWindow );
    int imgFlags = IMG_INIT_PNG;
    SDL_Init(SDL_INIT_AUDIO);
    if (!(IMG_Init(imgFlags) & imgFlags)){
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 2048);
    music2 = Mix_LoadMUS("data/nhacnendotoc2.mp3");
    if (checkLoa==true)Mix_PlayMusic(music2, -1);
    soundCoi = Mix_LoadWAV("data/coin.wav");
    soundNo = Mix_LoadWAV("data/bomNo.wav");
    
    return true;
}
bool layDuLieuFile(){
    //true
    std::ifstream file("data/dataTrue.txt");
    if (!file) {
        std::cout << "khong mo dc tep T " << std::endl;
        return false;
    }
    std::string word;
    while (file >> word) { // đọc từng từ trong tệp
        wordsTrue.push_back(word); // đưa từ vào vector
    }
    tongWordT=wordsTrue.size();
    file.close();
    //false
    std::ifstream file2("data/dataF.txt");
    if (!file2) {
        std::cout << "khong mo dc tep F" << std::endl;
        return false;
    }
    while (file2 >> word) { // đọc từng từ trong tệp
        wordsFalse.push_back(word); // đưa từ vào vector
    }
    file2.close();
    tongWordF=wordsFalse.size();
    // for (int i = 0; i < wordsTrue.size(); i++) { // duyệt qua các phần tử trong vector
    //     std::cout << wordsTrue[i] <<wordsFalse[i]<< std::endl; // in từ ra màn hình
    // }
    arrT[0]=wordsTrue[0];
    arrT[1]=wordsTrue[1];
    arrT[2]=wordsTrue[2];
    arrF=wordsFalse[0];
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
        //khung
        khungNoi.updateBeMat(gALL);

        //điểm
        textDiem.updateBeMatText(gALL, intToString(diem).c_str(),{ 255, 255, 255 });
        textTamDung.updateBeMatText(gALL);
        SDL_UpdateWindowSurface(gWindow);
    }
}
void vaTram(){
    int W,H;
    khungXYWHnhanVat.x=nhanVatgame.returnToaDoX();
    khungXYWHnhanVat.y=nhanVatgame.returnToaDoY();
    //lay toa do bom cho vao rect
    khungXYWHtextFalse.x=textFalse.returnToaDoX();
    khungXYWHtextFalse.y=textFalse.returnToaDoY();
    textFalse.updateWH(arrF.c_str(),W,H);
    khungXYWHtextFalse.w=W;
    khungXYWHtextFalse.h=H;
    for (int i = 0; i < 3; i++)
    {
        //lay toa do vat pham cho vao rect
        khungXYWHtextTrue[i].x=textTrue[i].returnToaDoX();
        khungXYWHtextTrue[i].y=textTrue[i].returnToaDoY();
        textTrue[i].updateWH(arrT[i].c_str(),W,H);
        khungXYWHtextTrue[i].w=W;
        khungXYWHtextTrue[i].h=H;
        //va tram voi vat pham
        if (SDL_HasIntersection(&khungXYWHnhanVat, &khungXYWHtextTrue[i]))
        {
            Mix_PlayChannel(-1, soundCoi, 0);
            arrCoinTrueFalse[i]=false;
            diem+=100;
            textTrue[i].updateToaDoX(1900);
            textTrue[i].updateToaDoY(1);
            arrT[i]=wordsTrue[sttT];
            sttT++;
        }
        //va tram voi bom
            if (SDL_HasIntersection(&khungXYWHnhanVat, &khungXYWHtextFalse))
            {
                    Mix_PlayChannel(-1, soundNo, 0);
                    arrBomTrueFalse=false;
                    diem-=100;
                    textFalse.updateToaDoX(1900);
                    textFalse.updateToaDoY(1);
                    arrF=wordsFalse[sttF];
                    sttF++;
            }
 
        
        if (textTrue[i].returnToaDoY()>1000&&sttT<=tongWordT)
        {
            int x=ranDom();
            arrCoinTrueFalse[i]=false;
            arrT[i]=wordsTrue[sttT];
            textTrue[i].updateToaDoX(1900);
            textTrue[i].updateToaDoY(1);
            sttT++;
        }
    }
    if (textFalse.returnToaDoY()>1000&&sttF<=tongWordF)
    {
        int x=ranDom();
        arrBomTrueFalse=false;
        arrF=wordsFalse[sttF];
        textFalse.updateToaDoX(1900);
        textFalse.updateToaDoY(1);
        sttF++;
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
void close()
{
	bool arrCoinTrueFalse[3]{false,false,false};//vvật phẩm nài còn trên màn hình
    bool arrBomTrueFalse=false;
    for (int i = 0; i < 3; i++)
    {
        textTrue[i].updateToaDoX(1850);
    }
    textFalse.updateToaDoX(1850);
    diem=0;
	SDL_DestroyWindow( gWindow );
}
void hamEndGame(){
    Text gach2soc(gALL,"data/KOMIKAX_.ttf", 50,  "||",  { 0, 0, 0,255 },  980, 500);
    Text V(gALL,"data/KOMIKAX_.ttf", 50,  "V",  { 0, 0, 0,255 },  984, 550);

    bool quit=false;
    int x, y;
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
        gach2soc.updateBeMatText(gALL);
        V.updateBeMatText(gALL);
        SDL_UpdateWindowSurface(gWindow);
    }
}
int main( int argc, char* args[] )
{
    layDuLieuFile();
    std::string name ="tung";
    sizeCat.x = 0;
    sizeCat.y = 0;
    sizeCat.w = chieuRongKhungNhanVat;
    sizeCat.h = chieuCaoKhungNhanVat;
    
    khungXYWHnhanVat.w=chieuRongKhungNhanVat;
    khungXYWHnhanVat.h=70;

    khungXYWHtextFalse.w=69;
    khungXYWHtextFalse.h=96;

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
        if (clock()-timeXuatHien>1000 && soLuongTextTrue<5&&arrCoinTrueFalse[soLuongTextTrue]==false)
        {
            timeXuatHien=clock();
            textTrue[soLuongTextTrue].updateToaDoX(ranDom());
            arrCoinTrueFalse[soLuongTextTrue]=true;
            soLuongTextTrue++;
        }
        if (clock()-timeXuatHienBom>600 &&arrBomTrueFalse==false)
        {
            timeXuatHienBom=clock();
            textFalse.updateToaDoX(ranDom());
            arrBomTrueFalse=true;

        }
        if (soLuongTextTrue==3)
        {
            soLuongTextTrue=0;
        }
        
        keyState = SDL_GetKeyboardState(NULL);
        //Background
        gBackground.updateBeMat(gALL);
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT){
                quit = true;
                // khi ấn thoát
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

        //tam dung
        else if (keyState[SDL_SCANCODE_ESCAPE]||keyState[SDL_SCANCODE_T])
        {
            hamTamDung(); 
              
        }
        trangThaiNhanVat();
        vaTram();
        //update toa do bom + vat pham
        if (arrBomTrueFalse==true)
        {
            textFalse.updateToaDoY(textFalse.returnToaDoY()+tocDoRoi+1);
            
        }
        for (int i = 0; i < 3; i++)
        {
            
            if (arrCoinTrueFalse[i]==true)
            {
                textTrue[i].updateToaDoY(textTrue[i].returnToaDoY()+tocDoRoi);
            }
            
        }

        //update be mat
        
        //Tiền + bom
        for (int i = 0; i < 3; i++)
        {   
            textTrue[i].updateBeMatText(gALL,arrT[i].c_str(),{255,255,255});
        }
        textFalse.updateBeMatText(gALL,arrF.c_str(),{255,255,255});
        //nhân vật
        nhanVatgame.updateBeMat(gALL,sizeCat);
        //khung
        khungNoi.updateBeMat(gALL);
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
        //điểm
        textDiem.updateBeMatText(gALL, intToString(diem).c_str(),{ 255, 255, 255 });
        //ten nguoi choi
        textName.updateBeMatText(gALL);

        //////////////
        // Cập nhật all
        SDL_UpdateWindowSurface(gWindow);
        //xoa
        SDL_FillRect(gALL, NULL, SDL_MapRGB(gALL->format, 0x00, 0x00, 0x00));
        SDL_Delay(7);
        
    }
	return 0;
}