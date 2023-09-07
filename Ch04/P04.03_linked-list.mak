CC = gcc
CFLAGS = -g -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes
TARGET = P04.03.exe
OBJ = P04.03_infix-to-postfix_conversion.o P04.05_linked-list_implementation_of_a_pushdown_stack.o
DEPS = Item_char.h STACK.h P04.05_linked-list_implementation_of_a_pushdown_stack.c

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
