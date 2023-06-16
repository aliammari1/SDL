#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#define NB_BACK_FRAME 2
#define NB_BUTTON 1
#define NB_BUTTON_STATE 3

typedef struct
{
    SDL_Surface *img;
    SDL_Rect pos;
} Image;

typedef struct
{
    SDL_Rect pos;
    SDL_Surface *img[3];
    int frame;
} Button;

typedef struct
{
    SDL_Surface *img[2];
    SDL_Rect pos;
    int frame;
} Back;

typedef struct
{
    SDL_Surface *img[11];
    SDL_Rect pos;
    int frame;
} Logo;

typedef struct
{
    SDL_Rect pos;
    TTF_Font *font;
    SDL_Surface *surface_texte;
    SDL_Color textcolor;
    char texte[50];
} Text;

typedef struct
{
    Mix_Music *music;
    SDL_Rect pos;
    SDL_Surface *songpic;
    int num;
} Song;

void init_image(Image *images, int x, int y, char path[]);
void init_buttons(Button *buttons[]);
// void init_button_play(Button *play);
// void init_button_settings(Button *settings);
// void init_button_quit(Button *quit);
void init_button_full_screen(Button *full_screen);
void init_back(Back *backg);
void init_logo(Logo *logo);
void display_texte(Text text, SDL_Surface *screen);
void init_texte(Text *text);
void scrolling_menu_UP(Button *play, Button *settings, Button *quit, int *n);
void scrolling_menu_DOWN(Button *play, Button *settings, Button *quit, int *n);
void animation_back(Back *backg);
void animation_logo(Logo *logo);
void afficher_logo(Logo logo, SDL_Surface *screen);
void afficher_image(Image images, SDL_Surface *screen);
void afficher_button(Button buttons, SDL_Surface *screen);
void afficher_back(Back backg, SDL_Surface *screen);
void afficher_back2(Back backg, SDL_Surface *screen);
void logo_music();
void back_music();
void init_back_music(Song song[]);
void afficher_song(Song song[], SDL_Surface *screen);
void play_music(Song song[]);
void playGame(SDL_Surface *screen, int *game);
void parametres(SDL_Surface *screen);
