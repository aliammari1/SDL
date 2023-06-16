#include "menu.h"

void init_image(Image *images, int x, int y, char path[])
{
    images->img = IMG_Load(path);
    images->pos.x = x;
    images->pos.y = y;
}

void init_buttons(Button *buttons[])
{
    int i, j, y = 0;
    char nom_image[20];
    for (i = 0; i < NB_BUTTON; i++)
    {
        for (j = 0; j < NB_BUTTON_STATE; j++)
        {
            sprintf(nom_image, "images/%d%d.png", i, j);
            buttons[i]->img[j] = IMG_Load(nom_image);
        }
        buttons[i]->frame = 0;
        buttons[i]->pos.x = 565;
        buttons[i]->pos.y = 296 + y;
        if (i != NB_BUTTON - 1)
            y += 120;
    }
}

/*
void init_button_settings(Button *settings)
{
    int i;
    char path[20];
    for (i = 0; i < 2; i++)
    {
        sprintf(path, "images/settings%d.png", i);
        settings->img[i] = IMG_Load(path);
    }
    settings->frame = 0;
    settings->pos.x = 565;
    settings->pos.y = 416;
}

void init_button_quit(Button *quit)
{
    int i;
    char path[20];
    for (i = 0; i < 2; i++)
    {
        sprintf(path, "quit%d.png", i);
        quit->img[i] = IMG_Load(path);
    }
    quit->frame = 0;
    quit->pos.x = 565;
    quit->pos.y = 530;
}
*/
void init_button_full_screen(Button *full_screen)
{
    int i;
    char nom_image[20];
    for (i = 0; i < 2; i++)
    {
        sprintf(nom_image, "fullscreen%d.png", i);
        full_screen->img[i] = IMG_Load(nom_image);
    }
    full_screen->frame = 0;
    full_screen->pos.x = 565;
    full_screen->pos.y = 296;
}
void init_back(Back *backg)
{
    int i;
    char path[20];
    for (i = 0; i < NB_BACK_FRAME; i++)
    {
        sprintf(path, "images/back%d.png", i);
        backg->img[i] = IMG_Load(path);
    }
    backg->frame = 0;
    backg->pos.x = 0;
    backg->pos.y = 0;
    backg->pos.w = backg->img[0]->w;
    backg->pos.h = backg->img[0]->h;
}
void init_logo(Logo *logo)
{
    int i;
    char path[20];
    for (i = 0; i < 11; i++)
    {
        sprintf(path, "logo/logo%d.png", i);
        logo->img[i] = IMG_Load(path);
    }
    logo->frame = 0;
    logo->pos.x = 510;
    logo->pos.y = 0;
}
void init_texte(Text *text)
{
    text->pos.x = 300;
    text->pos.y = 500;
    text->textcolor.r = 255;
    text->textcolor.g = 0;
    text->textcolor.b = 0;
    text->font = TTF_OpenFont("arial.ttf", 50);
}
void display_texte(Text text, SDL_Surface *screen)
{
    text.surface_texte = TTF_RenderText_Solid(text.font, "Cantact Us at: esprit2122@esprit.tn", text.textcolor);
    SDL_BlitSurface(text.surface_texte, NULL, screen, &text.pos);
}
void scrolling_menu_UP(Button *play, Button *settings, Button *quit, int *n)
{

    if ((*n) <= 0)
        (*n) = 1;
    if ((*n) == 1)
    {
        play->frame = 1;
        settings->frame = 0;
        quit->frame = 0;
    }
    if ((*n) == 2)
    {
        play->frame = 0;
        settings->frame = 1;
        quit->frame = 0;
    }
    if ((*n) == 3)
    {
        play->frame = 0;
        settings->frame = 0;
        quit->frame = 1;
    }
    printf("%d\n", *n);
}
void scrolling_menu_DOWN(Button *play, Button *settings, Button *quit, int *n)
{
    if ((*n) >= 3)
        (*n) = 3;
    if ((*n) == 1)
    {
        play->frame = 1;
        settings->frame = 0;
        quit->frame = 0;
    }
    if ((*n) == 2)
    {
        play->frame = 0;
        settings->frame = 1;
        quit->frame = 0;
    }
    if ((*n) == 3)
    {
        play->frame = 0;
        settings->frame = 0;
        quit->frame = 1;
    }
}
void animation_back(Back *backg)
{
    (backg->frame)++;
    if (backg->frame == NB_BACK_FRAME - 1)
        backg->frame = 0;
}
void animation_logo(Logo *logo)
{
    (logo->frame)++;
    if ((logo->frame) < 10)
        SDL_Delay(100);
    else
        logo->frame = 10;
}
void afficher_logo(Logo logo, SDL_Surface *screen)
{
    SDL_BlitSurface(logo.img[logo.frame], NULL, screen, &logo.pos);
}
void afficher_image(Image images, SDL_Surface *screen)
{
    SDL_BlitSurface(images.img, NULL, screen, &images.pos);
}
void afficher_button(Button buttons, SDL_Surface *screen)
{
    SDL_BlitSurface(buttons.img[buttons.frame], NULL, screen, &buttons.pos);
}
void afficher_back(Back backg, SDL_Surface *screen)
{
    SDL_BlitSurface(backg.img[0], NULL, screen, &backg.pos);
}
void afficher_back2(Back backg, SDL_Surface *screen)
{
    SDL_BlitSurface(backg.img[1], NULL, screen, &backg.pos);
}
void logo_music()
{
    Mix_Chunk *logo_music;
    logo_music = Mix_LoadWAV("audio.wav");
    Mix_PlayChannel(-1, logo_music, 0);
}
void back_music()
{
    Mix_Music *music;
    music = Mix_LoadMUS("Living Life In The Night - Cheriimoya- Sierra Kidd (Lyrics)[Mpgun.com].mp3");
    Mix_PlayMusic(music, 0);
}
void init_back_music(Song song[])
{
    int i;
    char path[20];
    for (i = 0; i < 5; i++)
    {
        sprintf(path, "music/%d.mp3", i);
        song[i].music = Mix_LoadMUS(path);
    }
    for (i = 0; i < 5; i++)
    {
        sprintf(path, "song/song%d.png", i);
        song[i].songpic = IMG_Load(path);
    }
    for (i = 0; i < 5; i++)
    {
        song[0].pos.x = 150;
        if (i != 0)
            song[i].pos.x = song[i - 1].pos.x + 150;
        song[i].pos.y = 500;
    }
}
void afficher_song(Song song[], SDL_Surface *screen)
{
    SDL_BlitSurface(song[0].songpic, NULL, screen, &song[0].pos);
    SDL_BlitSurface(song[1].songpic, NULL, screen, &song[1].pos);
    SDL_BlitSurface(song[2].songpic, NULL, screen, &song[2].pos);
    SDL_BlitSurface(song[3].songpic, NULL, screen, &song[3].pos);
    SDL_BlitSurface(song[4].songpic, NULL, screen, &song[4].pos);
}
void play_music(Song song[])
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_KP1:
            Mix_PlayMusic(song[0].music, 0);
            break;
        case SDLK_KP2:
            Mix_PlayMusic(song[1].music, 0);
            break;
        case SDLK_KP3:
            Mix_PlayMusic(song[2].music, 0);
            break;
        case SDLK_KP4:
            Mix_PlayMusic(song[3].music, 0);
            break;
        case SDLK_KP5:
            Mix_PlayMusic(song[4].music, 0);
            break;
        }
        break;
    }
}

void playGame(SDL_Surface *screen, int *game)
{
    int play = 1;
    SDL_Event event;
    Back backg;
    init_back(&backg);
    while (play)
    {
        afficher_back2(backg, screen);
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            play = 0;
            *game = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                play = 0;
                break;
            }
            break;
        }
        SDL_Flip(screen);
    }
}
void parametres(SDL_Surface *screen) {}