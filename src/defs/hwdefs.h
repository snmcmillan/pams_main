/**
 * @file hwdefs.h
 * @author Sebastian McMillan
 * @brief Hardware Config Definitions±
*/

#ifndef HWDEFS_H
#define HWDEFS_H
/**
 * Display Settings
 * 
 * These options are to configure display pinouts, touch settings, etc.
*/


/**
 * SPI Mode Toggle
 * 
 * 0: Run in 8-Bit Display Mode. This runs allegedly faster, but requires *significantly* more pins.
 *    This mode is not well tested, and is not very compatible. If you run this mode, be prepared to work
 *    on the code in both this project and the original libraries.
 * 
 * 1: Run in SPI Mode. This requires less pins and will be more compatible with other controllers.
 *    When in doubt, run in this mode.
*/
#define SPI_MODE 1

//Don't alter the logic here, but don't skip these either if you are rolling your own Micro Controller!
#if SPI_MODE == 1
    /**
     * SPI Mode Pin Settings
     * If running in SPI Mode, these pin definitions are what define the screen pins
    */
    #define TFT_RST -1  // Don't use a reset pin, tie to Arduino's RST if you like.
    #define TFT_DC 9
    #define TFT_CS 10

    #define YP A2  // Must be an analog pin, use "An" notation!
    #define XM A3  // Must be an analog pin, use "An" notation!
    #define YM A4  // Can be a digital pin if desired, using analog saves digital pins
    #define XP A5  // Can be a digital pin if desired, using analog saves digital pins
#else
    /**
     * 8-Bit Mode Pin Settings
     * If running in 8-Bit Mode, these pin definitions are what define the screen pins
    */
    #define LCD_CS A3
    #define LCD_CD A2
    #define LCD_WR A1
    #define LCD_RD A0
    #define LCD_RESET A4 //Optional, either use A4 or the RST Pin on the Arduino

    //Touch Screen Pins
    #define YP A3 // Must be an analog pin, use "An" notation!
    #define XM A2 // Must be an analog pin, use "An" notation!
    #define YM 9  // Can be a digital pin, we can save pins by doing so!
    #define XP 8  // Can be a digital pin, we can save pins by doing so!
#endif

// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 110
#define TS_MINY 80
#define TS_MAXX 900
#define TS_MAXY 940

//Touch screen sensitivity
#define MINPRESSURE 10
#define MAXPRESSURE 1000

/**
 * Serial Settings
 * 
 * These settings define our RX and TX pins for each monitor, as well as the baud rate
*/

#define MON1_RX 6
#define MON1_TX 7
#define MON2_RX 4 //Only used if MON_COUNT == 2 or 3
#define MON2_TX 5 //Only used if MON_COUNT == 2 or 3
#define MON3_RX 2 //Only used if MON_COUNT == 3
#define MON3_TX 3 //Only used if MON_COUNT == 3

#define BAUD_RATE 9600

/**
 * Monitor Count
 * 
 * Specifies the number of monitors we want to use.
 * 
 * Setting to 1 disables the system overview screen.
 * 
 * We support 1, 2, or 3 monitors, and if at runtime a monitor is missing, 
 * the program will crash until I implement a handler for that.
 * 
 * Setting a value of 0 will cause problems at compile time, and setting a value above 3
 * will break program logic.
*/
#define MON_COUNT 1

#endif