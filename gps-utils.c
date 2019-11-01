//
// Created by henry on 2019-10-29.
//

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "gpsprint.h"
#include "gps-utils.h"
#include "ERRNO.h"

bool isGPSDataValid(struct gps_data_t *gps_data_ptr) {
    return (gps_data_ptr->status == STATUS_FIX) &&
                    (gps_data_ptr->fix.mode == MODE_2D || gps_data_ptr->fix.mode == MODE_3D) &&
                    !isnan(gps_data_ptr->fix.latitude) && 
                    !isnan(gps_data_ptr->fix.longitude);
}

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
            if (gps_read(gps_data_ptr) == -1) { // Error getting GPS
                handleError(-2);
                exit(1);
            } else {
                if (isGPSDataValid(gps_data_ptr)) {
                    printGpsData(gps_data_ptr);
                } else {
                    printf("No GPS data\n");
                }
            }
        }
    }
}

void handleError(int error) {
    switch(error) {
        case -1:
            printf("GPS signal gone\n");
            break;
        case -2:
            printf("GPS error\n");
            break;
        case -3:
            printf("Timeout error\n");
            break;
        case -4:
            printf("Network error\n");
            break;
        default:
            printf("Unknown error\n");
            break;
    }
}
