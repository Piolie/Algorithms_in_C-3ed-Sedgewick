/* ---------------------------------------------------------------------
                             EXERCISE 4.52
------------------------------------------------------------------------
Do Exercises 4.48 and 4.49 for the FIFO queue ADT.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This exercise is then:
Modify the standard array-based FIFO queue implementation in Section 4.4
(Program 4.11) to disallow duplicates with an ignore-the-new-item
policy. Use a brute-force approach that involves scanning through the
whole stack.

The heavy lifting was already done in E04.48.
--------------------------------------------------------------------- */

// #define DEBUG_E04_52_E04_48

#include "Item.h"
#include "QUEUE.h"
#include <stdlib.h>

static Item *q;
static int N, head, tail;

void QUEUEinit(int maxN) {
  q = malloc((maxN + 1) * sizeof(Item));
  N = maxN + 1;
  head = N;
  tail = 0;
}

int QUEUEempty(void) { return head % N == tail; }

void QUEUEput(Item item) {
  for (int i = head % N; i != tail; i = (i + 1) % N)
    if (eq(q[i], item))
      return;
  q[tail++] = item;
  tail = tail % N;
}

Item QUEUEget(void) {
  head = head % N;
  return q[head++];
}

#ifdef DEBUG_E04_52_E04_48
#include <stdio.h>

void QUEUEdump(void) {
  for (int i = head % N; i != tail; i = (i + 1) % N) {
    ITEMshow(q[i]);
    printf(" ");
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  (void)argc;
  char *a = argv[2];
  QUEUEinit(atoi(argv[1]));
  for (char c = *a; c; c = *++a) {
    if (c >= 'A' && c <= 'Z') {
      printf("%c       ", c);
      QUEUEput(c);
      QUEUEdump();
    } else if (c == '*') {
      printf("*   %c", QUEUEget());
      printf("   ");
      QUEUEdump();
    }
  }
}
#endif // #ifdef DEBUG_E04_52_E04_48

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
Reproducing figure 4.10:
./E04.52_E04.48.exe 10 "F I R S * T * I N * * * F I * R S * * * T * O U T * * *"
F       F
I       F I
R       F I R
S       F I R S
*   F   I R S
T       I R S T
*   I   R S T
I       R S T I
N       R S T I N
*   R   S T I N
*   S   T I N
*   T   I N
F       I N F
I       I N F
*   I   N F
R       N F R
S       N F R S
*   N   F R S
*   F   R S
*   R   S
T       S T
*   S   T
O       T O
U       T O U
T       T O U
*   T   O U
*   O   U
*   U
--------------------------------------------------------------------- */
