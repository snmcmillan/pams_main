/**
 * @author Sebastian McMillan
 * @brief Hardware Config Definitions
*/

#ifndef HWDEFS_H
#define HWDEFS_H
/**
 * Display Settings
 * 
 * These options are to configure display pinouts, touch settings, etc.
*/

// These are the four touchscreen analog pins
#define YP A2  // Must be an analog pin, use "An" notation!
#define XM A3  // Must be an analog pin, use "An" notation!
#define YM A4  // Can be a digital pin if desired, using analog saves digital pins
#define XP A5  // Can be a digital pin if desired, using analog saves digital pins

// The display uses hardware SPI, plus #9 & #10
#define TFT_RST -1  // Don't use a reset pin, tie to Arduino's RST if you like.
#define TFT_DC 9
#define TFT_CS 10

// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 110
#define TS_MINY 80
#define TS_MAXX 900
#define TS_MAXY 940

// //Touch screen sensitivity
#define MINPRESSURE 10
#define MAXPRESSURE 1000

/**
 * Serial Settings
 * 
 * These settings define our SoftwareSerial pins for each monitor, as well as the baud rate
*/

//Coming Soon!

/**
 * SD Card Settings
 * 
 * Configure SD Card Settings Here
*/

#define SD_CS 7 //SD Chip Select Pin
#define SD_CD 8 //SD Card Detect Pin
#define SD_CLK_SPEED 25 //SD Card Clock Rate (in MHz)

/**
 * Development Features
 * 
 * These features are here for development purposes, if you do not know what you are doing, do NOT touch these.
*/

/**
 * DEMO - Enables DEMO Mode
 * 
 * Valid Values: 0 or 1
 * 
 * 0: The head unit expects the monitoring unit to be present, 
 *    and will display data collected from the monitoring unit.
 * 
 * 1: The head unit will display simulated data from a simulated monitoring unit.
 *    If any monitoring units are connected in this mode, they will be ignored.
*/
#define DEMO 1

/**
 * MULTIMON - Enables Multi-Monitor Support
 * 
 * Valid Values: 0 or 1
 * 
 * 0: The head unit will only check for mon1 and will only display mon1's data.
 *    Any other monitoring unit will be ignored, and the UI will run in single monitor mode.
 * 
 * 1: The head unit supports up to 3 monitoring units to be displayed at one time.
 * 
 * NOTE: Only MULTIMON = 0 is implemented at this time. Setting to 1 will result in a nonfunctional head unit.
 * This toggle is only present for potential future features.
*/

#define MULTIMON 0

#endif