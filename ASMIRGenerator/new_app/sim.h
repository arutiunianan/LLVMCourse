//#define SIM_X_SIZE 5
//#define SIM_Y_SIZE 2

#define SIM_X_SIZE 512
#define SIM_Y_SIZE 256

void simInit();
void app();
void simExit();

void simFlush();
void simPutPixel(int x, int y, int argb);
int  simRand();