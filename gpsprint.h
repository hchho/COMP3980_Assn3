/*------------------------------------------------------------------------------------------------------------------
-- HEADER FILE:		gps-utils.h - This file declares the methods used to print the GPS data.
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

#ifndef ASSIGNMENT3_GPSPRINT_H
#define ASSIGNMENT3_GPSPRINT_H

#include <gps.h>
#include <stdlib.h>

void printGpsData(struct gps_data_t *gpsdata, bool isGPSDataValid);

#endif //ASSIGNMENT3_GPSPRINT_H
