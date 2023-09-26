/* ---------------------------------------------------------------------
                             EXERCISE 5.15
------------------------------------------------------------------------
Write a recursive program for reversing the order of the nodes in a
linked list (see Program 3.7). Hint: Use a global variable.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
P03.07 is the Coin-flipping simulation. The exercise probably refers to
P03.10 (List reversal). I liked the step-by-step explanation at [How to
recursively reverse a linked
list](https://medium.com/the-core/how-to-recursively-reverse-a-linked-list-9990d59fc13f)
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;

struct node {
  int item;
  link next;
};

link reverse(link x) {
  if (x == NULL || x->next == NULL)
    return x;

  link t = reverse(x->next);
  x->next->next = x;
  x->next = NULL;

  return t;
}

void print_list(link x) {
  for (link t = x; t != NULL; t = t->next)
    printf("%3d", t->item);
  printf("\n");
}

int main(int argc, char *argv[]) {
  (void)argc;
  int N = atoi(argv[1]);
  link t = malloc(sizeof *t);
  t->item = 1;
  link x = t;
  for (int i = 2; i <= N; i++) {
    x->next = malloc(sizeof *x);
    x = x->next;
    x->item = i;
  }
  x->next = NULL;

  printf("Before:\n");
  print_list(t);
  t = reverse(t);
  printf("After:\n");
  print_list(t);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.15.exe 10
Before:
  1  2  3  4  5  6  7  8  9 10
After:
 10  9  8  7  6  5  4  3  2  1

./E05.15.exe 20
Before:
  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
After:
 20 19 18 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1
--------------------------------------------------------------------- */
