/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE:		gps-utils.c - This file defines the methods used to read the GPS streaming data.
--
-- PROGRAM:			PiDCGPS
--
-- FUNCTIONS:
--                  bool isGPSDataValid(struct gps_data_t *gpsdata)
--                  void readGPSFunc(struct gps_data_t *gpsdata, void (fn)(struct gps_data_t*, bool))
--
-- DATE:			Oct 28, 2019
--
-- REVISIONS:       (N/A)
--
-- DESIGNER:		Henry Ho
--
-- PROGRAMMER:		Henry Ho
--
----------------------------------------------------------------------------------------------------------------------*/

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "gpsprint.h"
#include "gps-utils.h"
#include "main-utils.h"
#include "ERRNO.h"

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	isGPSDataValid
--
-- DATE:		Oct 31, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Henry Ho
--
-- PROGRAMMER:	Henry Ho
--
-- INTERFACE:	bool isGPSDataValid(struct gps_data_t *gps_data_ptr)
--                  struct gps_data_t *gps_data_ptr:    pointer to the gps_data_t struct provided by GPSD API
--
-- RETURNS:		bool
--
-- NOTES:
-- Call this function to check if the GPS data received is valid for displaying
----------------------------------------------------------------------------------------------------------------------*/
bool isGPSDataValid(struct gps_data_t *gps_data_ptr) {
    return (gps_data_ptr->status == STATUS_FIX) &&
                    (gps_data_ptr->fix.mode == MODE_2D || gps_data_ptr->fix.mode == MODE_3D) &&
                    !isnan(gps_data_ptr->fix.latitude) && 
                    !isnan(gps_data_ptr->fix.longitude);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	readGPSFunc
--
-- DATE:		Nov 01, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Henry Ho
--
-- PROGRAMMER:	Henry Ho
--
-- INTERFACE:	void readGPSFunc(struct gps_data_t *gps_data_ptr, void (gpsDataHandler)(struct gps_data_t *, bool))
--                  struct gps_data_t *gps_data_ptr:                    pointer to the gps_data_t struct provided by
--                                                                      GPSD API
--                  void (gpsDataHandler)(struct gps_data_t *, bool):   the function that handles the GPS data
--
-- RETURNS:		void
--
-- NOTES:
-- Call this function to run the main loop that reads the GPS data stream. It waits for any incoming data and calls
-- gpsDataHandler to handle any incoming data.
----------------------------------------------------------------------------------------------------------------------*/
void readGPSFunc(struct gps_data_t *gps_data_ptr, void (gpsDataHandler)(struct gps_data_t *, bool)) {
    const int TIMEOUT = 500000; // 1/2 second timeout
    const int MAX_WAIT = 20;
    int wait_count = 0;
    for (;;) {
        if (!gps_waiting(gps_data_ptr, TIMEOUT)) {
            printf("Waiting...%d sec\n", wait_count / 2);
            if (wait_count++ > MAX_WAIT) {
                handleError(-3);
                exit(1);
            }
            moveCursorUp(1);
        } else {
            wait_count = 0;
            if (gps_read(gps_data_ptr) == -1) { // Error getting GPS
                handleError(-2);
                exit(1);
            } else {
                gpsDataHandler(gps_data_ptr, isGPSDataValid(gps_data_ptr));
            }
        }
    }
}
