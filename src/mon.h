#ifndef MON_H
#define MON_H

#include "definitions/hwdefs.h"
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
    float tempUpper = 0, tempLower = 0;
    float currentUpper = 0, currentLower = 0;
    float sigUpper = 0, sigLower = 0;
    float forUpper = 0, forLower = 0;
    float refUpper = 0, refLower = 0;


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
        //If we are running in head unitproduction mode, the serial interface is created.
        SoftwareSerial monSerial; 
    #endif

};
#endif