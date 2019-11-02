#include <stdio.h>
#include <stdlib.h>
#include <gps.h>
#include "dcgps.h"
#include "gps-utils.h"
#include "gpsprint.h"
#include "ERRNO.h"

int main() {

    static struct fixsource_t source;
    struct gps_data_t *gps_data_ptr = malloc(sizeof(struct gps_data_t));
    
    source.server = LOCAL_HOST;
    source.port = DEFAULT_GPSD_PORT;

    unsigned int flags = WATCH_ENABLE | WATCH_JSON;
    
    if (gps_open(source.server, source.port, gps_data_ptr) != 0) {
        handleError(-4);
        exit(1);
    } 

    if (source.device != NULL) {
        flags |= WATCH_DEVICE;
    }

    gps_stream(gps_data_ptr, flags, NULL);

    int input[1];
    printf("Enter option for this program:\n");
    printf("1 - Stream live GPS data\n");
    printf("2 - View location on Google Maps\n");
    scanf("%d", input);

    void (*handler)(struct gps_data_t *) = getHandler(input[0]);

    readGPSFunc(gps_data_ptr, handler);

    gps_stream(gps_data_ptr, WATCH_DISABLE, NULL);
    gps_close(gps_data_ptr);
    free(gps_data_ptr);

    return 0;
}
