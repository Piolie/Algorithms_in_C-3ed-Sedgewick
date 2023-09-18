CC = gcc
CFLAGS = -g -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes
TARGET = P04.19.exe
OBJ = P04.19_queue_client_program.o P04.20_linked-list_implementation_of_first-class_queue.o
DEPS = Item.h QUEUE.h

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
