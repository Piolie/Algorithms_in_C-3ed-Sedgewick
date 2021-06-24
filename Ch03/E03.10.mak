CC = gcc
CFLAGS = -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes

all: E03.10.o point.o triangle.o
	$(CC) -o E03.10.exe E03.10.o point.o triangle.o

E03.10.o: E03.10.c Point.h E03.10_triangle.h
	$(CC) $(CFLAGS) -c E03.10.c

point.o: P03.04_point_data_type_implementation.c Point.h
	$(CC) $(CFLAGS) -o point.o -c P03.04_point_data_type_implementation.c

triangle.o: E03.10_triangle_implementation.c Point.h E03.10_triangle.h
	$(CC) $(CFLAGS) -o triangle.o -c E03.10_triangle_implementation.c
