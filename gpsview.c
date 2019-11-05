/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE:		gps-utils.c - This file defines the methods used to view the GPS data.
--
-- PROGRAM:			PiDCGPS
--
-- FUNCTIONS:
--                  void viewGPSLocation(struct gps_data_t *gps_data_ptr, bool isDataValid)
--
-- DATE:			Nov 01, 2019
--
-- REVISIONS:       (N/A)
--
-- DESIGNER:		Henry Ho
--
-- PROGRAMMER:		Henry Ho
--
----------------------------------------------------------------------------------------------------------------------*/
#include "gpsview.h"

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	viewGPSLocation
--
-- DATE:		Oct 31, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Henry Ho
--
-- PROGRAMMER:	Henry Ho
--
-- INTERFACE:	void viewGPSLocation(struct gps_data_t *gps_data_ptr, bool isGPSDataValid)
--                  struct gps_data_t *gps_data_ptr:    pointer to the gps_data_t struct provided by GPSD API
--                  void isGPSDataValid:                boolean flag for GPS data validity
--
-- RETURNS:		void
--
-- NOTES:
-- Call this function to view GPS location on Google Maps
----------------------------------------------------------------------------------------------------------------------*/
void viewGPSLocation(struct gps_data_t *gps_data_ptr, bool isDataValid) {
    if (!isDataValid) {
        return;
    }

    char * link = (char *) malloc(64);
    *link = '\0';

    char latitude[16];
    snprintf(latitude, sizeof(latitude), "%f", gps_data_ptr->fix.latitude);

    char longitude[16];
    snprintf(longitude, sizeof(longitude), "%f", gps_data_ptr->fix.longitude);

    strcat(link, "xdg-open https://www.google.ca/maps/@");
    strcat(link, latitude);
    strcat(link, ",");
    strcat(link, longitude);
    strcat(link, ",14z");

    system(link);

    free(link);
    exit(1);
}
