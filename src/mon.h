#ifndef MON_H
#define MON_H

#include "defs/hwdefs.h"
#include "defs/swdefs.h"

#if DEBUG == 1
    #include <HardwareSerial.h>
#endif

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

    float getTemperature(){return temperature;};
    float getCurrent(){return current;};
    float getOutputPower(){return outputPower;};
    float getVSWR(){return VSWR;};
    float getInputPower(){return inputPower;};
    String getMonName(){return monName;};
    
    private:
    //These are the sensor data readings.
    float temperature = 0;
    float current = 0;
    float inputPower = 0;
    float outputPower = 0;
    float VSWR = 0;

    /**
     * Action Statuses
     * 
     * Temperature, input power, and VSWR are actively monitored, 
     * and will trigger a shutoff in wrong conditions.
    */
    

    
    String monName = "";
    #if DEMO == 0
        //If we are running in head unitproduction mode, the serial interface is created.
        SoftwareSerial monSerial; 
    #endif

};
#endif