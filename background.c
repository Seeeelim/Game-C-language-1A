#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "game.h"
void initBack(Background * b){
b->camera.x=0;
b->camera.y=0;
b->camera.w=4953;
b->camera.h=1000;
b->camera2.x=0;
b->camera2.y=0;
b->camera2.w=4953;
b->camera2.h=1000;
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
char animation[63];
	int i;
	for (i=2;i<=43;i++)
	{
		sprintf(animation,"animation/%d.png",i);
		b->imagebg[i] = IMG_Load(animation);

		
	}
b->musique = Mix_LoadMUS("dramatic.mp3");
Mix_PlayMusic(b->musique, -1);

}

void scrolling (SDL_Rect * b, int direction,int direction2,int wigth,int hight ){
int save=b->x;
int s=b->y;
b->x+=5*direction;
if(b->x>wigth-1500){
b->x=0;}
if(b->x<0){
b->x=3253;
}

b->y+=5*direction2;
if(b->y<0 ||b->y>hight-900){
b->y=s;

}
}
void QuitBack(Background * b){
int i;
for(i=2;i<44;i++){
SDL_FreeSurface(b->imagebg[i]);
}
Mix_FreeMusic(b->musique);
Mix_CloseAudio();
}

void QuitBackk(BackgroundL1  b){
SDL_FreeSurface(b.imagebg);
Mix_FreeMusic(b.musique);
Mix_CloseAudio();
}
void initialiser_imagebacklevel1(BackgroundL1 *b)
{
b->camera.x=0;
b->camera.y=0;
b->camera.w=4953;
b->camera.h=1000;
b->camera2.x=0;
b->camera2.y=0;
b->camera2.w=4953;
b->camera2.h=1000;
b->url="hhh.jpg";
b->imagebg=IMG_Load(b->url);
if(b ->imagebg==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
b->musique = Mix_LoadMUS("dramatic.mp3");
Mix_PlayMusic(b->musique, -1);

}
  
