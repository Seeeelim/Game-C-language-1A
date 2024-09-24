#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "game.h"
#include "sauvegarde.h"


int main()
{
SDL_Surface  *screen = NULL;
 image IMAGE_BTN1,IMAGE_BTN2,IMAGE10,IMAGE_BTN3,IMAGE_BTN1a,IMAGE_BTN2a,IMAGE_BTN3a,BACK1,retour,IMAGE_BTN4,bvol1,bvol2,bvol3,bvol5,rect,IMAGE,player,multiplayer,backplayer,pause,backmulti, IMAGE_CHARGER,backl1;
Mix_Music *music=NULL;
 BackgroundM B;
 Background l1;
 Mix_Chunk *mus = NULL;
 texte txte,txtev,txtes,txtef;
 SDL_Event event;
 int boucle=1,b=0,c=0,d=0,e=0,t=0,k, z = 0,level2=0;
 int m=0,mut=1,anim=0;
 int m1,m2,m3,f1,f2,f=0;
 int p=0,x=0,q=0;
Ennemi E1,E2;
image backk;
Personne P;
Personne P2;
Uint32 dt, t_prev;
int state;
int droite=0,gauche=0,up=0,dir=2,acc=2,dec=2,droite2=0,gauche2=0,up2=0,dir2=2,ll2=0,kk=0;
int continuer=1,partage=0,pas=5,pas2=5,direction=0,direction2=0,directionh=0,directionh2=0,pas3=5;
int animation=2;
 BackgroundL1 l2;

int done;
Uint8 *keystate = SDL_GetKeyState(NULL);


double ratio=0,r=0;
   SDL_Rect back;
 if(SDL_Init(SDL_INIT_VIDEO |SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
 {

  printf("coud not initialize SDL :%s.\n",SDL_GetError());
  return -1;



  }
  SDL_Rect** modes = SDL_ListModes(NULL, SDL_FULLSCREEN);

    if (modes == (SDL_Rect**)0 || modes == (SDL_Rect**)-1) {
        // No modes available
        return 1;
    }
    screen =SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);

  //initbackground(&IMAGE);
  initialiser_imageBack(&backk);
initEnnemi1(&E1);
initEnnemi2(&E2);
initPerso(&P);
initPerso2(&P2);
 initbackground(&B);
  initialiser_imageBMT1(&IMAGE_BTN1);
  initialiser_imageBMT2(&IMAGE_BTN2);
  initialiser_imageBMT3(&IMAGE_BTN3);
  initialiser_imageBMT1a(&IMAGE_BTN1a);
  initialiser_imageBMT2a(&IMAGE_BTN2a);
  initialiser_imageBMT3a(&IMAGE_BTN3a);
  initialiser_imageBMT10(&IMAGE10);
  initialiser_imageBack2(&BACK1);
  //initialiser_imagebackplayer(&backplayer);
  //initialiser_imagebackplayer(&backmulti);
   initialiser_imageplayer(&player);
   initialiser_imageCHARGER(&IMAGE_CHARGER);
   initialiser_imagemultiplayer(&multiplayer);
   initialiser_imageBMT4(&retour);
   initialiser_imagepause(&pause);
   initialiser_imageBMT7(&bvol2);
   initialiser_imageBMT8(&bvol3);
   initialiser_imageBMT9(&rect);
   initialiser_texte(&txte);
   initialiser_texteV(&txtev);
   initialiser_texteS(&txtes);
    initialiser_texteF(&txtef);
   initialiser_musique(music);
   initBack(&l1);
    initialiser_imagebacklevel1(&l2);
     initialiser_imageBackleeevel(&backl1);




  while(boucle==1)
  {

if(t==0)
{
 if (anim<=72)
  {
   SDL_BlitSurface(B.img[anim],NULL,screen,&back);

    if (anim>=72)
    {
    anim=0;
    }
   anim++;

  }


  afficher_imageBMT(screen,IMAGE_BTN1);
  afficher_imageBMT(screen,IMAGE_BTN2);
  afficher_imageBMT(screen,IMAGE_BTN3);
  afficher_texte(screen,txte);
  }

//affichage partie option
  if(b==1)
  {p=0;
   c=0;
   d=0;
   e=0;
   t=1;
   k=1;

afficher_imageBMT(screen,BACK1);
afficher_imageBMT(screen,rect);
afficher_imageBMT(screen,IMAGE10);
afficher_imageBMT(screen,retour);
afficher_imageBMT(screen,bvol2);
afficher_imageBMT(screen,bvol3);
afficher_texteV(screen,txtev);
afficher_texteS(screen,txtes);
afficher_texteF(screen,txtef);


}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(z == 1)
{
	charger(&P, &l1, &E1);
	printf("\n< perso > position : %d -- %d, vitesse : %f, acceleration : %f, direction : %d\n", P.pos.x, P.pos.y, P.vitesse, P.acceleration, P.direction);
	printf("\n< ennemi > position1 : %d -- %d, position2 : %d -- %d, direction : %d, etat : %d\n", E1.pos1.x, E1.pos1.y, E1.pos2.x, E1.pos2.y, E1.direction, E1.etat);
	printf("\n< background > position camera : %d -- %d, position camera 2 : %d -- %d\n", l1.camera.x, l1.camera.y, l1.camera2.x, l1.camera2.y);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//affichage partie play
if(p==1)
 {
c=0;
d=0;
k=0;
e=0;
t=1;
afficher_imageBMT(screen,BACK1);

afficher_imageBMT(screen,rect);

afficher_imageBMT(screen,retour);
afficher_imageBMT(screen,player);
afficher_imageBMT(screen,multiplayer);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
afficher_imageBMT(screen, IMAGE_CHARGER);

if(keystate[SDLK_LCTRL] && keystate[SDLK_s])
{
	sauvegarder(P, l1, E1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 }
//affichage partie player
if(f1==1 )
{

p=0;
c=0;
d=0;
k=0;
e=0;
t=1;

if(ratio>=0 && ratio<=200 && level2==0)
{
if ( animation<=43)
  {
   SDL_BlitSurface(l1.imagebg[animation],&l1.camera,screen,NULL);

    if (animation>=43)
    {
    animation=1;
    }
   animation++;
}
scrolling (&l1.camera,direction*pas,directionh*pas3 ,l1.imagebg[animation]->w,l1.imagebg[animation]->h);
}else 
{ll2=1;
afficher_imageBMT(screen,backl1);
if(level2==1)
{
 kk++;
 SDL_BlitSurface(l2.imagebg,&l2.camera,screen,NULL);
 scrolling (&l2.camera,direction*pas,directionh*pas3 ,l2.imagebg->w,l2.imagebg->h);

}
}

if(partage){
SDL_Rect pos;
pos.x=950;
pos.y=0;

if (animation<=43)
  {
   SDL_BlitSurface(l1.imagebg[animation],&l1.camera2,screen,&pos);

    if (animation>=43)
    {
    animation=1;
    }
   animation++;
}

if(ll2!=1)
{ 
afficherPerso(P2,screen);
moveAI1(&E1,&P);
moveAI2(&E2,&P2);
afficher_texteP(txte,screen,ratio);
afficherEnnemi(E1,screen);
afficherEnnemi(E2,screen);
afficherPerso(P,screen);
}
afficher_imageBMT(screen,pause);
if(P.pos.x>=850)
    {
    	P.pos.x=850;
    }
if(P2.pos.x<=950)
    {
    	P2.pos.x=950;
    }
    if(E1.pos1.x>=850)
{
    	E1.pos1.x=850;
    }
 if(E2.pos1.x<=950)
    {
    	E2.pos1.x=950;
    }
    
}
else
{
afficher_texteP(txte,screen,ratio);
afficherEnnemi(E1,screen);
afficherEnnemi(E2,screen);
afficherPerso(P,screen);
 if(P.pos.x>=1500)
{if(kk!=1)
{
    	P.pos.x=1500;
    	
    	}
    	else
    	{
    	P.pos.x=200;
    	ratio=0;
    	}
    }
moveAI1(&E1,&P);
moveAI2(&E2,&P);
//animerEnnemi( &E);
//afficherEnnemi(E,screen);


afficher_imageBMT(screen,pause);
}
/*
if (partage)
{scrolling (&l1.camera2,direction2*pas2,directionh2*pas3,l1.imagebg[animation]->w,l1.imagebg[animation]->h);}
*/

 if(acc==1)
 {
 	movePerso (&P,dt);
 	movePersoA (&P2,dt);
 }
 if(acc==0)
 {
 	movePerso (&P,dt);
 	movePerso (&P2,dt);
 	acc=2;
 }


 if (droite==1)
{
    P.vitesse=1;
    P.acceleration+=0.5;
    P.direction=0;
    r=1;
    droite=0;
}
if (gauche==1)
{
    P.vitesse=1;
    P.acceleration+=0.5;
    P.direction=1;
    gauche=0;
}
if (droite2==1)
{
    P2.vitesse=1;
    P2.acceleration+=0.5;
    P2.direction=0;
    droite2=0;

}
if (gauche2==1)
{
    P2.vitesse=1;
    P2.acceleration+=0.5;
    P2.direction=1;
    gauche2=0;

}

   
    
if (up2==1)
{saut2(&P2);}
if (up==1)   //saut
{
saut(&P);
}
P.acceleration -=1;
P2.acceleration -=1;
	if (P.acceleration<0 )
		{ P.acceleration=0;}
	if (P.acceleration>4)
		{P.acceleration=4;}
		if (P2.acceleration<0 )
{ P2.acceleration=0;}  //controler l'internalle du vitesse p2
if (P2.acceleration>4 )
{ P2.acceleration=4;}
SDL_Delay(1);
dt = SDL_GetTicks() - t_prev;
movePerso (&P,dt);
animerPerso(&P);
movePerso(&P2,dt);
animerPerso(&P2);
	if ((P.vitesse==0)&&(P.acceleration==0))
	{
    		P.direction=dir;
	}
P.pos.y += P.vitesseV;
P.vitesseV += 4;
if (P.pos.y >= 850)
{
    P.vitesseV=0;
    P.pos.y=850;
}
if ((P2.vitesse==0)&&(P2.acceleration==0))
{
    P2.direction=dir2;//mémorisation de direction de personne2
}

P2.pos.y += P2.vitesseV;    //   pour saut
P2.vitesseV += 4;
if (P2.pos.y >= 850)
{
   P2.vitesseV=0;//desendre p2
    P2.pos.y=850; //position initiale
}


  if(r==1)
  {
  	ratio++;
  }


  if(collisionBB( P, E1)==1  || collisionBB( P, E2)==1)
{

initialiser_musiquebref(mus);
ratio--;

}

}






 //changer le couleur des boutons
if(c==1)
{
 afficher_imageBMT(screen,IMAGE_BTN1a);
 }
 if(d==2)
{

afficher_imageBMT(screen,IMAGE_BTN2a);
}
if(e==3)
{
 afficher_imageBMT(screen,IMAGE_BTN3a);
 }



  SDL_Flip(screen);
  SDL_Delay(1);
t_prev=SDL_GetTicks();



  while( SDL_PollEvent(&event))
  {
     switch(event.type)
     {

    case SDL_MOUSEMOTION:
	
   if(event.motion.y>=300 && event.motion.y<=393 && event.motion.x>=300&& event.motion.x<=600)
    {
        c=1;

    }
    else
    {
    c=0;
    }

   if(event.motion.y>=400 && event.motion.y<=493 && event.motion.x>=300 && event.motion.x<=600)
   {
   d=2;

   }
   else
    {
    d=0;
    }
   if(event.motion.y>=600 && event.motion.y<=693 && event.motion.x>=300&& event.motion.x<=600)
   {
   e=3;

   }
   else
    {
    e=0;
    }
    break;

    case SDL_MOUSEBUTTONUP:
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if(event.motion.y>=200 && event.motion.y<=300 && event.motion.x>=350 && event.motion.x<=450)
   	{
   		z = 1;
   	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
   if(event.button.button==SDL_BUTTON_LEFT && event.motion.y>=300 && event.motion.y<=393 && event.motion.x>=300&& event.motion.x<=600 && t==0 )
    {initialiser_musiquebref(mus);
    	  p=1;
    }

  else if ( event.button.button==SDL_BUTTON_LEFT && event.motion.y>=400 && event.motion.y<=493 && event.motion.x>=300 && event.motion.x<=600 && t==0)
   {initialiser_musiquebref(mus);
  boucle=0;

  }
  else if( event.button.button==SDL_BUTTON_LEFT && event.motion.y>=600 && event.motion.y<=693 && event.motion.x>=300 && event.motion.x<=600 && t==0)

  {
   initialiser_musiquebref(mus);
   b=1;
 }
 else if( event.button.button==SDL_BUTTON_LEFT && event.motion.y>=233 && event.motion.y<=450 && event.motion.x>=450 && event.motion.x<=800 && p==1 )
  {
  initialiser_musiquebref(mus);
  f1=1;
  p=0;
 }

else if( event.button.button==SDL_BUTTON_LEFT && event.motion.y>=200 && event.motion.y<=233 && event.motion.x>=400 && event.motion.x<=450 )
   {

  initialiser_musiquebref(mus);

   	p=0;
   	b=0;
   	c=0;
   	d=0;
   	e=0;
   	t=0;
   	k=0;

   }
else if( event.button.button==SDL_BUTTON_LEFT && event.motion.y>=0 && event.motion.y<=200 && event.motion.x>=0 && event.motion.x<=200 && p==0 && f1==1)
  {initialiser_musiquebref(mus);
   	f1=0;
   	p=1;
   	t=0;

 }
else if ( event.button.button==SDL_BUTTON_LEFT && event.motion.y>=500 && event.motion.y<=570 && event.motion.x>=720 && event.motion.x<=790 && b==1 && q==0)
                    {

                        SDL_Surface* screen = SDL_SetVideoMode(modes[0]->w, modes[0]->h, 0, SDL_FULLSCREEN);
                        q=1;

                    }
 else if ( event.button.button==SDL_BUTTON_LEFT && event.motion.y>=500 && event.motion.y<=570 && event.motion.x>=720 && event.motion.x<=790 && b==1 && q==1)
                    {

                        SDL_Surface* screen = SDL_SetVideoMode(modes[0]->w, modes[0]->h, 0,0);
                        q=0;

                    }

else if(event.motion.y>=400 && event.motion.y<=500 && event.motion.x>=400 && event.motion.x<=510 && m==0 && k==1 && b==1)
{initialiser_musiquebref(mus);

Mix_VolumeMusic(MIX_MAX_VOLUME/10);
m=m+5;
 }


else if(event.motion.y>=400 && event.motion.y<=500 && event.motion.x>=400 && event.motion.x<=510 && m==5 && k==1 && b==1)

 {initialiser_musiquebref(mus);

 Mix_VolumeMusic(MIX_MAX_VOLUME*5/10);
 m=m+5;



 }
 else if(event.motion.y>=400 && event.motion.y<=500 && event.motion.x>=400 && event.motion.x<=510 && m==10 && k==1 && b==1)
 {
 initialiser_musiquebref(mus);
 Mix_VolumeMusic(MIX_MAX_VOLUME);

}


else if(event.motion.y>=400 && event.motion.y<=500 && event.motion.x>=720 && event.motion.x<=780 && m==10 && k==1 && b==1)

{initialiser_musiquebref(mus);

Mix_VolumeMusic(MIX_MAX_VOLUME/5);

m=m-5;

}
else if(event.motion.y>=400 && event.motion.y<=500 && event.motion.x>=720 && event.motion.x<=780 && m==5 && k==1 && b==1)
{
initialiser_musiquebref(mus);
Mix_VolumeMusic(MIX_MAX_VOLUME/10);

m=m-5;
}

else if(event.motion.y>=400 && event.motion.y<=500 && event.motion.x>=720 && event.motion.x<=780 && m==0 && k==1 && b==1)
{initialiser_musiquebref(mus);
 Mix_VolumeMusic(MIX_MAX_VOLUME*0);


 }

   break;

  case SDL_QUIT:
      boucle=0;
      break;

 case SDL_KEYDOWN:

if(event.key.keysym.sym==SDLK_DOWN )

{
if(c==1)
{
initialiser_musiquebref(mus);
c=0;
d=2;
}
else if(d==2)
{
initialiser_musiquebref(mus);
d=0;
e=3;
}
else
{
initialiser_musiquebref(mus);
c=1;
e=0;


}
}
else if(event.key.keysym.sym== SDLK_RETURN && f1==1 && ll2==1 )
{
ll2=0;
level2=1;


}
else if(event.key.keysym.sym== SDLK_RETURN  )
 {

 if(c==1)
 {initialiser_musiquebref(mus);
  p=1;

 }
 else if(d==2)
 {initialiser_musiquebref(mus);

 boucle=0;
 }

 else if(e==3)
 {initialiser_musiquebref(mus);
 b=1;
 }
 
 }
if(f1==1)
{

 switch (event.key.keysym.sym)
        {

		case SDLK_p:
	partage=!partage;

            case SDLK_RIGHT:
                droite=1;
                direction=1;
                break;
            case SDLK_LEFT:
                gauche=1;
                direction=-1;
                break;
            case SDLK_UP:
                up=1;
                break;
             case SDLK_m:
                acc=1;
                	pas=10;
                break;
                
             case SDLK_k:
            	MenuEnigme();
            	SDL_Flip(screen);
            	while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
					case SDL_KEYDOWN:
						if(event.key.keysym.sym == SDLK_ESCAPE)
						{
							done = 0;
						}
					break;
				}
			}
	 break;


	}if(partage){
switch (event.key.keysym.sym) {
	case SDLK_q:
		direction2=-1;
		gauche2=1;
		break;
	case SDLK_d:
		direction2=1;
		droite2=1;
		break;
	case SDLK_z:
		directionh2=-1;
		up2=1;
		break;
	case SDLK_s:
		directionh2=1;
		break;
	case SDLK_SPACE:
		pas2=10;
	}
}
	break;
}






 else if ((event.key.keysym.sym == SDLK_ESCAPE) && (p==1))
 {initialiser_musiquebref(mus);
	p=0;
   	t=0;

	}
 else if (event.key.keysym.sym == SDLK_ESCAPE && t==1 && f1==1)
 {initialiser_musiquebref(mus);
	f1=0;
	p=1;

	}

else if ((event.key.keysym.sym == SDLK_ESCAPE) && (b==1))
 {initialiser_musiquebref(mus);
 b=0;
t=0;

}
 else if ((event.key.keysym.sym == SDLK_ESCAPE) && (t==0))
{
 initialiser_musiquebref(mus);
boucle=0;
}



else if(event.key.keysym.sym == SDLK_LEFT && m==0 && b==1)
{
initialiser_musiquebref(mus);
Mix_VolumeMusic(MIX_MAX_VOLUME/10);

m=m+5;
}
else if(event.key.keysym.sym == SDLK_LEFT && m==5 && b==1)
{
initialiser_musiquebref(mus);
Mix_VolumeMusic(MIX_MAX_VOLUME*5/10);

m=m+5;
}
else if(event.key.keysym.sym == SDLK_LEFT && m==10 && b==1)
{
initialiser_musiquebref(mus);
Mix_VolumeMusic(MIX_MAX_VOLUME);


}
else if(event.key.keysym.sym == SDLK_LEFT && f1==1)
{


 gauche=1;

}

else if(event.key.keysym.sym == SDLK_RIGHT && m==10 && b==1)
{
initialiser_musiquebref(mus);
Mix_VolumeMusic(MIX_MAX_VOLUME*5/10);

m=m-5;
}
else if(event.key.keysym.sym == SDLK_RIGHT && m==5 && b==1)
{
initialiser_musiquebref(mus);
Mix_VolumeMusic(MIX_MAX_VOLUME/10);

m=m-5;
}

else if(event.key.keysym.sym == SDLK_RIGHT && m==0 && b==1)
{
initialiser_musiquebref(mus);
Mix_VolumeMusic(MIX_MAX_VOLUME*0);
}
else if(event.key.keysym.sym == SDLK_RIGHT && f1==1)
{

 droite=1;


}
else if(event.key.keysym.sym==SDLK_UP )


{
if(e==3)
{initialiser_musiquebref(mus);
e=0;
d=2;
}
else if(d==2)
{initialiser_musiquebref(mus);
d=0;
c=1;
}
else
{initialiser_musiquebref(mus);
e=3;
c=0;

}
}
else if(f1==1 && event.key.keysym.sym==SDLK_UP )
{
 up=1;

}
else if(event.key.keysym.sym== SDLK_RETURN  )
 {

 if(c==1)
 {initialiser_musiquebref(mus);
  p=1;

 }
 else if(d==2)
 {initialiser_musiquebref(mus);

 boucle=0;
 }

 else if(e==3)
 {initialiser_musiquebref(mus);
 b=1;
 }
 
 }
break;
case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                droite=0;
                r=0;
                dir=2;
                P.vitesse=0;
                if(direction==1)direction=0;
                break;
            case SDLK_LEFT:
                gauche=0;
                P.vitesse=0;
                dir=3;
                if(direction==-1)direction=0;
                break;
            case SDLK_UP:
                up=0;
                break;
            case SDLK_m:
                acc=0;
               	pas=5;
                break;
       if(partage){


	case SDLK_q:
		if(direction2==-1){direction2=0;}
		gauche2=0;
                P2.vitesse=0;
                dir2=3;
		break;
	case SDLK_d:
		if(direction2==1){direction2=0;}
		droite2=0;
                dir2=2;
                P2.vitesse=0;
		break;
	case SDLK_z:
		directionh2=0;
		up2=0;
		break;
	case SDLK_s:
		directionh2=0;
		break;
	case SDLK_SPACE:
		pas2=5;

	}

          }


           
          }







 }





  }








liberer_image(IMAGE_BTN1);
  liberer_image(IMAGE_BTN2);
  liberer_image(IMAGE_BTN3);
  liberer_image(IMAGE_BTN1a);
  liberer_image(IMAGE_BTN2a);
  liberer_image(IMAGE_BTN3a);
  liberer_image(player);
  liberer_image(multiplayer);
  liberer_image(IMAGE_CHARGER);
 liberer_image(pause);
   liberer_image(backplayer);
  
  liberer_image(bvol2);
  liberer_image(bvol3);

  liberer_image(retour);
  liberer_image(BACK1);
  liberer_texteP(txte);
  liberer_texteP(txtev);
  liberer_texteP(txtes);
  liberer_texteP(txtef);
  liberer_musique(music);
  liberer_musiquebref(mus);
  liberer_image(rect);
  //libere_image(back);
 liberer_ennemi(E1);
  liberer_ennemi(E2);
liberer_imageperso(P);
liberer_imageback(B);
QuitBack(&l1);
QuitBackk(l2);
//SDL_FreeSurface (screen);

   
 //liberer_imageback(B);
  
  

  
  

SDL_Quit();



return 0;

}



