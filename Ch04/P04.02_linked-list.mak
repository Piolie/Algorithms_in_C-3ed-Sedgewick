CC = gcc
CFLAGS = -g -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes
TARGET = P04.02.exe
OBJ = P04.02_postfix-expression_evaluation.o P04.05_linked-list_implementation_of_a_pushdown_stack.o
DEPS = Item.h STACK.h

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
