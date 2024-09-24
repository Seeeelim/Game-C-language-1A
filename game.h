#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <linux/joystick.h>

#define SCREEN_H 2000
#define SCREEN_W 2000
typedef enum STATE STATE;
enum STATE {WAITING,FOLLOWING1,FOLLOWING2,ATTACKING1,ATTACKING2};


typedef struct 
{
SDL_Surface *TabES[2][10];
int num; 
SDL_Rect pos1;//partie qui sera afficher
SDL_Rect pos2;//position par rapport a lecran
int etat,collision;
Mix_Chunk M;
int direction;
STATE state;

}Ennemi;

typedef struct {    
SDL_Rect pos1;
SDL_Rect pos_img_ecran;
SDL_Surface *img[80]; 
int num; 
}BackgroundM ; 


typedef struct 
{
char *url;

SDL_Rect pos_img_affiche;
SDL_Rect pos_img_ecran;
SDL_Surface *img;
} image;
typedef struct {    
SDL_Rect pos;
SDL_Rect pos_sprite;
SDL_Surface *spritesheet;
int numperso,up,direction; 
double vitesse,acceleration;
int vitesseV;

SDL_Surface *image_vie[5]; 
SDL_Rect position_vie ;
int val;
SDL_Rect position_texte;
}Personne ;



typedef struct
{
double ratio ;
SDL_Surface *txt;
SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font *police;
}texte; 
typedef struct {
SDL_Rect camera,camera2;
SDL_Surface *imagebg[80];
Mix_Music *musique;
}Background;

typedef struct {
SDL_Rect camera,camera2;
SDL_Surface *imagebg;
Mix_Music *musique;
char *url;
}BackgroundL1;

void initBack(Background * b);
void afficherBack(Background b, SDL_Surface * screen,int partage);
void scrolling (SDL_Rect * b, int direction,int direction2 ,int wigth,int hight);
void QuitBack(Background * b);
void QuitBackk(BackgroundL1  b);
void initialiser_imagebacklevel1(BackgroundL1 *b);		
void initPerso(Personne *p);		
void afficherPerso(Personne p, SDL_Surface * screen);		
void movePerso (Personne *p,int dt);	
void movePersoA (Personne *p,int dt);		
void animerPerso (Personne* p);		
void saut (Personne* p);		
void liberer_imageperso(Personne p);
void liberer_texteP(texte txte);
void afficher_texteP(texte txte,SDL_Surface *screen,double ratio);
void initialiser_texteP(texte *txte);
//void initbackground(image *IMAGE);
void initEnnemi1(Ennemi *E);
void animerEnnemi( Ennemi * E);
void afficherEnnemi(Ennemi E, SDL_Surface  * screen);
void updateEnnemiState (Ennemi* E, int distEH);
void initialiser_musiquebref(Mix_Chunk *music);
void liberer_musiquebref(Mix_Chunk *music);
void liberer_ennemi(Ennemi E);
int collisionBB( Personne P, Ennemi E) ;
void initialiser_imageBack(image *image);
void afficher_imageBMT(SDL_Surface *screen,image imge);
void libere_image(image back);	
void moveE1( Ennemi  *E);
void moveE2( Ennemi  *E);
void moveAI1(Ennemi *E,Personne *P);
void moveAI2(Ennemi *E,Personne *P);
void initEnnemi2(Ennemi *E);
void initbackground(BackgroundM *B);
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
void liberer_imageback(BackgroundM imge);
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
void liberer_texteP(texte txte);
void initialiser_imagemultiplayer(image *image);
void initialiser_imageCHARGER(image *image);
void initialiser_imageplayer(image *image);
void initialiser_imagebackplayer(image *image);
void initialiser_imagepause(image *image);
void initPerso2(Personne *p2);
void saut2 (Personne* p);
void initialiser_imageBackleeevel(image *image);

struct enigme
{
	SDL_Surface *image_enig, *reponse_1, *reponse_2, *reponse_3, *question, *correct, *wrong;
	SDL_Rect position, pos_reponse_1, pos_reponse_2, pos_reponse_3, pos_question, posRes;
	int resultat, alea, done;
	Mix_Music *music1, *music2;
	TTF_Font *police, *police_q;
};
typedef struct enigme enigme;  

void init_enig(enigme *e);
void alea_enig(enigme* e);
void afficherEnigme(enigme *e, SDL_Surface* screen);
void free_surface_enig(enigme *e);
void quiz(enigme *e, SDL_Surface* screen);
void MenuEnigme();

typedef struct save
{
	Personne p;
	Background b;
	Ennemi e;
}save;

void sauvegarder(Personne p, Background b, Ennemi e); 
int charger(Personne *p, Background *b, Ennemi *e);

//void maFonction(Joystick *joystick);
//void updateSDL(Joystick *joystick ,int direction,int  droite,int up ) ;



#endif 
