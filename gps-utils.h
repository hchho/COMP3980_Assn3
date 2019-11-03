//
// Created by henry on 2019-10-29.
//

#ifndef ASSIGNMENT3_GPS_UTILS_H
#define ASSIGNMENT3_GPS_UTILS_H

#include <gps.h>

bool isGPSDataValid(struct gps_data_t *gpsdata);

void readGPSFunc(struct gps_data_t *gpsdata, void (fn)(struct gps_data_t*, bool));

#endif //ASSIGNMENT3_GPS_UTILS_H
