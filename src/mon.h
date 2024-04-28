#ifndef MON_H
#define MON_H

#include "defs/hwdefs.h"

#if DEMO == 0
    #include <SoftwareSerial.h>
#endif
class mon{
    public:
    #if DEMO == 1
        mon(){
            monName = "Test Mon1";
            
        };
    #else
        mon(int rx, int tx):monSerial{SoftwareSerial(rx, tx)}{};
    #endif

    void monInit(); //Initializes the monitor communications
    void updateMon(); //Fetches new data
    void acknowledgeMon(int code); //Sends a status code to the monitor
    void waitForMon(); //Waits for any data to appear from the monitor
    void waitForMon(int code); //Waits for the monitor to send a status code

    //Getters
    bool getErrorState(){return errState;};
    float getTemperature(){return temperature;};
    float getCurrent(){return current;};
    float getFwPwr(){return forwardPower;};
    float getRflPwr(){return reflectedPower;};
    float getSigPwr(){return signalPower;};
    String getMonName(){return monName;};
    
    private:
    //These are the sensor data readings.
    float temperature = 0;
    float current = 0;
    float signalPower = 0;
    float forwardPower = 0;
    float reflectedPower = 0;

    /**
     * Thresholds
     * Upper and lower thresholds for each measurement. These are the critical points.
    */
    float tempUpper = 0;
    float currentUpper = 0, currentLower = 0;
    float sigUpper = 0, sigLower = 0;
    float forUpper = 0, forLower = 0;
    float refUpper = 0, refLower = 0;

    /**
     * Temperature History:
    */
    float temperatureHistory[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


    /**
     * State Codes
     * True or 1: That reading indicates a problem
     * False or 0: All good.
     * 
    */
    bool temperatureState = 0;
    bool currentState = 0;
    bool signalPowerState = 0;
    bool forwardPowerState = 0;
    bool reflectedPowerState = 0;

    bool errState = false; //If any of these are not 0, this will be true.
    
    String monName = "";
    #if DEMO == 0
        //If we are running in head unitproduction mode, the serial interface is created.
        SoftwareSerial monSerial; 
    #endif

};
#endif