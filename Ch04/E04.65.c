/* ---------------------------------------------------------------------
                             EXERCISE 4.65
------------------------------------------------------------------------
Develop an implementation of the FIFO queue first-class ADT given in
the text (Program 4.18) that uses an array as the underlying data
structure.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I'll be adapting heavily from P04.11 (FIFO queue array implementation).
Basically, we have to define the struct and then dereference the fields
of the queue variable every single time.

For testing purposes, I'll compile P04.19 against this implementation.
--------------------------------------------------------------------- */

#include "Item.h"
#include "QUEUE.h"
#include <stdio.h>
#include <stdlib.h>

struct queue {
  Item *q;
  int N;
  int head;
  int tail;
};

void QUEUEdump(Q queue) {
  for (int i = queue->head % queue->N; i != queue->tail; i = (i + 1) % queue->N) {
    ITEMshow(queue->q[i]);
    printf(" ");
  }
  printf("\n");
}

Q QUEUEinit(int maxN) {
  Q queue = malloc(sizeof(*queue));
  queue->q = malloc((maxN + 1) * sizeof(Item));
  queue->N = maxN + 1;
  queue->head = queue->N;
  queue->tail = 0;
  return queue;
}

int QUEUEempty(Q queue) { return queue->head % queue->N == queue->tail; }

void QUEUEput(Q queue, Item item) {
  queue->q[queue->tail++] = item;
  queue->tail = queue->tail % queue->N;
}

Item QUEUEget(Q queue) {
  queue->head = queue->head % queue->N;
  return queue->q[queue->head++];
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E04.65.exe 84
  3  62  66  72  74  75
  0  12  14  15  20  26  32  41  46  47  57  77
  8  17  22  24  25  35  42  52  63  67
 23  40  43  44  48  56  78  81
  2   5   9  21  39  45  51  68  82  83
 10  11  16  29  38  61  71
 19  27  31  60  65  70  76
  1  13  18  30  36  50  53  54
  6   7  28  33  49  59  64  69  79
  4  34  37  55  58  73  80
--------------------------------------------------------------------- */
