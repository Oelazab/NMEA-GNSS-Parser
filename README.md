# NMEA GNSS Parser

Parsing NMEA sentences from GNSS receivers.

"GP"  Global Positioning System (GPS) (Talker Identifier)\
"GGA" Global Positioning System Fix Data. (Sentence Identifier)

## Sentence Form
```
       1         2       3 4        5 6 7  8   9  10 11 12 13  14   15
       |         |       | |        | | |  |   |   | |   | |   |    |
$GPGGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx*hh
```
1) Time (UTC)
2) Latitude
3) N or S (North or South)
4) Longitude
5) E or W (East or West)
6) GPS Quality Indicator,\
    0 - fix not available,\
    1 - GPS fix,\
    2 - Differential GPS fix
7) Number of satellites in view, 00 - 12
8) Horizontal Dilution of precision
9) Antenna Altitude above/below mean-sea-level (geoid) 
10) Units of antenna altitude, meters
11) Geoidal separation, the difference between the WGS-84 earth\
    ellipsoid and mean-sea-level (geoid), "-" means mean-sea-level below ellipsoid
12) Units of geoidal separation, meters
13) Age of differential GPS data, time in seconds since last SC104\
    type 1 or 9 update, null field when DGPS is not used
14) Differential reference station ID, 0000-1023
15) Checksum


## Features
- Supports NMEA `$GPGGA` sentences
- Modular design for easy extension
