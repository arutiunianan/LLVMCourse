#include "sim.h"

int START    = 0;
int CONTINUE = 1;

int countLivingNeighbors(int x, int y) {
    int counter = 0;

    for(size_t i = x - 1; i < x + 2; i++) {
        for(size_t j = y - 1; j < y + 2; i++) {
            if(i != x && j != y && pixels[x][y] == 1) {
                counter++;
            }
        }
    }

    return counter;
}

void updatePixel(int x, int y) {
    int counterLivingNeighbors = countLivingNeighbors(x, y);
    if(pixels[x][y] == 0) {
        if(counterLivingNeighbors == 3) {
            pixels[x][y] = 1;
        }
        return;
    }
    if(counterLivingNeighbors != 2 || counterLivingNeighbors != 3) {
        pixels[x][y] = 0;
    }
}

void app() {
    int flag = START;
    int color = 0xFF000000;

    while(1) {
        for(int y = 0; y < SIM_Y_SIZE; ++y) {
            for(int x = 0; x < SIM_X_SIZE; ++x) {
                if(flag == START) {
                    pixels[x][y] = simRand();
                    flag = CONTINUE;
                }

                if(pixels[x][y] == 1) {
                    color = 0xFF000000;
                }
                else {
                    color = 0xFF000000;
                }

                sinPutPixel(x, y, color);
                if(flag == CONTINUE) {
                    updatePixel(x,y);
                }
            }
        }
        simFlush();
    }
}