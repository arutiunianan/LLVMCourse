#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

const int SIM_X_SIZE = 512;
const int SIM_Y_SIZE = 256;
static int pixels[SIM_X_SIZE][SIM_Y_SIZE];

void simInit();
void app();

void simFlush();
void simPutPixel(int x, int y, int argb);
int  simRand();