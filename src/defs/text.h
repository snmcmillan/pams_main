/**
 * text.h
 * 
 * These are compiler macros for the UI text.,
 * Makes it easy for anyone to perform translations 
 * without knowing any programming.
 * 
 * Ensure that each string is enclosed in quotation marks.
*/

/**
 * Escape Sequences 101: Some text has to be written differently
 * due to how strings are parsed. 
 * 
 * New Line (Enter Key): \n
 * Tab Key: \t
 * Quotation Mark: \"
 * Apostrophe: \'
 * Back Slash (\): \\
*/

#define MAIN_MENU_OVERVIEW "System Overview"

//Monitor Detailed Status Menu Text

#define SCREEN_TEMPERATURE "Temperature: "
#define SCREEN_CURRENT "Supply Current: "
#define SCREEN_SIGNAL_PWR "Input Power: "
#define SCREEN_FOR_PWR "Output Power: "
#define SCREEN_VSWR "VSWR: "

//Status Text

#define STATUS "Status: "
#define STATUS_GOOD "Good"
#define STATUS_WARN "Warning"
#define STATUS_CRIT "Critical"
#define STATUS_FAILURE "Failure"
#define STATUS_OFF "Off"

//Temperature Reading Statuses

#define STATUS_TEMP_HIGH "Power Amplifier is too hot."
#define STATUS_TEMP_SHUTOFF_RUNAWAY "Power Amplifier was shut off due to thermal runaway being detected."
#define STATUS_TEMP_SHUTOFF_OVERHEAT "Power Amplifier was shut off due to the temperature being too high. Wait for it to cool down."

//Current Reading Statuses

#define STATUS_CURRENT_HIGH "Too much current is being drawn from the power supply."
#define STATUS_CURRENT_LOW "Power Supply is not supplying enough current."
#define STATUS_CURRENT_ZERO "No current is being detected. Check the current sensor!"
#define STATUS_CURRENT_REVERSED "Negative current is being detected. Verify the orientation of the current sensor!"


// Everything below is still WIP

//Signal Power Readings

#define STATUS_SIGNAL_HIGH "Input signal power is too high!"


