#include "sim.h"

int START    = 0;
int CONTINUE = 1;

int pixels[SIM_X_SIZE][SIM_Y_SIZE];

int countLivingNeighbors(int x, int y) {
    assert(0 <= x && x < SIM_X_SIZE);
    assert(0 <= y && y < SIM_Y_SIZE);
    int counter = 0;

    for(int i = x - 1; i < x + 2; i++) {
        if(i < 0 || i >= SIM_X_SIZE) {
            continue;
        }
        for(int j = y - 1; j < y + 2; j++) {
            if(j < 0 || j >= SIM_Y_SIZE) {
                continue;
            }

            if(i == x && j == y) {
                continue;
            }

            if(pixels[i][j] == 1) {
                counter++;
            }
        }
    }
    
    return counter;
}

void updatePixel(int x, int y) {
    assert(0 <= x && x < SIM_X_SIZE);
    assert(0 <= y && y < SIM_Y_SIZE);
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
    assert(pixels != NULL);
    int flag = START;
    int color = 0xFF000000;

    while(1) {
        for(int x = 0; x < SIM_X_SIZE; ++x) {
            for(int y = 0; y < SIM_Y_SIZE; ++y) {
                if(flag == START) {
                    pixels[x][y] = simRand();
                }

                if(pixels[x][y] == 1) {
                    color = 0xFF0000;
                }
                else {
                    color = 0xFF000000;
                }

                simPutPixel(x, y, color);
                if(flag == CONTINUE) {
                    updatePixel(x,y);
                }
            }
        }
        flag = CONTINUE;
        simFlush();

    }
}