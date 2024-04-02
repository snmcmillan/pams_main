
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <Adafruit_GFX.h>    // Core graphics library
#include <SPI.h>
#include <Adafruit_HX8357.h>
#include <TouchScreen.h>
#include "definitions/hwdefs.h"
#include "definitions/colordefs.h"


/**
 * Some definitions for the UI.
 * Mostly used to dynamically scale things.
*/

#define HEADING_SIZE 5  //Heading Size
#define TEXT_SIZE 3     //Standard Text Size
#define STAT_TEXT_SIZE 2    //Status Text Size, use TBD.

class userinterface{
    public:
    userinterface();
    
    void screenInit();

    void probeTouch();

    bool isTouching();

    void displayMenu();

    void dispMonStatus();

    protected:
    Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
    TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
    TSPoint tp;
    uint16_t textColor, backgroundColor, statusText;
    
    String tempReading = "";
};







#endif