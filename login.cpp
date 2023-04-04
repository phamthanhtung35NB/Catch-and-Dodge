
//check cos tk chua
// bool check();
// tao tk or dang nhap
// std::string loginTK();
// nhập thông tin tk
// void nhap();
// std::string check();
// void updateFile();
bool init();
bool load();
void close();
const int SCREEN_WIDTH = 1500;//1850;//rộng
const int SCREEN_HEIGHT = 1000;
SDL_Window* gwindow = NULL;
SDL_Surface* gALL = NULL;
SDL_Surface* gBackground = NULL;
TTF_Font* font = NULL;
SDL_Renderer* nhaptk = NULL;
// SDL_Renderer* gRenderer = NULL;

SDL_Surface* buttonSurface=NULL;
SDL_Surface* tenDangNhap = NULL;
SDL_Surface* matkhau =NULL;
SDL_Surface* login =NULL;
SDL_Rect ToadoTenDangNhap;
SDL_Rect ToadoMatKhau;
SDL_Rect ToadoLogin;
SDL_Rect buttonLogin = {1097, 702, 200, 30 };;
// std::string line, name_, pass_,diem_,stt_;

bool init(){
	bool check = true;
	// Khởi tạo SDL2 và TTF
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout<<"SDL_ERROR: \n"<<SDL_GetError();
		check = false;
    }
    if (TTF_Init() < 0) {
		std::cout<<"SDL_ttf could not initialize! SDL_ttf Error: \n"<<SDL_GetError();
        check = false;
    }
		// Tạo cửa sổ
    gwindow = SDL_CreateWindow("LOGIN", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gwindow == NULL) {
        printf("gwindow could not be created! SDL_Error: %s\n", SDL_GetError());
        check = false;
    }

    // Tạo bề mặt của cửa sổ
    gALL = SDL_GetWindowSurface(gwindow);
    // Tạo renderer
	nhaptk = SDL_CreateRenderer(gwindow, -1, SDL_RENDERER_ACCELERATED);

    if (nhaptk == NULL) {
        check== false;
    }
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	return check;
}
bool load(){
	bool check = true;
	gBackground = IMG_Load( "data/backgrounlogin.png" );
	if( gBackground == NULL )
	{
		std::cout<<( "Khong load duoc anh Background.\n");
		check = false;
	}

    // Tạo font chữ
	font = TTF_OpenFont("data/3Dumb.ttf", 48);
    // font = TTF_OpenFont("path/to/font.ttf", 48);
    if (font == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        check = false;
    }
    buttonSurface = IMG_Load("data/xacnhan.png");
    
    // Tạo bề mặt văn bản
    // SDL_Color textColor = { };
	matkhau = TTF_RenderText_Solid(font,"Password", {0, 225, 255 });
    tenDangNhap = TTF_RenderText_Solid(font, "User Name", {0, 225, 255 });
	login = TTF_RenderText_Solid(font, "Login", {0, 225, 255 });
    if (tenDangNhap == NULL||matkhau== NULL) {
        printf("Failed to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        check = false;
    }
	return check;
}
void gameLoop()
{
    bool quit = false;
    SDL_Event e;
    int mouseX, mouseY;
    bool mouseLeftDown = false;
	std::string username = "";
    std::string password = "";
	SDL_Color textColor = { 0, 0, 0, 255 };

    SDL_Rect usernameRect = { 100, 100, 200, 30 };
    SDL_Rect passwordRect = { 100, 150, 200, 30 };
    SDL_Rect messageRect = { 100, 200, 200, 30 };
    if (init())
	{
		if (load())
		{
			// Thiết lập vị trí của văn bản trên màn hình
    		ToadoTenDangNhap.x = 1100;//(gALL->w - tenDangNhap->w) / 2;
			ToadoTenDangNhap.y = 240;
			ToadoMatKhau.x = 1100;//(gALL->w - tenDangNhap->w) / 2;
			ToadoMatKhau.y = 440;
			ToadoLogin.x=1160;
			ToadoLogin.y=722;
			SDL_BlitSurface(gBackground, NULL, gALL, NULL);
			// Hiển thị văn bản trên màn hình
			SDL_BlitSurface(tenDangNhap, NULL, gALL, &ToadoTenDangNhap);
			SDL_BlitSurface(matkhau, NULL, gALL,&ToadoMatKhau);
			SDL_BlitSurface(login, NULL, gALL,&ToadoLogin);
			SDL_UpdateWindowSurface(gwindow);

			// SDL_Delay(2000);
			// 	// Xóa văn bản khỏi màn hình
			// SDL_FillRect(gALL, &ToadoTenDangNhap, SDL_MapRGB(gALL->format, 0, 0, 0));
            while (!quit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                    
                    if (e.type == SDL_MOUSEBUTTONDOWN) {
                        int mouseX = e.button.x;
                        int mouseY = e.button.y;
                        if (mouseX >= buttonLogin.x && mouseX < buttonLogin.x + buttonLogin.w && mouseY >= buttonLogin.y && mouseY < buttonLogin.y + buttonLogin.h) {
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Thông báo", "Đăng nhập thành công!", gwindow);
                        }
                    }
                    SDL_BlitSurface(gBackground, NULL, gALL, NULL);
                    // Hiển thị văn bản trên màn hình
                    SDL_BlitSurface(tenDangNhap, NULL, gALL, &ToadoTenDangNhap);
                    SDL_BlitSurface(matkhau, NULL, gALL,&ToadoMatKhau);
                    // SDL_BlitSurface(login, NULL, gALL,&ToadoLogin);
                    SDL_BlitSurface(buttonSurface, NULL, gALL, &buttonLogin);
                    SDL_BlitSurface(login, NULL, gALL,&ToadoLogin);
                    SDL_UpdateWindowSurface(gwindow);
                    
                    // if (e.type == SDL_QUIT)
                    // {
                    //     quit = true;
                    // }
                    // else if (e.type == SDL_MOUSEBUTTONDOWN)
                    // {
                    //     if (e.button.button == SDL_BUTTON_LEFT)
                    //     {
                    //         mouseLeftDown = true;
                    //     }
                    // }
                    // else if (e.type == SDL_MOUSEBUTTONUP)
                    // {
                    //     if (e.button.button == SDL_BUTTON_LEFT)
                    //     {
                    //         mouseLeftDown = false;
                    //     }
                    // }
                    else if (e.type == SDL_MOUSEMOTION)
                    {
                        mouseX = e.motion.x;
                        mouseY = e.motion.y;
                        std::cout<<mouseX<<" "<<mouseY<<"\n";
                    }
                                    // // Xử lý các thao tác chuột
                    // if (mouseLeftDown)
                    // {
                    //     // Khi nhấn chuột trái
                    // }
                    // else
                    // {
                    //     // Khi thả chuột trái
                    // }
                    
                    // Cập nhật và vẽ hình ảnh của game
                    // SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    // SDL_RenderClear(gRenderer);
                        // Vẽ hình ảnh game tại đây
                    
                //      SDL_RenderPresent(gRenderer);
                }
                

            }
		}

	}
}


SDL_Texture* createTextTexture(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, SDL_Color textColor) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
void close()
{
    // Giải phóng bộ nhớ và thoát
    SDL_FreeSurface(tenDangNhap);
	SDL_DestroyRenderer(nhaptk);
	SDL_FreeSurface(matkhau);
    TTF_CloseFont(font);
    SDL_DestroyWindow(gwindow);
    TTF_Quit();
    SDL_Quit();
}

	// //Deallocate surface
	// SDL_FreeSurface( gBackground );
	// gBackground = NULL;
    
    // //
    // SDL_FreeSurface(gNhanVatLeft);
    // gNhanVatLeft = NULL;

    // SDL_FreeSurface(gNhanVatRight);
    // gNhanVatRight = NULL;
	// //Destroy gwindow
	// SDL_DestroyWindow( gWindow );
	// gWindow = NULL;

	// //Quit SDL subsystems
	// SDL_Quit();
// }

/* std::string checkTrongFile(){
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
*/

int main(int argc, char* args[]){
	gameLoop();
	close();
	return 0;
}