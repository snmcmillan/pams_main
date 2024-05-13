#include "mon.h"
#if DEMO == 1
    #include<time.h>
#endif


void mon::updateMon(){
    #if DEMO == 1
        temperature = (float) (rand()%10000) / 100;
        current = (float) (rand()%1000) / 100;
        signalPower = (float) (rand()%1000) / 100;
        forwardPower = (float) (rand()%1000) / 100;
        VSWR = (float) (rand()%1000) / 100;
    #else
        monSerial.listen();
        acknowledgeMon(23);
        waitForMon();
        temperature = monSerial.parseFloat();
        current = monSerial.parseFloat();
        inputPower = monSerial.parseFloat();
        outputPower = monSerial.parseFloat();
        VSWR = monSerial.parseFloat();
        thermalState = monSerial.parseInt();
        inputState = monSerial.parseInt();
        vswrState = monSerial.parseInt();
    #endif
}

/**
 * monInit: Initializes the serial interface to the monitor.
 * 
 * The monitor sends its name to the head unit.
*/

void mon::monInit(){
    monSerial.begin(BAUD_RATE);
    monSerial.listen();
    while(monSerial.available() == 0){
        acknowledgeMon(10);
    }
    monName = monSerial.readStringUntil('\n');
    acknowledgeMon(20);
    //updateMon();
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