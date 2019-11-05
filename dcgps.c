/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE:		dcgps.c - This file contains the main function to start the program
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
-- NOTES:
-- This is the starting point for the application.
----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gps.h>
#include "dcgps.h"
#include "ERRNO.h"
#include "main-utils.h"

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	main
--
-- DATE:		Nov 02, 2019
--
-- REVISIONS:	(N/A)
--
-- DESIGNER:	Michael Yu
--
-- PROGRAMMER:	Michael Yu
--
-- INTERFACE:	int main(void)
--
-- RETURNS:		int
--
-- NOTES:
-- Call this function to start the program. This is where the program opens the sockets, accepts user input, and
-- calls the main reading loop to process GPS data.
----------------------------------------------------------------------------------------------------------------------*/
int main() {
    setupSocket();

    static struct fixsource_t source;
    struct gps_data_t *gps_data_ptr = malloc(sizeof(struct gps_data_t));
    
    source.server = LOCAL_HOST;
    source.port = DEFAULT_GPSD_PORT;

    unsigned int flags = WATCH_ENABLE | WATCH_JSON;
    
    if (gps_open(source.server, source.port, gps_data_ptr) != 0) {
        handleError(NETWORK_ERROR);
        exit(1);
    }

    if (source.device != NULL) {
        flags |= WATCH_DEVICE;
    }

    gps_stream(gps_data_ptr, flags, NULL);

    int input[1];
    printOptions();
    scanf("%d", input);

    void (*handler)(struct gps_data_t *) = getOptionHandler(input[0]);

    readGPSFunc(gps_data_ptr, handler);

    gps_stream(gps_data_ptr, WATCH_DISABLE, NULL);
    gps_close(gps_data_ptr);
    free(gps_data_ptr);

    return 0;
}
