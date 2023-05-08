all:
	g++ -I src/include -L src/lib -o main main.cpp runCheDoVatPham.cpp manHinhKhoiDong.cpp khoitao.cpp endGame.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf && .\\main
run:
	./main
test:
	g++ -I src/include -L src/lib -o testText runCheDoText.cpp khoitao.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# git mergetool kdiff3
# kdiff3: một công cụ so sánh/ghép đa cửa sổ trên Windows, macOS và Linux.