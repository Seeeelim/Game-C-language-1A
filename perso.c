#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "game.h"



void initPerso(Personne *p)
{
p->spritesheet=IMG_Load("perso.png");
    
    

    p->direction=2;
    p->acceleration=0;
    p->vitesse=2;
    p->vitesseV=0;

    
    p->pos_sprite.x= 0;
    p->pos_sprite.y=200;
    p->pos_sprite.h= 100;
    p->pos_sprite.w=100 ;
    p->pos.x=50;
    p->pos.y=600;

}
void initPerso2(Personne *p2)
  
{ 
   p2->spritesheet=IMG_Load("perso.png");
    
    p2->pos.x=950;
    p2->pos.y=600;

    p2->direction=2;

    p2->acceleration=0;
    p2->vitesse=2;
   p2->vitesseV=0;

    
    p2->pos_sprite.x= 0;
    p2->pos_sprite.y= 200;//position d'un frame dans la spritesheet
    p2->pos_sprite.h= 100;//largeur d'un frame 
    p2->pos_sprite.w= 100;//hauteur d'un frame

}
void saut2 (Personne* p) {
    if (p->pos.y==850)
    {
        p->vitesseV=-40;
    }
    
}		
void afficherPerso(Personne p, SDL_Surface * screen)
{
	SDL_BlitSurface(p.spritesheet,&p.pos_sprite,screen,&p.pos);

}		
void movePerso (Personne *p,int dt)
{
	double dx;
	p->vitesse+=p->acceleration*dt;
    dx = 0.5 * p->acceleration * dt *dt + p->vitesse * dt ; 
    if ((p->direction==0) ) 
    {
        p->pos.x += dx ;
    }
    else if ((p->direction==1)) 
    p->pos.x -= dx ;

}
void movePersoA (Personne *p,int dt)
{
	double dx;
	p->vitesse+=p->acceleration*dt;
    dx =(p->acceleration+ p->vitesse) * dt ; 
    if ((p->direction==0) ) 
    {
        p->pos.x += dx ;
    }
    else if ((p->direction==1)) 
    p->pos.x -= dx ;

}	
void animerPerso (Personne* p)
{
	p->pos_sprite.x += 100;
    if (p->pos_sprite.x >= 1500)
     p->pos_sprite.x = 0;

    p->pos_sprite.y = 100;
    p->pos_sprite.y = p->direction * 100 ;

}		
void saut (Personne* p) 
{
    if (p->pos.y==850)
    {
        p->vitesseV=-40;
    }
    
}


void liberer_imageperso(Personne p)
{
	SDL_FreeSurface(p.spritesheet);
}

void afficher_texteP(texte txte,SDL_Surface *screen,double ratio)
{ 
	double compteur=0;
	
	char  score[20]="";  
	sprintf(score,"%.2f : score",ratio);
	txte.txt=TTF_RenderText_Blended(txte.police,score,txte.color_txt);
	SDL_BlitSurface(txte.txt,NULL,screen,&txte.pos_txt);
}

void liberer_texteP(texte txte)
{
	TTF_CloseFont(txte.police);
	TTF_Quit();
}
void initialiser_texteP(texte *txte)
{
	TTF_Init();
	txte->police =TTF_OpenFont("arial.ttf",80);
	txte->color_txt.r=255;
	txte->color_txt.g=255;
	txte->color_txt.b=255;
	txte->pos_txt.x=320;
	txte->pos_txt.y=0;
}












