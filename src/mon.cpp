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
        waitForMon();
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

/**
 * monInit: Initializes the serial interface to the monitor.
 * 
 * The monitor sends its name to the head unit, 
 * along with its critical thresholds.
*/

void mon::monInit(){
    monSerial.begin(BAUD_RATE);
    monSerial.listen();
    acknowledgeMon(10);
    while(monSerial.available() == 0){}
    monName = monSerial.readStringUntil('\n');
    acknowledgeMon(20);
}

/**
 * waitForMon: Waits for any data to be sent from the monitor.
 * 
 * This variant does not discard any data. 
 * Once any data is read, execution continues.
*/
void mon::waitForMon(){
    while(monSerial.peek() == -1){}
}

/**
 * waitForMon: Waits for the monitor to send the supplied code.
 * 
 * This variant discards all data until the specified code is read.
 * Once the code is read, it is also discarded.
*/
void mon::waitForMon(int code){
  while(monSerial.read() != code){}
}

/**
 * acknowledgeMon: Sends a supplied status code to the monitor.
*/
void mon::acknowledgeMon(int code){
  monSerial.write(code);
}