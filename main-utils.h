//
// Created by henry on 2019-11-01.
//

#ifndef ASSIGNMENT3_MAIN_UTILS_H
#define ASSIGNMENT3_MAIN_UTILS_H

#include <gps.h>

void handleError(int error);

void moveCursorUp(int numberOfLines);

void (*getOptionHandler(const int option))(struct gps_data_t *);

void printOptions();

#endif //ASSIGNMENT3_MAIN_UTILS_H
