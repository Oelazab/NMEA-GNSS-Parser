CC = gcc
CFLAGS = -I../include -Wall -Wextra -g
TARGET = test_parser

SRC = test_nmea_parser.c ../src/nmea_parser.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
