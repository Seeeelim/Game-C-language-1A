prog:ennemi.o perso.o  main.o background.o menu.o sauvegarde.o enigme.o
	gcc ennemi.o perso.o  main.o background.o  menu.o sauvegarde.o enigme.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer  -g

main.o: main.c
	gcc -c main.c 
ennemi.o:ennemi.c
	gcc -c ennemi.c 
perso.o:perso.c
	gcc -c perso.c 
background.o:background.c
	gcc -c background.c 

sauvegarde.o:sauvegarde.c
	gcc -c sauvegarde.c
enigme.o:enigme.c
	gcc -c enigme.c


menu.o:menu.c
	gcc -c menu.c
