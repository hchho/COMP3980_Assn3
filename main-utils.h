//
// Created by henry on 2019-11-01.
//

#ifndef ASSIGNMENT3_MAIN_UTILS_H
#define ASSIGNMENT3_MAIN_UTILS_H

#include <gps.h>

void setupSocket();

void handleError(int error);

void moveCursorUp(int numberOfLines);

void (*getOptionHandler(const int option))(struct gps_data_t *, bool);

void printOptions();

#endif //ASSIGNMENT3_MAIN_UTILS_H
