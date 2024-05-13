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

    unsigned short getThermalState(){return thermalState;};
    bool getInputState(){return inputState;};
    unsigned short getVSWRState(){return vswrState;};
    bool getOverdriveState(){return overdriveState;};

    String getMonName(){return monName;};
    
    private:
    //These the readings we need to display to the user

    float temperature = 0;
    float current = 0;
    float inputPower = 0;
    float outputPower = 0;
    float VSWR = 0;

    /**
     * Thermal Status Codes
     * 
     * 0: Temperature OK
     * 1: Temperature Warning
     * 2: Temperature Critical - Maximum Reached
     * 3: Temperature Critical - Above Warning Threshold for too long.
     * 4: Thermal Runaway Detected 
     * Conditions 2, 3, and 4 are critical.
    */
    unsigned short thermalState = 0;

    /**
     * Input Power Status Code
     * 
     * 0 / False: Input Power OK
     * 1 / True: Input Power Critical
    */
    bool inputState = false;

    /**
     * VSWR Status Code
     * 0: VSWR Acceptable
     * 1: VSWR Above Warning
     * 2: VSWR Too High - trigger overdrive switch
    */
    unsigned short vswrState = false;

    bool overdriveState = false;   

    
    String monName = "";
    #if DEMO == 0
        //If we are running in head unit production mode, the serial interface is created.
        SoftwareSerial monSerial; 
    #endif

};
#endif