CC = gcc
CFLAGS = -g -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes
TARGET = E03.10.exe
OBJ = E03.10.o P03.04_point_data_type_implementation.o E03.10_triangle_implementation.o
DEPS = Point.h P03.04_point_data_type_implementation.c E03.10_triangle.h

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
