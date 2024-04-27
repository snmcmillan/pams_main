#include "userinterface.h"
#if DEMO == 1
    #include<time.h>
#endif

userinterface ui;

void setup(){
    ui = userinterface();
    ui.screenInit();
    #if DEMO == 1
        srand(time(NULL));
    #endif
}

void loop(){
    ui.displayMenu();
}