#include "mon.h"
#if DEMO == 1
    #include<time.h>
#endif

mon::mon(){

}

void mon::updateMon(){
    #if DEMO == 1
        monName = "Testy Mon";
        temperature = (float) (rand()%10000) / 100;
        current = (float) (rand()%1000) / 100;
        forwardPower = (float) (rand()%1000) / 100;
        reflectedPower = (float) (rand()%1000) / 100;
        signalPower = (float) (rand()%1000) / 100;
        errCode = 0;
    #endif
}