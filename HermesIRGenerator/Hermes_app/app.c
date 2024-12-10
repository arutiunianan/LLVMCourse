#include "sim.h"

void app() {
    //simGetMus();
    while(1) {
        char *imagePath = "../for_readme/1alb8.png";
        simGetPic(imagePath);
        for(int i1 = 0; i1 < 350; ++i1) {
            simFlush();
        }

        imagePath = "../for_readme/2alb8.png";
        simGetPic(imagePath);
        int i2 = 0;
        while(i2 < 350) {
            simFlush();
            i2 = i2 + 1;
        }

        imagePath = "../for_readme/3alb8.png";
        simGetPic(imagePath);
        for(int i1 = 0; i1 < 350; ++i1) {
            simFlush();
        }

        imagePath = "../for_readme/4alb8.png";
        simGetPic(imagePath);
        for(int i1 = 0; i1 < 350; ++i1) {
            simFlush();
        }

        imagePath = "../for_readme/5alb8.png";
        simGetPic(imagePath);
        for(int i1 = 0; i1 < 350; ++i1) {
            simFlush();
        }
    }
}