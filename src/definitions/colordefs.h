/**
 * @author Sebastian McMillan
 * @brief Definitions of colors.
 * 
 * The Adafruit GFX Library (in which is used in this project) uses RGB565 colors.
 * These are 16-bit color definitions that are much different from RGB888 that we're used to.
 * 
 * I personally recommend reading https://barth-dev.de/online/rgb565-color-picker/
 * as it has a great write up on it.
 * 
 * TLDR: Red has 5 bits, green has 6 bits, blue has 5 bits. That site also has a color picker that produces RGB565 colors.
*/

//Defining our color palette here. If you need more than this, add onto here.
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define ORANGE 0xFC80
#define LIGHT_GREY 0xD6BA
#define LIGHT_GRAY 0xD6BA //I sadly need to ensure the inferior spelling is defined.

/**
 * UI Modes
 * 
 * TODO: Implement color-blind modes and dark mode
*/

/**
 * UI Colors
 * 
 * Don't changes these unless you *really* need a special color palette.
*/

#define BG_COLOR WHITE
#define BG_BUTTON_PRESSED LIGHT_GREY
#define TXT_COLOR BLACK
#define TXT_COLOR_CRIT RED
#define TXT_COLOR_WARN ORANGE
#define TXT_COLOR_GOOD GREEN
