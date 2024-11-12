#include "sim.h"
#include <stdio.h>

void app() {

    while(1) {
        for (int x = 0; x < SIM_X_SIZE; ++x) {
            for (int y = 0; y < SIM_Y_SIZE; ++y) {
                if (simRand() % 2) {
                    simPutPixel(x, y, 0xFF0000 + (x + y * SIM_X_SIZE) * 128);
                }
                else {
                    simPutPixel(x, y, 0xFF000000);
                }
            }
        }
        simFlush();
    }
}