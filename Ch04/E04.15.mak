CC = gcc
CFLAGS = -g -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes
TARGET = E04.15.exe
OBJ = E04.15.o P04.05_linked-list_implementation_of_a_pushdown_stack.o
DEPS = Item_string.h STACK.h P04.05_linked-list_implementation_of_a_pushdown_stack.c

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
