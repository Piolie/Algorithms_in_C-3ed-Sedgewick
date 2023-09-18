/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.19
                Queue client program (queue simulation)
------------------------------------------------------------------------
The availability of object handles makes it possible to build compound
data structures with ADT objects, such as the array of queues in this
sample client program, which simulates a situation where customers
waiting for service are assigned at random to one of M service queues.
--------------------------------------------------------------------- */

#include "Item.h"
#include "QUEUE.h"
#include <stdio.h>
#include <stdlib.h>
#define M 10

int main(int argc, char *argv[]) {
  (void)argc;
  int i, j, N = atoi(argv[1]);
  Q queues[M];
  for (i = 0; i < M; i++)
    queues[i] = QUEUEinit(N);
  for (i = 0; i < N; i++)
    QUEUEput(queues[rand() % M], i);
  for (i = 0; i < M; i++, printf("\n"))
    for (j = 0; !QUEUEempty(queues[i]); j++)
      printf("%3d ", QUEUEget(queues[i]));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./P04.19.exe 84
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
