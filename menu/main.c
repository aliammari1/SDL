#include "menu.h"

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    int game = 1;
    SDL_Surface *screen;
    Back background;
    Button play;
    Button settings;
    Button quit;
    Button *buttons[3] = {&play, &settings, &quit};
    SDL_Event event;
    Mix_Chunk *son;
    son = Mix_LoadWAV("videoplayback.wav");
    init_back(&background);
    screen = SDL_SetVideoMode(background.pos.w, background.pos.h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    init_buttons(buttons);
    while (game)
    {
        afficher_back(background, screen);
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            game = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                game = 0;
                break;
            case SDLK_p:
                printf("play\n");
                playGame(screen, &game);
                break;
            case SDLK_s:
                parametres(screen);
                break;
            case SDLK_q:
                game = 0;
                break;
            case SDLK_f:
                SDL_WM_ToggleFullScreen(screen);
                break;
            }
            break;
        default:
            break;
        }
        SDL_Flip(screen);
    }

    return 0;
}