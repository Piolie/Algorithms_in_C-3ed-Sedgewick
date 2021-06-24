CC = gcc
CFLAGS = -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes

all: P03.13.o list.o
	$(CC) -o P03.13_list_allocation_for_the_Josephus_problem.exe P03.13.o list.o

P03.13.o: P03.13_list_allocation_for_the_Josephus_problem.c list.h
	$(CC) $(CFLAGS) -o P03.13.o -c P03.13_list_allocation_for_the_Josephus_problem.c

list.o: P03.14_implementation_of_list-processing_interface.c list.h
	$(CC) $(CFLAGS) -o list.o -c P03.14_implementation_of_list-processing_interface.c
