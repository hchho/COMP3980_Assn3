//
// Created by henry on 2019-11-01.
//

#include "gpsview.h"

void viewGPSLocation(struct gps_data_t *gps_data_ptr, bool isDataValid) {
    if (!isDataValid) {
        return;
    }

    char * link = (const char *) malloc(64);
    *link = '\0';

    char latitude[16];
    snprintf(latitude, sizeof(latitude), "%f", gps_data_ptr->fix.latitude);

    char longitude[16];
    snprintf(longitude, sizeof(longitude), "%f", gps_data_ptr->fix.longitude);

    strcat(link, "xdg-open https://www.google.ca/maps/@");
    strcat(link, latitude);
    strcat(link, ",");
    strcat(link, longitude);
    strcat(link, ",14z");

    system(link);

    free(link);
    exit(1);
}
