//
// Created by henry on 2019-10-29.
//

#include "gpsprint.h"
#include "main-utils.h"
#include <gps.h>

void printGpsData(struct gps_data_t *gps_data_ptr) {
    system("clear");
    int satellites_visible = gps_data_ptr->satellites_visible;
    printf("===============================================================================\n");
    printf("\t\t\t\tVisible Satellites: %d\n", satellites_visible);
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < satellites_visible; i++) {
        printf("Elevation: %d,\tPRN: %d,\tAzimuth: %d,\tUsed: %s,\t SNR: %f\n",
               gps_data_ptr->skyview[i].elevation,
               gps_data_ptr->skyview[i].PRN,
               gps_data_ptr->skyview[i].azimuth,
               gps_data_ptr->skyview[i].used ? "Y" : "N",
               gps_data_ptr->skyview[i].ss);
    }
    printf("===============================================================================\n");
    printf("Latitude: %f, Longitude: %f, Timestamp: %lf \n",
           gps_data_ptr->fix.latitude,
           gps_data_ptr->fix.longitude,
           gps_data_ptr->fix.time);
}
