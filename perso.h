#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 1500
#define SCREEN_W 1500

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


typedef struct {
char *url;
SDL_Rect pos_img_affiche;
SDL_Rect pos_img_ecran;
SDL_Surface *img;
} image;


void init(Personne * p, int numperso);		
void initPerso(Personne *p);		
void afficherPerso(Personne p, SDL_Surface * screen);		
void movePerso (Personne *p,int dt);		
void animerPerso (Personne* p);		
void saut (Personne* p);
void saut2(Personne* p, int dt, int posinit);		
void liberer_image(Personne p);



void initbackground(image *IMAGE);
void afficher_imageBMT(SDL_Surface *screen,image imge);
void liberer_imagev(image imge);

#endif 
