#include "userinterface.h"


userinterface::userinterface(){
    probeTouch();
}

void userinterface::screenInit(){
    #if SPI_MODE == 1
        tft.begin();
    #else
        tft.reset();
        tft.begin(0x8357);
        pinMode(13, OUTPUT);
    #endif
    mon1.monInit();
    tft.cp437(true);
    tft.setRotation(1);
    tft.fillScreen(RED);
    tft.fillScreen(GREEN);
    tft.fillScreen(backgroundColor);
}

void userinterface::probeTouch(){
    #if SPI_MODE == 1
        tp = ts.getPoint();
    #else
        digitalWrite(13, HIGH);
        tp = ts.getPoint();
        digitalWrite(13, LOW);
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
    #endif
        tp.x = map(tp.x, TS_MINX, TS_MAXX, 0, tft.width());
        tp.y = map(tp.y, TS_MINY, TS_MAXY, 0, tft.height());

}

bool userinterface::isTouching(){
    if(tp.z > MINPRESSURE && tp.z < MAXPRESSURE)
        return true;
    else return false;
}

void userinterface::toggleDarkMode(){
    uint16_t tmp = backgroundColor;
    backgroundColor = textColor;
    textColor = tmp;
    tft.fillScreen(backgroundColor);
}

void userinterface::displayMenu(){
    #if MON_COUNT == 1
        dispMonStatus(mon1);
    #else
        uint16_t tmp = RED;
        textColor = BLACK;
        backgroundColor = RED;
        tft.fillScreen(BLACK);
        tft.setTextSize(5);
        tft.setTextWrap(1);
        while(true){
            tmp = textColor;
            textColor = backgroundColor;
            backgroundColor = tmp;
            tft.setCursor(1, 1);
            tft.setTextColor(textColor, backgroundColor);
            tft.println("I TOLD YOU THIS WILL NOT WORK! \nYOU DARE TO DEFY ME? \nYOU DARE TO FIGHT ME?");
            delay(100);
        }
    #endif
}

void userinterface::dispMonStatus(mon monSelected){
    bool exit = false;
    uint16_t statColor = GREEN;

    
    tft.setTextSize(HEADING_SIZE);
    tft.setCursor(0,0);
    tft.setTextColor(textColor, backgroundColor);
    tft.print(monSelected.getMonName());

    tft.setTextSize(TEXT_SIZE);
    tft.setCursor(1,(HEADING_SIZE*8) + 4);
    tft.println(SCREEN_TEMPERATURE);
    tft.println(SCREEN_CURRENT);
    tft.println(SCREEN_SIGNAL_PWR);
    tft.println(SCREEN_FOR_PWR);
    tft.println(SCREEN_VSWR);
    tft.println(STATUS);


    
    while(exit == false){
        monSelected.updateMon();
        
        if(monSelected.getThermalState() == 1)
            statColor = TXT_COLOR_WARN;
        else if(monSelected.getThermalState() > 1)
            statColor = TXT_COLOR_CRIT;
        else statColor = TXT_COLOR_GOOD;
        tft.setCursor(sizeof(SCREEN_TEMPERATURE)*TEXT_SIZE*6, (8*HEADING_SIZE) + 4);
        tft.setTextColor(statColor, backgroundColor);
        tft.print(monSelected.getTemperature());
        tft.write(0xF8);
        tft.println("C  ");

        
        tft.setCursor(sizeof(SCREEN_CURRENT)*TEXT_SIZE*6, tft.getCursorY());
        tft.setTextColor(textColor, backgroundColor);
        tft.print(monSelected.getCurrent());
        tft.println(" A  ");

        if(monSelected.getInputState())
            statColor = TXT_COLOR_CRIT;
        else statColor = TXT_COLOR_GOOD;
        tft.setCursor(sizeof(SCREEN_SIGNAL_PWR)*TEXT_SIZE*6, tft.getCursorY());
        tft.setTextColor(statColor, backgroundColor);
        tft.print(monSelected.getInputPower());
        tft.println(" dBm  ");

        tft.setCursor(sizeof(SCREEN_FOR_PWR)*TEXT_SIZE*6, tft.getCursorY());
        tft.setTextColor(textColor, backgroundColor);
        tft.print(monSelected.getOutputPower());
        tft.println(" dBm  ");


        if(monSelected.getVSWRState() == 1)
            statColor = TXT_COLOR_WARN;
        else if(monSelected.getVSWRState() == 2)
            statColor = TXT_COLOR_CRIT;
        else statColor = TXT_COLOR_GOOD;
        tft.setCursor(sizeof(SCREEN_VSWR)*TEXT_SIZE*6 + 1, tft.getCursorY());
        tft.setTextColor(statColor, backgroundColor);
        tft.print(monSelected.getVSWR());
        tft.println("   ");

        tft.setCursor(sizeof(STATUS)*TEXT_SIZE*6, tft.getCursorY());
        if(monSelected.getVSWRState() == 2 || monSelected.getThermalState() > 1 || monSelected.getInputState()){
            tft.setTextColor(TXT_COLOR_CRIT, backgroundColor);
            tft.println(STATUS_CRIT);
        }
        else if(monSelected.getVSWRState() == 1 || monSelected.getThermalState() == 1){
            tft.setTextColor(TXT_COLOR_WARN, backgroundColor);
            tft.println(STATUS_WARN);
        }
        else{
            tft.setTextColor(TXT_COLOR_GOOD, backgroundColor);
            tft.println(STATUS_GOOD);
        }

        probeTouch();
        if(isTouching()){
            if(tp.x > 240){
                toggleDarkMode();
                exit = true;
            }
        }
    }
}