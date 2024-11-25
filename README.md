# NMEA GNSS Parser

Parsing NMEA sentences from GNSS receivers
```
"$--GGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx*hh"
"$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47"
  GP -> Global Positioning System (GPS) (Talker Identifier)
  GGA -> Global Positioning System Fix Data. (Sentence Identifier)
```
## Features
- Supports NMEA `$GPGGA` sentences
- Modular design for easy extension
