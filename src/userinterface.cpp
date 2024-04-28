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

    tft.setTextSize(HEADING_SIZE);
    tft.setCursor(1,1);
    tft.setTextColor(textColor, backgroundColor);
    tft.print(monSelected.getMonName());

    tft.setTextSize(TEXT_SIZE);
    tft.setCursor(1,(HEADING_SIZE*8) + 4);
    tft.setTextColor(textColor, backgroundColor);
    tft.println(SCREEN_TEMPERATURE); //Length = 13
    
    //tft.setCursor(1,tft.getCursorY() + 1);
    tft.setTextColor(textColor, backgroundColor);
    tft.println(SCREEN_CURRENT);
    

    //tft.setCursor(1,tft.getCursorY() + 1);
    tft.setTextColor(textColor, backgroundColor);
    tft.println(SCREEN_SIGNAL_PWR);

    //tft.setCursor(1,tft.getCursorY() + 1);
    tft.setTextColor(textColor, backgroundColor);
    tft.println(SCREEN_FOR_PWR);
    
    //tft.setCursor(1,tft.getCursorY() + 1);
    tft.setTextColor(textColor, backgroundColor);
    tft.println(SCREEN_VSWR);
    
    while(exit == false){
        monSelected.updateMon();

        tft.setCursor(13*TEXT_SIZE*6, (8*HEADING_SIZE) + 4);
        tft.setTextColor(textColor, backgroundColor);
        tft.print(monSelected.getTemperature());
        tft.write(0xF8);
        tft.println("C  ");

        tft.setCursor(16*TEXT_SIZE*6 + 1, tft.getCursorY());
        tft.setTextColor(textColor, backgroundColor);
        tft.print(monSelected.getCurrent());
        tft.println(" A  ");

        tft.setCursor(15*TEXT_SIZE*6 + 1, tft.getCursorY());
        tft.setTextColor(textColor, backgroundColor);
        tft.print(monSelected.getInputPower());
        tft.println(" dBm  ");

        tft.setCursor(15*TEXT_SIZE*6 + 1, tft.getCursorY());
        tft.setTextColor(textColor, backgroundColor);
        tft.print(monSelected.getOutputPower());
        tft.println(" dBm  ");

        tft.setCursor(17*TEXT_SIZE*6 + 1, tft.getCursorY());
        tft.setTextColor(textColor, backgroundColor);
        tft.println(monSelected.getVSWR());

        probeTouch();
        if(isTouching()){
            if(tp.x > 240){
                toggleDarkMode();
                exit = true;
            }
        }
    }
}