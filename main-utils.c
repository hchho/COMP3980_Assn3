/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE:		main-utils.c - This file consists of utility methods in the application level
--
-- PROGRAM:			PiDCGPS
--
-- FUNCTIONS:
--                  void setupSocket(void)
--                  void moveCursorUp(int numberOfLines)
--                  void handleError(int errorNumber)
--                  void (*getOptionHandler(const int option))(struct gps_data_t *, bool)
--                  void printOptions(void)
--
-- DATE:			Nov 02, 2019
--
-- REVISIONS:       (N/A)
--
-- DESIGNER:		Henry Ho
--
-- PROGRAMMER:		Henry Ho
--
----------------------------------------------------------------------------------------------------------------------*/

#include <stdlib.h>
#include "gpsprint.h"
#include "gpsview.h"
#include "main-utils.h"

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	setupSocket
--
-- DATE:		Nov 02, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Henry Ho
--
-- PROGRAMMER:	Henry Ho
--
-- INTERFACE:	void setupSocket(void)
--
-- RETURNS:		void
--
-- NOTES:
-- Call this function to set up the socket for gpsd
----------------------------------------------------------------------------------------------------------------------*/
void setupSocket() {
    system("sudo systemctl stop gpsd.socket");
    system("sudo systemctl disable gpsd.socket");
    system("sudo gpsd /dev/ttyUSB0 -F /var/run/gpsd.socket");
    system("clear");
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	moveCursorUp
--
-- DATE:		Nov 02, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Henry Ho
--
-- PROGRAMMER:	Henry Ho
--
-- INTERFACE:	void setupSocket(int numberOfLines)
--                  int numberOfLines:  number of lines to move up the terminal cursor
--
-- RETURNS:		void
--
-- NOTES:
-- Call this function to move the terminal cursor upwards
----------------------------------------------------------------------------------------------------------------------*/
void moveCursorUp(int numberOfLines) {
    printf("%c[%dA", 033, numberOfLines);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	handleError
--
-- DATE:		Nov 02, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Henry Ho
--
-- PROGRAMMER:	Henry Ho
--
-- INTERFACE:	void handleError(int error)
--                  int error:  error code
--
-- RETURNS:		void
--
-- NOTES:
-- Call this function to handle a program error
----------------------------------------------------------------------------------------------------------------------*/
void handleError(int error) {
    switch(error) {
        case GPS_GONE:
            printf("GPS signal gone\n");
            break;
        case GPS_ERROR:
            printf("GPS error\n");
            break;
        case GPS_TIMEOUT:
            printf("Timeout error\n");
            break;
        case NETWORK_ERROR:
            printf("Network error\n");
            break;
        default:
            printf("Unknown error\n");
            break;
    }
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	getOptionHandler
--
-- DATE:		Nov 02, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Henry Ho
--
-- PROGRAMMER:	Henry Ho
--
-- INTERFACE:	void (*getOptionHandler(const int option))(struct gps_data_t *, bool)
--                  const int option:   program option number user enters
--
-- RETURNS:		void (*) (struct gps_data_t *, bool)
--
-- NOTES:
-- Call this function to return a function that handles GPS data based on the user input. FOr example, if
-- if the user wishes to view GPS location on Google Maps, this method will return viewGPSLocation, which
-- accepts a gps_data_t struct and a boolean flag.
----------------------------------------------------------------------------------------------------------------------*/
void (*getOptionHandler(const int option))(struct gps_data_t *, bool) {
    switch(option) {
        case 1: // Stream GPS data
            return printGpsData;
        case 2: // View location on map
            return viewGPSLocation;
        default:
            printf("Unvailable option\n");
            exit(1);
    }
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	printOptions
--
-- DATE:		Nov 02, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Henry Ho
--
-- PROGRAMMER:	Henry Ho
--
-- INTERFACE:	void printOptions(void)
--
-- RETURNS:		void
--
-- NOTES:
-- Call this function to print program options on the terminal
----------------------------------------------------------------------------------------------------------------------*/
void printOptions() {
    printf("Enter option for this program:\n");
    printf("1 - Stream live GPS data\n");
    printf("2 - View location on Google Maps\n");
}
