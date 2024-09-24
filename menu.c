

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "game.h"

/*void initbackground(image *IMAGE)
{

IMAGE->url="back.jpg";
IMAGE->img=IMG_Load(IMAGE->url);
if(IMAGE->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
IMAGE->pos_img_ecran.x=0;
IMAGE->pos_img_ecran.y=0;
IMAGE->pos_img_affiche.x=0;
IMAGE->pos_img_affiche.y=0;
IMAGE->pos_img_affiche.h=SCREEN_H;
IMAGE->pos_img_affiche.w=SCREEN_W;



}

*/
void initbackground(BackgroundM *B)
{
	char animation[74];
	int i;
	for (i=1;i<=73;i++)
	{
		sprintf(animation,"animation/%d (Grand).jpg",i);
		B->img[i]=IMG_Load(animation);

		if(B->img[i]==NULL)
		{
			printf("unable %s\n", SDL_GetError());
			return;
			}
	}
	B->num=0;

	
	B->pos1.x=0;
	B->pos1.y=0;

	B->pos1.w=(SCREEN_W);
	B->pos1.h=(SCREEN_H);
}

void initialiser_imageBack2(image *image)
{
image->url="back2.jpg";
image->img=IMG_Load(image->url);
if(image->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
image->pos_img_ecran.x=0;
image->pos_img_ecran.y=0;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;

}
void initialiser_imageBackleeevel(image *image)
{
image->url="level2.png";
image->img=IMG_Load(image->url);
if(image->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
image->pos_img_ecran.x=0;
image->pos_img_ecran.y=0;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;

}
void initialiser_imagebackplayer(image *image)
{
image->url="backplayer.jpg";
image->img=IMG_Load(image->url);
if(image->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
image->pos_img_ecran.x=0;
image->pos_img_ecran.y=0;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;

}


void initialiser_imagepause(image *image)
{

image->url="pause.png";
image->img=IMG_Load(image->url);
if(image->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
image->pos_img_ecran.x=0;
image->pos_img_ecran.y=0;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;

}
void initialiser_imageBMT10(image *image)
{


image->url="fullscreen.png";
image->img=IMG_Load(image->url);
if(image->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}

image->pos_img_ecran.x=720;
image->pos_img_ecran.y=500;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;





}

void initialiser_imageBMT1(image *imgbtn)

{
imgbtn->url="play.png";
imgbtn->img=IMG_Load(imgbtn->url);
if(imgbtn->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
imgbtn->pos_img_affiche.x=400;
imgbtn->pos_img_affiche.y=400;
imgbtn->pos_img_affiche.w=400;
imgbtn->pos_img_affiche.h=400;
imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/5);
imgbtn->pos_img_ecran.y=((SCREEN_W-imgbtn->pos_img_affiche.h)/6);



}

void initialiser_imageBMT2(image *imgbtn)
{

imgbtn->url="exit.png";
imgbtn->img=IMG_Load(imgbtn->url);
if(imgbtn->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
imgbtn->pos_img_affiche.x=400;
imgbtn->pos_img_affiche.y=700;
imgbtn->pos_img_affiche.w=400;
imgbtn->pos_img_affiche.h=700;
imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/5);
imgbtn->pos_img_ecran.y=(2*(SCREEN_W-imgbtn->pos_img_affiche.h)/6);

}
void initialiser_imageBMT3(image *imgbtn)
{

imgbtn->url="settings.png";
imgbtn->img=IMG_Load(imgbtn->url);
if(imgbtn->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
imgbtn->pos_img_affiche.x=400;
imgbtn->pos_img_affiche.y=800;
imgbtn->pos_img_affiche.w=400;
imgbtn->pos_img_affiche.h=800;
imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/5);
imgbtn->pos_img_ecran.y=(3*(SCREEN_W-imgbtn->pos_img_affiche.h)/6);

}
void initialiser_imageBMT1a(image *imgbtn)

{
imgbtn->url="play2.png";
imgbtn->img=IMG_Load(imgbtn->url);
if(imgbtn->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
imgbtn->pos_img_affiche.x=400;
imgbtn->pos_img_affiche.y=400;
imgbtn->pos_img_affiche.w=400;
imgbtn->pos_img_affiche.h=400;
imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/5);
imgbtn->pos_img_ecran.y=((SCREEN_W-imgbtn->pos_img_affiche.h)/6);



}

void initialiser_imageBMT2a(image *imgbtn)
{

imgbtn->url="exit2.png";
imgbtn->img=IMG_Load(imgbtn->url);
if(imgbtn->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
imgbtn->pos_img_affiche.x=400;
imgbtn->pos_img_affiche.y=700;
imgbtn->pos_img_affiche.w=400;
imgbtn->pos_img_affiche.h=700;
imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/5);
imgbtn->pos_img_ecran.y=(2*(SCREEN_W-imgbtn->pos_img_affiche.h)/6);

}
void initialiser_imageBMT3a(image *imgbtn)
{

imgbtn->url="settings2.png";
imgbtn->img=IMG_Load(imgbtn->url);
if(imgbtn->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
imgbtn->pos_img_affiche.x=400;
imgbtn->pos_img_affiche.y=800;
imgbtn->pos_img_affiche.w=400;
imgbtn->pos_img_affiche.h=800;
imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/5);
imgbtn->pos_img_ecran.y=(3*(SCREEN_W-imgbtn->pos_img_affiche.h)/6);

}
void initialiser_imageBMT4(image *image)
{

image->url="retour.png";
image->img=IMG_Load(image->url);
if(image->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}

image->pos_img_ecran.x=400;
image->pos_img_ecran.y=200;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;



}



void initialiser_imageBMT7(image *image)
{

image->url="plus.png";
image->img=IMG_Load(image->url);
if(image->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}

image->pos_img_ecran.x=400;
image->pos_img_ecran.y=400;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;





}
void initialiser_imageBMT8(image *image)
{


image->url="min.png";
image->img=IMG_Load(image->url);
if(image->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}

image->pos_img_ecran.x=720;
image->pos_img_ecran.y=400;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;





}
void initialiser_imageBMT9(image *image)
{
image->url="rectangle.png";
image->img=IMG_Load(image->url);
if(image->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
image->pos_img_ecran.x=250;
image->pos_img_ecran.y=0;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;

}

void initialiser_imageplayer(image *image)
{
image->url="player.png";
image->img=IMG_Load(image->url);
if(image->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
image->pos_img_ecran.x=400;
image->pos_img_ecran.y=100;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;

}
/////////////////////////////////////////////////////////////////////////////////////////
void initialiser_imageCHARGER(image *image)
{
image->url="charger.png";
image->img=IMG_Load(image->url);
if(image->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
image->pos_img_ecran.x=400;
image->pos_img_ecran.y=250;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;

}
/////////////////////////////////////////////////////////////////////////////////////////
void initialiser_imagemultiplayer(image *image)
{
image->url="multiplayer.png";
image->img=IMG_Load(image->url);
if(image->img==NULL)
{

printf("unable to load background image %s \n",SDL_GetError());
return;

}
image->pos_img_ecran.x=400;
image->pos_img_ecran.y=400;
image->pos_img_affiche.x=0;
image->pos_img_affiche.y=0;
image->pos_img_affiche.h=SCREEN_H;
image->pos_img_affiche.w=SCREEN_W;

}


/*
void afficher_imageBMT(SDL_Surface *screen,image imge)
{

SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);


}
void liberer_image(image imge)
{

SDL_FreeSurface(imge.img);


}
*/



void initialiser_musique(Mix_Music *music)
{
if(Mix_OpenAudio(44110,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1);
{
printf("%s",SDL_GetError());


}

music=Mix_LoadMUS("dramatic.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME/5);

}
void liberer_musique( Mix_Music *music)

{
Mix_FreeMusic(music);



}
/*
void liberer_musiquebref(Mix_Chunk *music)

{
Mix_FreeChunk(music);



}
*/
/*
void initialiser_musiquebref(Mix_Chunk *music)
{

Mix_OpenAudio(44110,MIX_DEFAULT_FORMAT,2,2048);






music=Mix_LoadWAV("son.wav");
Mix_PlayChannel(-1,music,0);
if(music==NULL)
{

printf("%s",SDL_GetError());

}



}
*/


void initialiser_texte(texte *txte)
{
TTF_Init();

txte->police=TTF_OpenFont("Young.ttf",135);
txte->color_txt.r=193;
txte->color_txt.g=223;
txte->color_txt.b=240;
txte->pos_txt.x=300;
txte->pos_txt.y=70;

}
void afficher_texte(SDL_Surface *screen,texte txte)
{

txte.txt=TTF_RenderText_Blended(txte.police,"CITYSCAPE",txte.color_txt);

SDL_BlitSurface(txte.txt, NULL,screen,&txte.pos_txt);



}
void initialiser_texteV(texte *txte)
{
TTF_Init();

txte->police=TTF_OpenFont("Virgo.ttf",45);
txte->color_txt.r=0;
txte->color_txt.g=0;
txte->color_txt.b=0;
txte->pos_txt.x=400;
txte->pos_txt.y=300;

}
void afficher_texteV(SDL_Surface *screen,texte txte)
{

txte.txt=TTF_RenderText_Blended(txte.police,"VOLUME",txte.color_txt);

SDL_BlitSurface(txte.txt, NULL,screen,&txte.pos_txt);



}
void initialiser_texteS(texte *txte)
{
TTF_Init();

txte->police=TTF_OpenFont("Young.ttf",70);
txte->color_txt.r=205;
txte->color_txt.g=57;
txte->color_txt.b=220;
txte->pos_txt.x=450;
txte->pos_txt.y=0;
}
void afficher_texteS(SDL_Surface *screen,texte txte)
{

txte.txt=TTF_RenderText_Blended(txte.police,"",txte.color_txt);

SDL_BlitSurface(txte.txt, NULL,screen,&txte.pos_txt);



}
void initialiser_texteF(texte *txte)
{
TTF_Init();

txte->police=TTF_OpenFont("Young.ttf",30);
txte->color_txt.r=0;
txte->color_txt.g=0;
txte->color_txt.b=0;
txte->pos_txt.x=400;
txte->pos_txt.y=500;
}
void afficher_texteF(SDL_Surface *screen,texte txte)
{

txte.txt=TTF_RenderText_Blended(txte.police,"FULLSCREEN",txte.color_txt);

SDL_BlitSurface(txte.txt, NULL,screen,&txte.pos_txt);



}

void liberer_imageback(BackgroundM imge)
{
int i;

for(i=1;i<73;i++)
{
SDL_FreeSurface(imge.img[i]);
}


}
void liberer_image(image imge)
{
SDL_FreeSurface(imge.img);
}


