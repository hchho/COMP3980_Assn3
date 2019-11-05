/*------------------------------------------------------------------------------------------------------------------
-- HEADER FILE:		dcgps.h - This file defines the fixsource_t struct and the local host address
--
-- PROGRAM:			PiDCGPS
--
-- FUNCTIONS:       N/A
--
-- DATE:			Oct 28, 2019
--
-- REVISIONS:       (N/A)
--
-- DESIGNER:		Michael Yu
--
-- PROGRAMMER:		Michael Yu
--
----------------------------------------------------------------------------------------------------------------------*/

#include <gps.h>
#include "gps-utils.h"
#define LOCAL_HOST "127.0.0.1"

struct fixsource_t{
    char *spec;         /* pointer to actual storage */
    char *server;
    char *port;
    char *device;
};
