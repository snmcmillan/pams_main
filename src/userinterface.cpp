#include "userinterface.h"


userinterface::userinterface(){
    tp = ts.getPoint();
    tp.x = map(tp.x, TS_MINX, TS_MAXX, 0, tft.width());
    tp.y = map(tp.y, TS_MINY, TS_MAXY, 0, tft.height());
}

void userinterface::screenInit(){
    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(BG_COLOR);
}

void userinterface::probeTouch(){
    tp = ts.getPoint();
    tp.x = map(tp.x, TS_MINX, TS_MAXX, 0, tft.width());
    tp.y = map(tp.y, TS_MINY, TS_MAXY, 0, tft.height());
}

bool userinterface::isTouching(){
    if(tp.z > MINPRESSURE && tp.z < MAXPRESSURE)
        return true;
    else return false;
}

void userinterface::displayMenu(){
    #if MULTIMON == 0
        dispMonStatus();
    #endif
}

void userinterface::dispMonStatus(){
    probeTouch();
    if(tp.z > 0){
        if(tp.x > 240){
            if(backgroundColor == WHITE)
                tft.fillScreen(BLACK);
            textColor = WHITE;
            backgroundColor = BLACK;
        }
        if(tp.y > 160){
            statusText = TXT_COLOR_CRIT;
            tempReading = "420*C";
        }
    }
       
    if(tp.z == 0 || (tp.x <= 240 && tp.y <= 160)) {
            if(backgroundColor == BLACK)
                tft.fillScreen(WHITE);
            textColor = BLACK;
            backgroundColor = WHITE;
            statusText = TXT_COLOR_GOOD;
            tempReading = "69*C ";
    }
    

    tft.setTextSize(HEADING_SIZE);
    tft.setCursor(1,1);
    tft.setTextColor(textColor, backgroundColor);
    tft.print("Monitor 1");

    tft.setTextSize(TEXT_SIZE);
    tft.setCursor(1,(HEADING_SIZE*8) + 2);
    tft.setTextColor(textColor, backgroundColor);
    tft.print("Temperature: ");
    tft.setTextColor(statusText, backgroundColor);
    tft.println(tempReading);


}