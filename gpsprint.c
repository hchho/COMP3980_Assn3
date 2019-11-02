//
// Created by henry on 2019-10-29.
//

#include "gpsprint.h"
#include <gps.h>

void printGpsData(struct gps_data_t *gps_data_ptr) {
	int satellites_visible = gps_data_ptr->satellites_visible;
	for (int i = 0; i < satellites_visible; i++) {
	printf("latitude: %f, longitude: %f, timestamp: %lf, elevation: %d, PRN: %d, Azimuth: %d, Used: %s, SNR: %f\n", 
                        gps_data_ptr->fix.latitude,
                        gps_data_ptr->fix.longitude,
                        gps_data_ptr->fix.time,
			gps_data_ptr->skyview[i].elevation,
			gps_data_ptr->skyview[i].PRN,
			gps_data_ptr->skyview[i].azimuth,
			gps_data_ptr->skyview[i].used ? "Y" : "N",
			gps_data_ptr->skyview[i].ss);
	}
}
