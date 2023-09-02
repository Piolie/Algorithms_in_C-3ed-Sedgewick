CC = gcc
CFLAGS = -g -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes
TARGET = P03.13_list_allocation_for_the_Josephus_problem.exe
OBJ = P03.13_list_allocation_for_the_Josephus_problem.o P03.14_implementation_of_list-processing_interface.o
DEPS = list.h P03.13_list_allocation_for_the_Josephus_problem.c P03.14_implementation_of_list-processing_interface.c

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
