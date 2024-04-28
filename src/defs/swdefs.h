/**
 * @file swdefs.h
 * @author Sebastian McMillan
 * @brief Software Configuration Definitions
*/

#ifndef SWDEFS_H
#define SWDEFS_H

/**
 * DEBUG - Enables Debug Mode
 * 
 * Valid Values: 0 or 1
 * 
 * 0: The head unit program will run normally, and will not communicate with a host computer.
 * 
 * 1: The head unit will print debug statements over USB serial to a connected computer.
 *    This will incur a significant performance penalty, so only use this mode if things are not working.
*/
#define DEBUG 0

/**
 * DEMO - Enables Demo Mode
 * 
 * Valid Values: 0 or 1
 * 
 * 0: The head unit expects the monitoring unit to be present, 
 *    and will display data collected from the monitoring unit.
 * 
 * 1: The head unit will display simulated data from a simulated monitoring unit.
 *    If any monitoring units are connected in this mode, they will be ignored.
*/
#define DEMO 0

#endif