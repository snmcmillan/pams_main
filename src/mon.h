#ifndef MON_H
#define MON_H

#include "definitions/hwdefs.h"

class mon{
    public:
    #if DEMO == 1
        mon();
    #else
        mon(int TX_PIN, int RX_PIN);
    #endif
    void updateMon();


    
    protected:
    float temperature = 0;
    int errStatus = 0;
    int errCode = 0;

};
#endif