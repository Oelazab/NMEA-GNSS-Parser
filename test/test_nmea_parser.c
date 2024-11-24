#include <stdio.h>
#include "nmea_parser.h"

void run_tests() {
    NMEAData data;
    const char *test_sentence = "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";

    if (parse_nmea_sentence(test_sentence, &data)) {
        printf("Test Passed: Parsed successfully.\n");
    } else {
        printf("Test Failed: Parsing failed.\n");
    }
}

int main() {
    run_tests();
    return 0;
}
