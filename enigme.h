#ifndef enigme_H_INCLUDED
#define enigme_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <time.h>
#define SCREEN_H 600
#define SCREEN_w 832

struct enigme
{
	SDL_Surface *image_enig,*reponse_1,*reponse_2,*reponse_3,*question,*correct,*wrong;
	SDL_Rect position,pos_reponse_1,pos_reponse_2,pos_reponse_3,pos_question;
	int resultat,alea,done;
	Mix_Music *music1,*music2;
	TTF_Font *police,*police_q;
	
	
};
typedef struct enigme enigme;

void init_enig( enigme* e );
void alea_enig(enigme* e);
void afficherEnigme ( enigme *e, SDL_Surface* screen);
void free_surface_enig( enigme *e );
int quiz(enigme *e, SDL_Surface* screen );

#endif 
