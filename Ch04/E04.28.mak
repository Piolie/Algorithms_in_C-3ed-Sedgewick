CC = gcc
CFLAGS = -g -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes
TARGET = E04.28.exe
OBJ = E04.28_P04.07.o E04.28_P04.08.o
DEPS = E04.28_P04.06.h E04.28_P04.08.c

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
