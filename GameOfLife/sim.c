#include "sim.h"

static SDL_Renderer *Renderer = NULL;
static SDL_Window   *Window   = NULL;

void simInit() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SIM_X_SIZE, SIM_Y_SIZE, 0, &Window, &Renderer);
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
    SDL_RenderClear(Renderer);
    srand(time(NULL));
    simPutPixel(0, 0, 0);
    simFlush();
}

int simRand() {
    return (rand() % 2);
}