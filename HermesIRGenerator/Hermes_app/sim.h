#define SIM_X_SIZE 512
#define SIM_Y_SIZE 512

void simInit();
void app();
void simExit();

void simGetMus();
void simGetPic(char *imgPath);
void simFlush();
int  simRand();