#include "userinterface.h"
#if DEMO == 1
    #include<time.h>
#endif

userinterface ui = userinterface();

void setup(){
    ui.screenInit();
    Serial.begin(115200);
    Serial.println("setup() complete");
    #if DEMO == 1
        srand(time(NULL));
    #endif
}

void loop(){
    ui.displayMenu();
}