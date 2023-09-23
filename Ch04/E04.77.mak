CC = gcc
CFLAGS = -g -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes
TARGET = E04.77.exe
OBJ = E04.77.o P04.04_array_implementation_of_a_pushdown_stack.c E04.76_implementation.o
DEPS = Item.h STACK.h POLY.h

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
