CC = gcc
CFLAGS = -g -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes
TARGET = E03.51.exe
OBJ = P03.13_list_allocation_for_the_Josephus_problem.o E03.50.o
DEPS = list.h P03.13_list_allocation_for_the_Josephus_problem.c

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
