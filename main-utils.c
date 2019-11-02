//
// Created by henry on 2019-11-01.
//

#include <stdlib.h>
#include "gpsprint.h"
#include "gpsview.h"
#include "main-utils.h"

void moveCursorUp(int numberOfLines) {
    printf("%c[%dA", 033, numberOfLines);
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

void (*getOptionHandler(const int option))(struct gps_data_t *) {
    switch(option) {
        case 1: // Stream GPS data
            return printGpsData;
        case 2: // View location on map
            return viewGPSLocation;
        default:
            printf("Unvailable option\n");
            exit(1);
            return;
    }
}

void printOptions() {
    printf("Enter option for this program:\n");
    printf("1 - Stream live GPS data\n");
    printf("2 - View location on Google Maps\n");
}