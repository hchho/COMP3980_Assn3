/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE:		gps-utils.c - This file defines the methods used to print the GPS data.
--
-- PROGRAM:			PiDCGPS
--
-- FUNCTIONS:
--                  void printGpsData(struct gps_data_t *gpsdata, bool isGPSDataValid)
--
-- DATE:			Oct 29, 2019
--
-- REVISIONS:       (N/A)
--
-- DESIGNER:		Henry Ho
--
-- PROGRAMMER:		Henry Ho
--
----------------------------------------------------------------------------------------------------------------------*/
#include "gpsprint.h"
#include "main-utils.h"
#include <gps.h>

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	isGPSDataValid
--
-- DATE:		Oct 31, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Henry Ho
--
-- PROGRAMMER:	Michael Yu
--
-- INTERFACE:	void printGpsData(struct gps_data_t *gps_data_ptr, bool isGPSDataValid)
--                  struct gps_data_t *gps_data_ptr:    pointer to the gps_data_t struct provided by GPSD API
--                  void isGPSDataValid:                boolean flag for GPS data validity
--
-- RETURNS:		void
--
-- NOTES:
-- Call this function to print streaming GPS data
----------------------------------------------------------------------------------------------------------------------*/
void printGpsData(struct gps_data_t *gps_data_ptr, bool isGPSDataValid) {
    system("clear");
    int satellites_visible = gps_data_ptr->satellites_visible;
    printf("===============================================================================\n");
    printf("\t\t\t\tVisible Satellites: %d\n", satellites_visible);
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < satellites_visible; i++) {
        printf("Elevation: %d,\tPRN: %d,\tAzimuth: %d,\tUsed: %s,\t SNR: %f\n",
               gps_data_ptr->skyview[i].elevation,
               gps_data_ptr->skyview[i].PRN,
               gps_data_ptr->skyview[i].azimuth,
               gps_data_ptr->skyview[i].used ? "Y" : "N",
               gps_data_ptr->skyview[i].ss);
    }
    printf("===============================================================================\n");
    if (isGPSDataValid) {
        printf("Latitude: %f, Longitude: %f, Timestamp: %lf \n",
               gps_data_ptr->fix.latitude,
               gps_data_ptr->fix.longitude,
               gps_data_ptr->fix.time);
    } else {
        printf("No data.\n");
    }
}
