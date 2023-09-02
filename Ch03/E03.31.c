/* ---------------------------------------------------------------------
                             EXERCISE 3.31
------------------------------------------------------------------------
Use Program 3.9 to plot the Josephus function versus N for M = 10 and N
from 2 to 1000.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#define M 10

typedef struct node *link;

struct node {
  int item;
  link next;
};

void print_Josephus(int result, int N) {
  int scale = 10; // to scale the number of stars printed
  printf("%3d ", N);
  for (int i = 0; i < result / scale; i++)
    printf("*");
  printf("\n");
}

int main(void) {
  for (int N = 2; N <= 1000; N++) {
    int i;
    link t = malloc(sizeof *t), x = t;
    t->item = 1;
    t->next = t;
    for (i = 2; i <= N; i++) {
      x = (x->next = malloc(sizeof *x));
      x->item = i;
      x->next = t;
    }
    while (x != x->next) {
      for (i = 1; i < M; i++)
        x = x->next;
      x->next = x->next->next;
    }
    print_Josephus(x->item, N);
  }
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
(just a sample)

 79
 80 *
 81 **
 82 ***
 83 ****
 84 *****
 85 ******
 86 *******
 87 ********
 88
 89 *
 90 **
 91 ***
 92 ****
 93 *****
 94 ******
 95 *******
 96 ********
 97 *********
 98
 99 *
100 **
101 ***
102 ****
103 *****
104 ******
105 *******
106 ********
107 *********
108 **********
109
--------------------------------------------------------------------- */
