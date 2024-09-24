#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
typedef struct {
SDL_Rect camera,camera2;
SDL_Surface *imagebg[63];
Mix_Music *musique;
}Background;
void initBack(Background * b);
void afficherBack(Background b, SDL_Surface * screen,int partage);
void scrolling (SDL_Rect * b, int direction,int direction2 ,int wigth,int hight);
void QuitBack(Background * b);

#endif // BACKGROUND_H_INCLUDED
