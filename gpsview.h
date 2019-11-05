/*------------------------------------------------------------------------------------------------------------------
-- HEADER FILE:		gps-utils.h - This file declares the methods used to view the GPS data.
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
#ifndef ASSIGNMENT3_GPSVIEW_H
#define ASSIGNMENT3_GPSVIEW_H

#include <gps.h>
#include <stdlib.h>
#include <string.h>
void viewGPSLocation(struct gps_data_t *gps_data_ptr, bool isDataValid);

#endif //ASSIGNMENT3_GPSVIEW_H

