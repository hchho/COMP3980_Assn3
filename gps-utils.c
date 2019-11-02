//
// Created by henry on 2019-10-29.
//

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "gpsprint.h"
#include "gps-utils.h"
#include "main-utils.h"
#include "ERRNO.h"

bool isGPSDataValid(struct gps_data_t *gps_data_ptr) {
    return (gps_data_ptr->status == STATUS_FIX) &&
                    (gps_data_ptr->fix.mode == MODE_2D || gps_data_ptr->fix.mode == MODE_3D) &&
                    !isnan(gps_data_ptr->fix.latitude) && 
                    !isnan(gps_data_ptr->fix.longitude);
}

void readGPSFunc(struct gps_data_t *gps_data_ptr, void (gpsProcessor)(struct gps_data_t *)) {
    const int TIMEOUT = 500000; // 1/2 second timeout
    const int MAX_WAIT = 20;
    int wait_count = 0;
    for (;;) {
        if (!gps_waiting(gps_data_ptr, TIMEOUT)) {
            printf("Waiting...%d sec\n", wait_count / 2);
            if (wait_count++ > MAX_WAIT) {
                handleError(-3);
                exit(1);
            }
            moveCursorUp(1);
        } else {
            errno = 0;
            wait_count = 0;
            if (gps_read(gps_data_ptr) == -1) { // Error getting GPS
                handleError(-2);
                exit(1);
            } else {
                if (isGPSDataValid(gps_data_ptr)) {
                    gpsProcessor(gps_data_ptr);
                }
            }
        }
    }
}
