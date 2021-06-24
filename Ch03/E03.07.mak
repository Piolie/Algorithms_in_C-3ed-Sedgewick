CC = gcc
CFLAGS = -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes

all: E03.07.o point.o
	$(CC) -o E03.07.exe E03.07.o point.o

E03.07.o: E03.07.c Point.h
	$(CC) $(CFLAGS) -c E03.07.c

point.o: P03.04_point_data_type_implementation.c Point.h
	$(CC) $(CFLAGS) -o point.o -c P03.04_point_data_type_implementation.c

