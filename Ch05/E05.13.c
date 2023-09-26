/* ---------------------------------------------------------------------
                             EXERCISE 5.13
------------------------------------------------------------------------
Write a recursive program for solving the Josephus problem (see
Section 3.3).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This is basically P03.13 (List allocation for the Josephus problem) with
the added solve_josephus recursive function.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;

struct node {
  int item;
  link next;
};

int solve_josephus(link x, int M) {
  if (x == x->next)
    return x->item;

  for (int i = 1; i < M; i++)
    x = x->next;
  x->next = x->next->next;

  return solve_josephus(x, M);
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);
  link t = malloc(sizeof *t);
  t->item = 1;
  t->next = t;
  link x = t;
  for (int i = 2; i <= N; i++) {
    x->next = malloc(sizeof *x);
    x = x->next;
    x->item = i;
  }
  x->next = t;

  printf("%d\n", solve_josephus(x, M));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.13.exe 1000 32
749
--------------------------------------------------------------------- */
