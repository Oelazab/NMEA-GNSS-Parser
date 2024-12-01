#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char    time[7];        // HHMMSS format
    double  latitude;       // Degrees
    char    latitude_dir;   // N or S
    double  longitude;      // Degrees
    char    longitude_dir;  // E or W
    int     quality_ind;    // GPS Quality Indicator
    int     num_sat;         // Number of satellites in view
} NMEAData;

// Function to parse an NMEA sentence
bool parse_nmea_sentence(const char *sentence, NMEAData *data);

void plotData(NMEAData *data);

int main() {
    const char *nmea_sentence = "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    NMEAData data;
    if (parse_nmea_sentence(nmea_sentence, &data)) {
        plotData(&data);
    } else {
        printf("Failed to parse NMEA sentence.\n");
    }
    return 0;
}
void plotData(NMEAData *data){
    printf("Time: %c%c:%c%c:%c%c\n",
        data->time[0], 
        data->time[1], 
        data->time[2], 
        data->time[3], 
        data->time[4], 
        data->time[5]);
    
    printf("Latitude: %.8f %c\n"
        "Longitude: %.8f %c\n",
        data->latitude, 
        data->latitude_dir, 
        data->longitude, 
        data->longitude_dir);

    printf("Status: %s\n",
        (data->quality_ind)?
        ((data->quality_ind==1)?
        ((char*)"GPS fix"):((char*)"Differential GPS fix")):((char*)"fix not available"));
        
    printf("SAT in view: %d\n",
        data->num_sat);
}

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