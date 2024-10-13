#include "sim.h"

int countLivingNeighbors(int x, int y, int* pixels) {
    int counter = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        if (i < 0 || i >= SIM_X_SIZE) {
            continue;
        }

        for (int j = y - 1; j <= y + 1; j++) {
            if (j < 0 || j >= SIM_Y_SIZE || (i == x && j == y)) {
                continue;
            }

            if (pixels[i + j * SIM_X_SIZE]) {
                counter++;
            }
        }
    }
    return counter;
}

void updatePixel(int x, int y, int* pixels, int* new_pixels) {
    int counterLivingNeighbors = countLivingNeighbors(x, y, pixels);
    
    if (pixels[x + y * SIM_X_SIZE] == 1) {
        if(counterLivingNeighbors != 2 && counterLivingNeighbors != 3) {
            new_pixels[x + y * SIM_X_SIZE] = 0;
        }
        else {
            new_pixels[x + y * SIM_X_SIZE] = 1;
        }
    } 
    else {
        if(counterLivingNeighbors != 3) {
            new_pixels[x + y * SIM_X_SIZE] = 0;
        }
        else {
            new_pixels[x + y * SIM_X_SIZE] = 1;
        }
    }
}

void swapPixels(int** old_pixels, int** new_pixels) {
    int* buf = *old_pixels;
    *old_pixels = *new_pixels;
    *new_pixels = buf;
}

void gameOfLife(int* pixels, int* new_pixels) {
    while (1) {
        for (int x = 0; x < SIM_X_SIZE; x++) {
            for (int y = 0; y < SIM_Y_SIZE; y++) {
                simPutPixel(x, y, pixels[x + y * SIM_X_SIZE] ? 0xFF0000 : 0xFF000000);
                updatePixel(x, y, pixels, new_pixels);
            }
        }
        swapPixels(&pixels, &new_pixels);
        simFlush();
    }
}

void app() {
    int pixels[SIM_X_SIZE][SIM_Y_SIZE]     = {0};
    int new_pixels[SIM_X_SIZE][SIM_Y_SIZE] = {0};

    for(int x = 0; x < SIM_X_SIZE; ++x) {
        for(int y = 0; y < SIM_Y_SIZE; ++y) {
            pixels[x][y] = simRand();
            new_pixels[x][y] = pixels[x][y];
        }
    }
    gameOfLife(pixels, new_pixels);
}
