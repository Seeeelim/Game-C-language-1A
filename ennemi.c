
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "game.h"



void initEnnemi1(Ennemi *E)
{
char ennemi[44];
int i,j;
for(j=0;j<2;j++)
{
for (i=0;i<9;i++)
{
sprintf(ennemi,"A/%d%d (Grand).png",j,i);
E->TabES[j][i]=IMG_Load(ennemi);
if(E->TabES[j][i]==NULL)
{
printf("unable %s\n", SDL_GetError());
return;
}
}
}
E->num=0;
E->direction=0;
E->pos1.x=500;
E->pos1.y=750;
E->pos2.x=0;
E->pos2.y=0;
E->state=WAITING;
	
}
void initEnnemi2(Ennemi *E)
{
char ennemi[44];
int i,j;
for(j=0;j<2;j++)
{
for (i=0;i<9;i++)
{
sprintf(ennemi,"A/%d%d (Grand).png",j,i);
E->TabES[j][i]=IMG_Load(ennemi);
if(E->TabES[j][i]==NULL)
{
printf("unable %s\n", SDL_GetError());
return;
}
}
}
E->num=0;
E->direction=0;
E->pos1.x=1000;
E->pos1.y=750;
E->pos2.x=0;
E->pos2.y=0;
E->state=WAITING;
	
}

void afficherEnnemi(Ennemi E, SDL_Surface  * screen)
{
int l,c;
l=E.direction;
c=E.num;
SDL_BlitSurface(E.TabES[l][c],NULL,screen,&E.pos1);  
}

void animerEnnemi( Ennemi * E)
{



if(E->num==8 )
{
E->num=0;


}
else
{

E->num++;

}




}



void moveE1( Ennemi  *E)

{
if(E->state==WAITING)
{

if(E->pos1.x>510 && E->direction==0 )
{ 
E->direction=1;


}


 else if(E->pos1.x<490 && E->direction==1)
{
E->direction=0;

}
 else if(E->direction==0 )
{
E->pos1.x=E->pos1.x+1;



}
else if(E->direction==1) 
{
E->pos1.x=E->pos1.x-1;
}

}
else if(E->state==FOLLOWING1 )
{
if(E->direction==1)
{

E->pos1.x=E->pos1.x-1;


}
else if(E->direction==0)
{

E->direction=1;
}
}
else if(E->state==FOLLOWING2 )
{
if(E->direction==0)
{

E->pos1.x=E->pos1.x+1;


}
else if(E->direction==1)
{

E->direction=0;
}
}
}


void moveE2( Ennemi  *E)

