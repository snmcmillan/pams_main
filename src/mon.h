#ifndef MON_H
#define MON_H

#include "definitions/hwdefs.h"
#include <WString.h>

class mon{
    public:
    #if DEMO == 1
        mon();
    #else
        mon(int rx, int tx){
            RX = rx;
            TX = tx;
        }
    #endif
    void updateMon();

    //Getters
    int getErrorCode(){
        return errCode;
    };

    bool getErrorStatus(){
        return errStatus;
    };

    float getTemperature(){
        return temperature;
    };

    float getCurrent(){
        return current;
    };

    float getFwPwr(){
        return forwardPower;
    };

    float getRflPwr(){
        return reflectedPower;
    };

    float getSigPwr(){
        return signalPower;
    };

    String getMonName(){
        return monName;
    };

    
    protected:
    float temperature = 0;
    float current = 0;
    float forwardPower = 0;
    float reflectedPower = 0;
    float signalPower = 0;
    bool errStatus = false;
    int errCode = 0;
    
    String monName = "";
    #if DEMO == 0
        int RX = -1;
        int TX = -1;
    #endif

};
#endif