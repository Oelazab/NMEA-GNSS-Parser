#ifndef NMEA_PARSER_H
#define NMEA_PARSER_H

#include <stdbool.h>

typedef struct {
    char    time[7];        // HHMMSS format
    double  latitude;       // Degrees
    char    latitude_dir;   // N or S
    double  longitude;      // Degrees
    char    longitude_dir;  // E or W
} NMEAData;

// Function to parse an NMEA sentence
bool parse_nmea_sentence(const char *sentence, NMEAData *data);

#endif // NMEA_PARSER_H
