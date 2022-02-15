CC = gcc
CFLAGS = -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes

all: P03.13.o E03.52.o
	$(CC) -o E03.52.exe P03.13.o E03.52.o

P03.13.o: P03.13_list_allocation_for_the_Josephus_problem.c list.h
	$(CC) $(CFLAGS) -o P03.13.o -c P03.13_list_allocation_for_the_Josephus_problem.c

E03.52.o: E03.52.c list.h
	$(CC) $(CFLAGS) -o E03.52.o -c E03.52.c
