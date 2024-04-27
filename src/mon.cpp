#include "mon.h"
#if DEMO == 1
    #include<time.h>
#endif


void mon::updateMon(){
    #if DEMO == 1
        temperature = (float) (rand()%10000) / 100;
        current = (float) (rand()%1000) / 100;
        forwardPower = (float) (rand()%1000) / 100;
        reflectedPower = (float) (rand()%1000) / 100;
        signalPower = (float) (rand()%1000) / 100;
    #else
        monSerial.listen();
        acknowledgeMon(23);
        while(monSerial.available() == 0){}
        temperature = monSerial.parseFloat();
        current = monSerial.parseFloat();
        signalPower = monSerial.parseFloat();
        forwardPower = monSerial.parseFloat();
        reflectedPower = monSerial.parseFloat();
        temperatureState = monSerial.parseInt();
        currentState = monSerial.parseInt();
        signalPowerState = monSerial.parseInt();
        forwardPowerState = monSerial.parseInt();
        reflectedPowerState = monSerial.parseInt();

        if(!temperatureState || !currentState || !signalPowerState || !forwardPowerState || !reflectedPowerState)
            errState = true;
        else
            errState = false;
        
    #endif
}

void mon::monInit(){
    pinMode(MON1_RX, INPUT);
    pinMode(MON1_TX, OUTPUT);
    Serial.begin(9600);
    monSerial.begin(BAUD_RATE);
    monSerial.listen();
    acknowledgeMon(10);
    while(monSerial.available() == 0){}
    monName = monSerial.readStringUntil('\n');
    acknowledgeMon(20);
}

void mon::waitForMon(int code){
  while(monSerial.read() != code){}
  monSerial.read();
}

void mon::acknowledgeMon(int code){
  monSerial.write(code);
}