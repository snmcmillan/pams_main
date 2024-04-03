
#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "definitions/hwdefs.h"
#include "definitions/colordefs.h"

#include <Adafruit_GFX.h>    // Core graphics library
#if SPI_MODE == 1
    #include <SPI.h>
    #include <Adafruit_HX8357.h>
#else
    #include <Adafruit_TFTLCD.h>
#endif
#include <TouchScreen.h>
#include "mon.h"

/**
 * Some definitions for the UI.
 * Mostly used to dynamically scale things.
*/

#define HEADING_SIZE 5  //Heading Size
#define TEXT_SIZE 2     //Standard Text Size
#define STAT_TEXT_SIZE 2    //Status Text Size, use TBD.

class userinterface{
    public:
    userinterface();
    
    void screenInit();

    void probeTouch();

    bool isTouching();

    void toggleDarkMode();

    void displayMenu();

    void dispMonStatus(mon monSelected);

    protected:
    #if SPI_MODE == 1
        Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
    #else
        Adafruit_TFTLCD tft = Adafruit_TFTLCD(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
    #endif

    TouchScreen ts = TouchScreen(XP, YP, XM, YM, 260);
    TSPoint tp;
    uint16_t textColor = TXT_COLOR, 
            backgroundColor = BG_COLOR, 
            statusTextGood = TXT_COLOR_GOOD,
            statusTextWarn = TXT_COLOR_WARN,
            statusTextCrit = TXT_COLOR_CRIT,
            statusText;

    #if MULTIMON == 1
        mon mon1 = mon();
        mon mon2 = mon();
        mon mon3 = mon();
    #else
        mon mon1 = mon();
    #endif
};







#endif