#include "nmea_parser.h"
#include <stdio.h>

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
        
    printf("SAT in view: %d\n SATs",
        data->num_sat);
}
