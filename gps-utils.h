/*------------------------------------------------------------------------------------------------------------------
-- HEADER FILE:		gps-utils.h - This file declares the methods used to read the GPS streaming data.
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

#ifndef ASSIGNMENT3_GPS_UTILS_H
#define ASSIGNMENT3_GPS_UTILS_H

#include <gps.h>
#include "ERRNO.h"

bool isGPSDataValid(struct gps_data_t *gpsdata);

void readGPSFunc(struct gps_data_t *gpsdata, void (fn)(struct gps_data_t*, bool));

#endif //ASSIGNMENT3_GPS_UTILS_H

