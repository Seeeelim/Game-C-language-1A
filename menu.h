#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 2000
#define SCREEN_W 2000

typedef struct {

char *url;
SDL_Rect pos_img_affiche;
SDL_Rect pos_img_ecran;
SDL_Surface *img;
} image;

typedef struct {

SDL_Surface *txt;

SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font *police;
} texte;


typedef struct {    
SDL_Rect pos1;
SDL_Rect pos_img_ecran;
SDL_Surface *img[80]; 
int num; 
}Background ; 
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

//void initbackground(image *IMAGE);
void initbackground(Background *B);
void initialiser_imageBMT1(image *imgbtn);

void initialiser_imageBMT2(image *imgbtn);
void initialiser_imageBMT3(image *imgbtn);
void initialiser_imageBMT1a(image *imgbtn);
void initialiser_imageBMT2a(image *imgbtn);
void initialiser_imageBMT3a(image *imgbtn);
void initialiser_imageBack2(image *imgbtn);
void initialiser_imageBMT4(image *imgbtn);
void initialiser_imageBMT7(image *imgbtn);
void initialiser_imageBMT8(image *imgbtn);
void initialiser_imageBMT9(image *imgbtn);
void initialiser_imageBMT10(image *imgbtn);
void afficher_imageBMP(SDL_Surface *screen,Background imge);
void afficher_imageBMT(SDL_Surface *screen,image imge);
void liberer_image(image imge);
void liberer_imageback(Background imge);
void initialiser_musique(Mix_Music *music);
void liberer_musique(Mix_Music *music);
void initialiser_musiquebref(Mix_Chunk *music);
void liberer_musiquebref(Mix_Chunk *music);
void initialiser_texte(texte *txte);
void initialiser_texteV(texte *txte);
void initialiser_texteF(texte *txte);
void afficher_texte(SDL_Surface *screen,texte txte);
void afficher_texteV(SDL_Surface *screen,texte txte);
void afficher_texteS(SDL_Surface *screen,texte txte);
void afficher_texteF(SDL_Surface *screen,texte txte);
void initialiser_texteS(texte *txte);
void liberer_texte(texte txte);
void initialiser_imagemultiplayer(image *image);
void initialiser_imageplayer(image *image);
void initialiser_imagebackplayer(image *image);
void initialiser_imagepause(image *image);
void initEnnemi(Ennemi *E);
void animerEnnemi( Ennemi * E);
void afficherEnnemi(Ennemi E, SDL_Surface  * screen);
void liberer_ennemi(Ennemi E);

void initialiser_imageBack(image *image);
void afficher_imageBMT(SDL_Surface *screen,image imge);
void libere_image(image back);	
void move( Ennemi  *E);
void init(Personne * p, int numperso);		
void initPerso(Personne *p);		
void afficherPerso(Personne p, SDL_Surface * screen);		
void movePerso (Personne *p,int dt);
void movePersoA (Personne *p,int dt);		
void animerPerso (Personne* p);		
void saut (Personne* p);
void saut2(Personne* p, int dt, int posinit);		
void liberer_imageperso(Personne p);


			




//void initialiser_imagebackmultiplayer(image *image);



#endif 
