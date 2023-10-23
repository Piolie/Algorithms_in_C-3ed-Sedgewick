CC = gcc
CFLAGS = -g -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes
TARGET = E06.51.exe
OBJ = P06.06_sort_driver_for_arrays.o E06.51.o P06.08_implementation_of_array_data_type.o P06.03_insertion_sort.o
DEPS = Item.h Array.h

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
