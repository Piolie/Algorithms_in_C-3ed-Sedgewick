CC = gcc
CFLAGS = -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes

all: E03.08.o point.o
	$(CC) -o E03.08.exe E03.08.o point.o

E03.08.o: E03.08.c E03.08_Point.h
	$(CC) $(CFLAGS) -c E03.08.c

point.o: E03.08_point_implementation.c E03.08_Point.h
	$(CC) $(CFLAGS) -o point.o -c E03.08_point_implementation.c
