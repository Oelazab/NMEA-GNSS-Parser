#include "nmea_parser.h"
#include <stdio.h>

int main() {
    const char *nmea_sentence = "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    NMEAData data;

    if (parse_nmea_sentence(nmea_sentence, &data)) {
        printf("Time: %s\nLatitude: %.6f %c\nLongitude: %.6f %c\n", 
               data.time, data.latitude, data.latitude_dir, 
               data.longitude, data.longitude_dir);
    } else {
        printf("Failed to parse NMEA sentence.\n");
    }

    return 0;
}
