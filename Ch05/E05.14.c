/* ---------------------------------------------------------------------
                             EXERCISE 5.14
------------------------------------------------------------------------
Write a recursive program that deletes the final element of a linked
list.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;

struct node {
  int item;
  link next;
};

link delete_last(link x) {
  if (x->next == NULL) {
    free(x);
    return NULL;
  }

  x->next = delete_last(x->next);

  return x;
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
  delete_last(t);
  printf("After:\n");
  print_list(t);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.14.exe 10
Before:
1 2 3 4 5 6 7 8 9 10
After:
1 2 3 4 5 6 7 8 9

./E05.14.exe 20
Before:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
--------------------------------------------------------------------- */
