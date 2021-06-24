CC = gcc
CFLAGS = -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes

all: P03.08.o point.o
	$(CC) -o P03.08_closest-point_computation.exe P03.08.o point.o

P03.08.o: P03.08_closest-point_computation.c Point.h
	$(CC) $(CFLAGS) -o P03.08.o -c P03.08_closest-point_computation.c

point.o: P03.04_point_data_type_implementation.c Point.h
	$(CC) $(CFLAGS) -o point.o -c P03.04_point_data_type_implementation.c
