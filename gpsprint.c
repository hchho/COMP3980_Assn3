//
// Created by henry on 2019-10-29.
//

#include "gpsprint.h"
#include <gps.h>

void printGpsData(struct gps_data_t *gps_data_ptr) {
	printf("latitude: %f, longitude: %f, speed: %f, timestamp: %lf\n", 
                        gps_data_ptr->fix.latitude,
                        gps_data_ptr->fix.longitude,
                        gps_data_ptr->fix.speed,
                        gps_data_ptr->fix.time);
}
