CC = gcc
CFLAGS = -g -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes
TARGET = E03.22.exe
OBJ = E03.22.o P03.04_point_data_type_implementation.o
DEPS = Point.h

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
