CC = gcc
CFLAGS = -I../include -Wall -Wextra -g
TARGET = nmea_parser

SRC = main.c nmea_parser.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
