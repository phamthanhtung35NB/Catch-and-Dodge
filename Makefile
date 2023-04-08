all:
	g++ -I src/include -L src/lib -o main run.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
//git mergetool kdiff3