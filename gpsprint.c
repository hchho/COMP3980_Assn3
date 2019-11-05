/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE:		gps-utils.c - This file defines the methods used to print the GPS data.
--
-- PROGRAM:			PiDCGPS
--
-- FUNCTIONS:
--                  void printGpsData(struct gps_data_t *gpsdata, bool isGPSDataValid)
--                	char* convertTimestampToLocal(time_t rawTimestamp, char* datetimeBuf)
--
-- DATE:			Oct 29, 2019
--
-- REVISIONS:       Revision 1 - Michael Yu: Add conversion from timestamp to localtime 
--
-- DESIGNER:		Henry Ho, Michael Yu
--
-- PROGRAMMER:		Henry Ho, Michael Yu
--
----------------------------------------------------------------------------------------------------------------------*/
#include "gpsprint.h"
#include "main-utils.h"
#include <gps.h>
#include <time.h>

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	convertTimestampToLocal
--
-- DATE:		Nov 4, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Michael Yu
--
-- PROGRAMMER:	Michael Yu
--
-- INTERFACE:	char* convertTimestampToLocal(time_t rawTimestamp, char* datetimeBuf)
--                  time_t rawTimestamp:    UNIX timestamp value to be converted into a localtime string
--                  char* datetimeBuf       string containing the localtime value of the UNIX timestamp
--
-- RETURNS:		char*
--                  pointer to the buffer that contains the localtime value of the UNIX timestamp
--
-- NOTES:
-- Call this function to convert a UNIX timestamp to a localtime string format.
----------------------------------------------------------------------------------------------------------------------*/
char* convertTimestampToLocal(time_t rawTimestamp, char* datetimeBuf) {
		struct  tm ts;
		ts = *localtime(&rawTimestamp);
		strftime(datetimeBuf, sizeof(datetimeBuf), "%x | %H:%M:%S %Z", &ts);
		return datetimeBuf;
}

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
        printf("Elevation: %d,\tPRN: %.2d,\tAzimuth: %d,\tUsed: %s,\t SNR: %f\n",
               gps_data_ptr->skyview[i].elevation,
               gps_data_ptr->skyview[i].PRN,
               gps_data_ptr->skyview[i].azimuth,
               gps_data_ptr->skyview[i].used ? "Y" : "N",
               gps_data_ptr->skyview[i].ss);
    }
    printf("===============================================================================\n");

    if (isGPSDataValid) {
		char 	datetimeBuf[80];
                       unix_to_iso8601(gps_data_ptr->fix.time, datetimeBuf, sizeof(datetimeBuf));
		printf("Latitude: %f, Longitude: %f, UTC Time: %s \n",
               gps_data_ptr->fix.latitude,
               gps_data_ptr->fix.longitude,
               convertTimestampToLocal(gps_data_ptr->fix.time, datetimeBuf));
    } else {
        printf("No data.\n");
    }
}



=======
/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE:		gps-utils.c - This file defines the methods used to print the GPS data.
--
-- PROGRAM:			PiDCGPS
--
-- FUNCTIONS:
--                  void printGpsData(struct gps_data_t *gpsdata, bool isGPSDataValid)
--                	char* convertTimestampToLocal(time_t rawTimestamp, char* datetimeBuf)
--
-- DATE:			Oct 29, 2019
--
-- REVISIONS:       Revision 1 - Michael Yu: Add conversion from timestamp to localtime 
--
-- DESIGNER:		Henry Ho, Michael Yu
--
-- PROGRAMMER:		Henry Ho, Michael Yu
--
----------------------------------------------------------------------------------------------------------------------*/
#include "gpsprint.h"
#include "main-utils.h"
#include <gps.h>
#include <time.h>

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	convertTimestampToLocal
--
-- DATE:		Nov 4, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Michael Yu
--
-- PROGRAMMER:	Michael Yu
--
-- INTERFACE:	char* convertTimestampToLocal(time_t rawTimestamp, char* datetimeBuf)
--                  time_t rawTimestamp:    UNIX timestamp value to be converted into a localtime string
--                  char* datetimeBuf       string containing the localtime value of the UNIX timestamp
--
-- RETURNS:		char*
--                  pointer to the buffer that contains the localtime value of the UNIX timestamp
--
-- NOTES:
-- Call this function to convert a UNIX timestamp to a localtime string format.
----------------------------------------------------------------------------------------------------------------------*/
char* convertTimestampToLocal(time_t rawTimestamp, char* datetimeBuf) {
		struct  tm ts;
		ts = *localtime(&rawTimestamp);
		strftime(datetimeBuf, sizeof(datetimeBuf), "%x | %H:%M:%S %Z", &ts);
		return datetimeBuf;
}

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
		time_t rawTimestamp = gps_data_ptr->fix.time;
		char 	datetimeBuf[80];
		printf("Latitude: %f, Longitude: %f, Timestamp: %s \n",
               gps_data_ptr->fix.latitude,
               gps_data_ptr->fix.longitude,
               convertTimestampToLocal(rawTimestamp, datetimeBuf));
    } else {
        printf("No data.\n");
    }
}
