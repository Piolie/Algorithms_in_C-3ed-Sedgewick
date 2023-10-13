/* ---------------------------------------------------------------------
                             EXERCISE 5.91
------------------------------------------------------------------------
Write a recursive program that deletes all the leaves with a given key
from a tournament (see Exercise 5.59).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I've adapted P05.18 (Quick tree-print function), P05.18 (Construction of
a tournament) and copied delete_leaves() from E05.59. However, I'm not
sure what should happen with the tournament once the leaves are deleted.
Should the new tournament be reshaped? As it is now, the solution is
easy enough to make me suspicious.
--------------------------------------------------------------------- */

#include "P05_tree_ADT.c"

void printnode(char c, int h) {
  int i;
  for (i = 0; i < h; i++)
    printf("  ");
  printf("%c\n", c);
}

void show(link x, int h) {
  if (x == NULL) {
    printnode('*', h);
    return;
  }
  show(next_r(x), h + 1);
  printnode(get_item(x), h);
  show(next_l(x), h + 1);
}

int eq(Item a, Item b) { return a == b; }

link NEW(Item item, link l, link r) {
  link x = malloc(sizeof *x);
  set_item(x, item);
  append_l(x, l);
  append_r(x, r);
  return x;
}

link max(Item a[], int l, int r) {
  int m = (l + r) / 2;
  Item u, v;
  link x = NEW(a[m], NULL, NULL);
  if (l == r)
    return x;
  append_l(x, max(a, l, m));
  append_r(x, max(a, m + 1, r));
  u = get_item(next_l(x));
  v = get_item(next_r(x));
  if (u > v)
    set_item(x, u);
  else
    set_item(x, v);
  return x;
}

link delete_leaves(link root, Item item) {
  if (root == NULL)
    return NULL;

  if ((next_l(root) == NULL) && (next_r(root) == NULL) &&
      (eq(get_item(root), item)))
    return NULL;

  append_l(root, delete_leaves(next_l(root), item));
  append_r(root, delete_leaves(next_r(root), item));
  return root;
}

int main(void) {
  int a[] = {'A', 'M', 'P', 'L', 'E', '\0'};
  link T = max(a, 0, 4);
  printf("Elements: ");
  for (int i = 0; a[i]; i++)
    printf("%c ", a[i]);
  printf("\n");
  printf("\nTournament:\n");
  show(T, 0);
  printf("\nAfter removing 'L' leaves:\n");
  T = delete_leaves(T, 'L');
  show(T, 0);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.91.exe
Elements: A M P L E

Tournament:
      *
    E
      *
  L
      *
    L
      *
P
      *
    P
      *
  P
        *
      M
        *
    M
        *
      A
        *

After removing 'L' leaves:
      *
    E
      *
  L
    *
P
      *
    P
      *
  P
        *
      M
        *
    M
        *
      A
        *
--------------------------------------------------------------------- */
