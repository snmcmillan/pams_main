#include "userinterface.h"

userinterface ui = userinterface();

void setup(){
    ui.screenInit();
    Serial.begin(115200);
    Serial.println("setup() complete");
}

void loop(){
    ui.displayMenu();
}