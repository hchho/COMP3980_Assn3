//
// Created by henry on 2019-10-29.
//

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "gpsprint.h"
#include "gps-utils.h"
#include "ERRNO.h"

void readGPSFunc(struct gps_data_t *gps_data_ptr) {
    const int TIMEOUT = 500000; // 1/2 second timeout
    const int MAX_WAIT = 20;
    int wait_count = 0;
    for (;;) {
        if (!gps_waiting(gps_data_ptr, TIMEOUT)) {
            if (wait_count++ > MAX_WAIT) {
                handleError(-3);
                exit(1);
            }
        } else {
            errno = 0;
            wait_count = 0;
            char * msg = {0};
            if (gps_read(gps_data_ptr, msg, sizeof(msg)) == -1) { // Error getting GPS
                handleError(-2);
                exit(1);
            } else {
                printGpsData(gps_data_ptr);
            }
        }
    }
}

void handleError(int error) {
    switch(error) {
        case -1:
            printf("GPS signal gone");
            break;
        case -2:
            printf("GPS error");
            break;
        case -3:
            printf("Timeout error");
            break;
        case -4:
            printf("Network error");
            break;
        default:
            printf("Unknown error");
            break;
    }
}