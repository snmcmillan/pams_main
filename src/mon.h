#ifndef MON_H
#define MON_H

#include "definitions/hwdefs.h"
#include <WString.h>
#if DEMO == 0
    #include <SoftwareSerial.h>
    #include <wiring_private.h>
#endif
class mon{
    public:
    #if DEMO == 1
        mon(){
            monName = "Test Mon1";
            
        };
    #else
        mon(int rx, int tx):monSerial{SoftwareSerial(rx, tx)}{  
        };
    #endif
    void updateMon();

    //Getters
    bool getErrorState(){return errState;};
    float getTemperature(){return temperature;};
    float getCurrent(){return current;};
    float getFwPwr(){return forwardPower;};
    float getRflPwr(){return reflectedPower;};
    float getSigPwr(){return signalPower;};
    String getMonName(){return monName;};

    void monInit();
    void acknowledgeMon(int code);
    void waitForMon(int code);
    
    private:
    float temperature = 0;
    float current = 0;
    float signalPower = 0;
    float forwardPower = 0;
    float reflectedPower = 0;
    

    /**
     * State Codes
     *  2: Upper Threshold Critical
     *  1: Upper Threshold Warning
     *  0: OK
     * -1: Lower Threshold Warning
     * -2: Lower Threshold Critical
     * 
    */
    int temperatureState = 0;
    int currentState = 0;
    int signalPowerState = 0;
    int forwardPowerState = 0;
    int reflectedPowerState = 0;

    bool errState = false; //If any of these are not 0, this will be true.
    
    String monName = "";
    #if DEMO == 0
        //int RX, TX;
        SoftwareSerial monSerial; 
    #endif

};
#endif