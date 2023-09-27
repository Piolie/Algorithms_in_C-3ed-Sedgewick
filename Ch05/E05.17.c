/* ---------------------------------------------------------------------
                             EXERCISE 5.17
------------------------------------------------------------------------
Write a recursive program that finds the maximum element in a linked
list.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;

struct node {
  int item;
  link next;
};

int max(link x) {
  if (x->next == NULL)
    return x->item;

  int m = max(x->next);

  if (x->item >= m)
    return x->item;

  return m;
}

void print_list(link x) {
  for (link t = x; t != NULL; t = t->next)
    printf("%d ", t->item);
  printf("\n");
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  link t = malloc(sizeof *t);
  t->item = rand();
  link x = t;
  for (int i = 2; i <= N; i++) {
    x->next = malloc(sizeof *x);
    x = x->next;
    x->item = rand();
  }
  x->next = NULL;

  print_list(t);
  printf("Max = %d\n", max(t));
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.17.exe 5
41 18467 6334 26500 19169
Max = 26500

./E05.17.exe 10
41 18467 6334 26500 19169 15724 11478 29358 26962 24464
Max = 29358

./E05.17.exe 15
41 18467 6334 26500 19169 15724 11478 29358 26962 24464 5705 28145 23281 16827 9961
Max = 29358
--------------------------------------------------------------------- */