{
if(E->state==WAITING)
{

if(E->pos1.x>1010 && E->direction==0 )
{
E->direction=1;


}


 else if(E->pos1.x<990 && E->direction==1)
{
E->direction=0;

}
 else if(E->direction==0 )
{
E->pos1.x=E->pos1.x+1;



}
else if(E->direction==1) 
{
E->pos1.x=E->pos1.x-1;
}

}
else if(E->state==FOLLOWING1 )
{
if(E->direction==1)
{

E->pos1.x=E->pos1.x-1;


}
else if(E->direction==0)
{

E->direction=1;
}
}
else if(E->state==FOLLOWING2 )
{
if(E->direction==0)
{

E->pos1.x=E->pos1.x+1;


}
else if(E->direction==1)
{

E->direction=0;
}
}
}
void initialiser_imageBack(image *image)
{
image->url="back.jpg";
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
void afficher_imageBMT(SDL_Surface *screen,image imge)
{

SDL_BlitSurface(imge.img,NULL,screen,&imge.pos_img_ecran);


}
/*
void libere_image( image e)
{

SDL_FreeSurface(e.img);


}
*/
void liberer_ennemi(Ennemi E)
{
int i,j;

for(i=0;i<2;i++)
{
for(j=0;j<9;j++)
{
SDL_FreeSurface(E.TabES[i][j]);
}


}
}
int collisionBB( Personne P, Ennemi E) 
{
int k;
if((P.pos.x + 122< E.pos1.x) || (P.pos.x>  E.pos1.x + 122) || (P.pos.y+ 186<  E.pos1.y) || (P.pos.y>  E.pos1.y + 186))
{

k=0;
}
else
{

k=1;

}

return k;
}
void updateEnnemiState(Ennemi* E, int distEH) {
    switch (E->state) {
        case WAITING:
            if (distEH > 200) {
                E->state = WAITING;
            } else if (distEH <= -200) { 
                E->state = WAITING;
            } else if (10 < distEH && distEH <= 200) {
                E->state = FOLLOWING1;
            } else if (distEH <= -5 && distEH > -200) {
                E->state = FOLLOWING2; 
            }
            break;

        case FOLLOWING1:
            if (10 < distEH && distEH <= 200) {
                E->state = FOLLOWING1;
            } else if (0 < distEH && distEH <= 10) {
                E->state = ATTACKING1;
            } else if (distEH > 200) {
                E->state = WAITING;
            } else if (distEH <= -5 && distEH > -200) {
                E->state = FOLLOWING2;
            }
            break;

        case FOLLOWING2:
            if (distEH <= -5 && distEH > -200) {
                E->state = FOLLOWING2;
            } else if (distEH <= -200) {
                E->state = WAITING;
            } else if (distEH <= 0 && distEH > -5) {
                E->state = ATTACKING1; 
            } else if (10 < distEH && distEH <= 200) {
                E->state = FOLLOWING1;
            }
            break;

        case ATTACKING1:
            if (0 < distEH && distEH <= 10) {
                E->state = ATTACKING1; 
            } else if (distEH <= 0 && distEH > -5) {
                E->state = ATTACKING2;
            } else if (10 < distEH && distEH <= 200) {
                E->state = FOLLOWING1;
            } else if (distEH <= -5 && distEH > -200) {
                E->state = FOLLOWING2;
            }
            break;

        case ATTACKING2:
            if (distEH <= 0 && distEH > -5) {
                E->state = ATTACKING2; 
            } else if (distEH <= -5 && distEH > -200) {
                E->state = FOLLOWING2;
            } else if (0 < distEH && distEH <= 10) {
                E->state = ATTACKING1; 
            } else if (10 < distEH && distEH <= 200) {
                E->state = FOLLOWING1;
            }
            break;
    }
}
void moveAI1(Ennemi *E,Personne *P)
{int distEH;
distEH=E->pos1.x-P->pos.x;

updateEnnemiState (E, distEH);
switch(E->state)
   {
	case WAITING:
 
        moveE1(E);
        animerEnnemi(E);
	break;
	case FOLLOWING1:
        
          moveE1(E);
          animerEnnemi(E);
	break;
	case FOLLOWING2:
        
          moveE1(E);
          animerEnnemi(E);
	break;
	case ATTACKING1:
	E->direction=1;
	animerEnnemi(E);
	 

	break;
	case ATTACKING2:
	E->direction=0;
	animerEnnemi(E);
	 

	break;
		




}
}
void moveAI2(Ennemi *E,Personne *P)
{int distEH;
distEH=E->pos1.x-P->pos.x;

updateEnnemiState (E, distEH);
switch(E->state)
   {
	case WAITING:
 
        moveE2(E);
        animerEnnemi(E);
	break;
	case FOLLOWING1:
        
          moveE2(E);
          animerEnnemi(E);
	break;
	case FOLLOWING2:
        
          moveE2(E);
          animerEnnemi(E);
	break;
	case ATTACKING1:
	E->direction=1;
	animerEnnemi(E);
	 

	break;
	case ATTACKING2:
	E->direction=0;
	animerEnnemi(E);
	 

	break;
		




}
}


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
void liberer_musiquebref(Mix_Chunk *music)

{
Mix_FreeChunk(music);



}
