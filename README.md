# NMEA GNSS Parser

A lightweight and efficient C library for parsing NMEA sentences from GNSS receivers.
"$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47"

## Features
- Supports NMEA `$GPGGA` sentences.
- Modular design for easy extension.
- Lightweight and easy to integrate.

## Directory Structure
nmea-gnss-parser/
├── src/
│   ├── nmea_parser.c       # Core source file for parsing NMEA sentences
│   ├── main.c              # Example usage
│   └── Makefile            # Build instructions for the project
|
├── include/
│   ├── nmea_parser.h       # Header file for NMEA parser
│   ├── utils.h             # Header file for utility functions
|
├── tests/
│   ├── test_nmea_parser.c  # Unit tests for the parser
│   └── Makefile            # Makefile for running tests
|
├── LICENSE                 # License file (MIT License)
└── README.md               # Main project description
