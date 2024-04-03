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

    tft.cp437(true);
    tft.setRotation(1);
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
    #if MULTIMON == 0
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
            tft.println("I TOLD YOU THIS WILL NOT WORK! YOU DARE TO DEFY ME? YOU DARE TO FIGHT ME?");
            delay(1000);
        }
    #endif
}

void userinterface::dispMonStatus(mon monSelected){
    probeTouch();
    if(isTouching()){
        if(tp.x > 240){
            toggleDarkMode();
        }
        if(tp.y > 160){
            statusText = TXT_COLOR_CRIT;
        }
    }
    
    monSelected.updateMon();  

    tft.setTextSize(HEADING_SIZE);
    tft.setCursor(1,1);
    tft.setTextColor(textColor, backgroundColor);
    tft.print(monSelected.getMonName());

    tft.setTextSize(TEXT_SIZE);
    tft.setCursor(1,(HEADING_SIZE*8) + 4);
    tft.setTextColor(textColor, backgroundColor);
    tft.print("Temperature: ");
    tft.setTextColor(statusText, backgroundColor);
    tft.print(monSelected.getTemperature());
    tft.write(0xF8);
    tft.println("C  ");

    //tft.setCursor(1,tft.getCursorY() + 1);
    tft.setTextColor(textColor, backgroundColor);
    tft.print("Supply Current: ");
    tft.setTextColor(statusText, backgroundColor);
    tft.print(monSelected.getCurrent());
    tft.println(" A  ");

    //tft.setCursor(1,tft.getCursorY() + 1);
    tft.setTextColor(textColor, backgroundColor);
    tft.print("Signal Power: ");
    tft.setTextColor(statusText, backgroundColor);
    tft.print(monSelected.getSigPwr());
    tft.println(" dBm  ");

    //tft.setCursor(1,tft.getCursorY() + 1);
    tft.setTextColor(textColor, backgroundColor);
    tft.print("Forward Power: ");
    tft.setTextColor(statusText, backgroundColor);
    tft.print(monSelected.getFwPwr());
    tft.println(" dBm ");

    //tft.setCursor(1,tft.getCursorY() + 1);
    tft.setTextColor(textColor, backgroundColor);
    tft.print("Reflected Power: ");
    tft.setTextColor(statusText, backgroundColor);
    tft.print(monSelected.getRflPwr());
    tft.println(" dBm ");

}