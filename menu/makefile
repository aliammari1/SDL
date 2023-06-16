prog:main.o menu.o
	gcc menu.o main.o -o prog -lSDL -lSDL_ttf -g -lSDL_image  -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
menu.o:menu.c
	gcc -c menu.c -g