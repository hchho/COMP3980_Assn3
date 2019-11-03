/*------------------------------------------------------------------------------------------------------------------
-- HEADER FILE:		main-utils.h - This file declares the methods used on the application level.
--
-- PROGRAM:			PiDCGPS
--
-- FUNCTIONS:
--                  void setupSocket(void)
--                  void moveCursorUp(int numberOfLines)
--                  void handleError(int errorNumber)
--                  void (*getOptionHandler(const int option))(struct gps_data_t *, bool)
--                  void printOptions(void)
--
-- DATE:			Nov 02, 2019
--
-- REVISIONS:       (N/A)
--
-- DESIGNER:		Henry Ho
--
-- PROGRAMMER:		Henry Ho
--
----------------------------------------------------------------------------------------------------------------------*/

#ifndef ASSIGNMENT3_MAIN_UTILS_H
#define ASSIGNMENT3_MAIN_UTILS_H

#include <gps.h>

void setupSocket();

void handleError(int error);

void moveCursorUp(int numberOfLines);

void (*getOptionHandler(const int option))(struct gps_data_t *, bool);

void printOptions();

#endif //ASSIGNMENT3_MAIN_UTILS_H
