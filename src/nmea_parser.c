#include "nmea_parser.h"
#include <string.h>
#include <stdlib.h>

bool parse_nmea_sentence(const char *sentence, NMEAData *data) {
    if (strncmp(sentence, "$GPGGA", 6) != 0) return false;

    // Copy the sentence to avoid modifying the original string
    char buffer[100];
    strncpy(buffer, sentence, sizeof(buffer));
    buffer[sizeof(buffer) - 1] = '\0';

    char *token = strtok(buffer, ",");
    int field = 0;

    while (token) {
        switch (field) {
            case 1: // Time
                strncpy(data->time, token, sizeof(data->time) - 1);
                data->time[sizeof(data->time) - 1] = '\0';
                break;
            case 2: // Latitude
                data->latitude = atof(token);
                break;
            case 3: // Latitude direction
                data->latitude_dir = token[0];
                break;
            case 4: // Longitude
                data->longitude = atof(token);
                break;
            case 5: // Longitude direction
                data->longitude_dir = token[0];
                break;
            case 6: // GPS Quality Indicator
                data->quality_ind = atoi(token);
            break;
            case 7: // Number of satellites in view
                data->num_sat = atoi(token);
            break;
        }
        token = strtok(NULL, ",");
        field++;
    }

    return true;
}