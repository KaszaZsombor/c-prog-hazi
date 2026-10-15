#include "SDL.h"

int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *pwindow = SDL_CreateWindow("GEO", 0, 0, 600, 300, 0);
    SDL_Delay(4000);
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
    return 0;
}
