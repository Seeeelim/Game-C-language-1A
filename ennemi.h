#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"



#define SCREEN_H 2000
#define SCREEN_W 2000

typedef struct 
{
SDL_Surface *TabES[2][10];
int num; 
SDL_Rect pos1;//partie qui sera afficher
SDL_Rect pos2;//position par rapport a lecran
int etat,collision;
Mix_Chunk M;
int direction;
}Ennemi;
typedef struct {    
SDL_Rect pos;
SDL_Rect pos_sprite;
SDL_Surface *spritesheet;
int numperso,up,direction; 
double vitesse,acceleration;
int vitesseV;
//vie
SDL_Surface *image_vie[5]; 
SDL_Rect position_vie ;
int val;
SDL_Rect position_texte;
}Personne ; 
typedef struct 
{
char *url;

SDL_Rect pos_img_affiche;
SDL_Rect pos_img_ecran;
SDL_Surface *img;
} image;


void initEnnemi(Ennemi *E);
void animerEnnemi( Ennemi * E);
void afficherEnnemi(Ennemi E, SDL_Surface  * screen);
void liberer_ennemi(Ennemi E);

void initialiser_imageBack(image *image);
void afficher_imageBMT(SDL_Surface *screen,image imge);
//void libere_image(image back);	
void move( Ennemi  *E);
//void afficherPerso(Perso P, SDL_Surface  * screen);
//void moveP( Perso  *P);
int collisionBB( Personne *P, Ennemi *E) ;
//void liberer_perso(Perso P);
//void initialiser_Perso(Perso  *P);

			
/*

int collisionBB( personne p, Ennemi e) ;				
void moveIA( Ennemi * e);
void libere_musique(Mix_Chunk *M);
	
			
*/
























#endif 
