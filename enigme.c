#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <time.h>
#include "game.h"

void init_enig( enigme* e )
{
	e->music1 = Mix_LoadMUS("enigme/audio.mp3");
	Mix_PlayMusic(e->music1, 0);
	e->image_enig = IMG_Load("enigme/parchemin1.png");
	e->position.x = 0;
	e->position.y = 0;
	e->posRes.x = 620;
	e->posRes.y = 210;
	e->resultat = 0;
	e->correct =IMG_Load("enigme/correct_answer.png");
	e->wrong =IMG_Load("enigme/wrong_answer.png");

	e->police=TTF_OpenFont("enigme/alger.TTF", 30);
	e->reponse_1 = NULL;
	e->pos_reponse_1.x=SCREEN_W/7.5;
	e->pos_reponse_1.y=SCREEN_H/5;

	e->reponse_2 = NULL;
	e->pos_reponse_2.x=SCREEN_W/2.5;
	e->pos_reponse_2.y=SCREEN_H/5;

	e->reponse_3 =NULL;
	e->pos_reponse_3.x=SCREEN_W/2+SCREEN_W/6;
	e->pos_reponse_3.y=SCREEN_H/5;

	e->police_q=TTF_OpenFont("enigme/alger.TTF", 35);
	e->question = NULL;
	e->pos_question.x=SCREEN_W/8;
	e->pos_question.y=SCREEN_H/9.5;

	e->alea = 0;
}
void afficherEnigme(enigme *e, SDL_Surface* screen)
{
	SDL_BlitSurface(e->image_enig,NULL, screen, &e->position);
	SDL_BlitSurface(e->reponse_1,NULL,screen,&e->pos_reponse_1);
	SDL_BlitSurface(e->reponse_2,NULL,screen,&e->pos_reponse_2);
	SDL_BlitSurface(e->reponse_3,NULL,screen,&e->pos_reponse_3);
	SDL_BlitSurface(e->question,NULL,screen,&e->pos_question);
}
void free_surface_enig(enigme *e)
{
	SDL_FreeSurface(e->image_enig);
	SDL_FreeSurface(e->correct);
	SDL_FreeSurface(e->wrong);
	SDL_FreeSurface(e->reponse_1);
	SDL_FreeSurface(e->reponse_2);
	SDL_FreeSurface(e->reponse_3);
	SDL_FreeSurface(e->question);
	TTF_CloseFont(e->police);
	TTF_CloseFont(e->police_q);
	Mix_FreeMusic(e->music1);
}
void alea_enig(enigme *e)
{
	FILE* fichier = NULL;
	FILE* fichier_reponse = NULL;
	char ques[46];
	char rep1[20];
	char rep2[20];
	char rep3[20];
	SDL_Color Color={255,0,0};
	SDL_Color Color1={128,0,0};
	int caracterelu_question,caracterelu_reponses,ligne =1,ligne_reponse=1;
	srand(time(NULL));
	do {
		e->alea = rand()%5 +1;
	}while ( e->alea <1 || e->alea > 4 );
	printf("%d", e->alea);

	fichier_reponse = fopen("enigme/reponses.txt","r");
	fichier = fopen("enigme/questions.txt","r"); 
	if ( fichier != NULL && fichier_reponse != NULL )
	{
		while ( caracterelu_question!=EOF && ligne < e->alea )
		{
			caracterelu_question = fgetc(fichier);
			if ( caracterelu_question == '\n')
				ligne++;
		}
		fgets(ques,46,fichier);
		fclose(fichier);
		while ( caracterelu_reponses!=EOF && ligne_reponse < e->alea )
		{
			caracterelu_reponses = fgetc(fichier_reponse);
			if ( caracterelu_reponses == '\n')
				ligne_reponse++;
		}
		fscanf(fichier_reponse,"%s %s %s",rep1,rep2,rep3);
		fclose(fichier_reponse);
	}

	e->question = TTF_RenderText_Solid(e->police_q,ques,Color);
	e->reponse_1 = TTF_RenderText_Solid(e->police,rep1,Color1);
	e->reponse_2 = TTF_RenderText_Solid(e->police,rep2,Color1);
	e->reponse_3 = TTF_RenderText_Solid(e->police,rep3,Color1);
}
void quiz(enigme *e, SDL_Surface* screen)
{
	SDL_Event event;

	SDL_WaitEvent(&event);

	switch(event.type)
	{
		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
				case SDL_MOUSEMOTION:
   					if(event.motion.y>=312 && event.motion.y<=319 && event.motion.x>=165&& event.motion.x<=175)
   					{
						if ( e->alea == 1)
						{
							e->resultat= 1;
						}

						else
						{
							e->resultat = 2;
						}
					}
					if(event.motion.y>=312 && event.motion.y<=322 && event.motion.x>=330&& event.motion.x<=340)
					{
						if ( e->alea == 2 || e->alea == 3 )
						{
							e->resultat= 1;
						}
						 else
						{
							e->resultat = 2;
						}
					}
					if(event.motion.y>=312 && event.motion.y<=322 && event.motion.x>=555&& event.motion.x<=565)
					{
						if(e->alea == 4)
						{
							e->resultat = 1;
						}
						else
						{                	
							e->resultat = 2;
						}
					}
				break;
			}
		break;

		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_a:
					if(e->alea == 1)
					{
						e->resultat = 1;
					}
					else
					{
						e->resultat = 2;
					}
				break;
				
				case SDLK_z:
					if(e->alea == 2 || e->alea == 3)
					{
						e->resultat = 1;
					}
					else
					{
						e->resultat = 2;
					}
				break;
				
				case SDLK_e:
					if(e->alea == 4)
					{
						e->resultat = 1;
					}
					else
					{
						e->resultat = 2;
					}
				break;
		}
		break;
	}

	afficherEnigme(e, screen);

	if(e->resultat == 1)
	{
		SDL_BlitSurface(e->correct, NULL, screen, &e->posRes);
		SDL_Flip(screen);

		SDL_Delay(3000);

		e->done = 0;
	}
	else if(e->resultat == 2)
	{
		SDL_BlitSurface(e->wrong, NULL, screen, &e->posRes);
		SDL_Flip(screen);

		SDL_Delay(3000);

		e->done = 0;
	}
	SDL_Flip(screen);
}
void MenuEnigme()
{
	SDL_Surface *screen;
	SDL_Event event;
	enigme e;
	
	TTF_Init();
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1411);

	screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
	//SDL_WM_SetCaption("Enigme", NULL);

	init_enig(&e);
	alea_enig(&e);

  	e.done= 1;
	while (e.done) 
	{
		/*while (SDL_PollEvent(&event)) 
		{
		    switch (event.type) 
		    {
		   	case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						e.done = 0;
					break;
				}
			break;
		    
			case SDL_QUIT:
				e.done = 0;
			break;
		    }
		}*/  
		quiz(&e, screen);
	}
}
