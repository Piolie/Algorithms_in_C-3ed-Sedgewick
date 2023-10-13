/* ---------------------------------------------------------------------
                             EXERCISE 5.86
------------------------------------------------------------------------
Write a program that counts the leaves in a binary tree.
--------------------------------------------------------------------- */

#include "P05_tree_ADT.c"

int count_leaves(link tree) {
  if (tree == NULL)
    return 0;
  if (next_l(tree) == NULL && next_r(tree) == NULL)
    return 1;
  return count_leaves(next_l(tree)) + count_leaves(next_r(tree));
}

int main(void) {
  link D = new_tree('D');
  link B = add_l(D, 'B');
  link F = add_r(D, 'F');
  link A = add_l(B, 'A');
  link C = add_r(B, 'C');
  link E = add_l(F, 'E');
  link G = add_r(F, 'G');
  printf("Leaves in the tree of E05.79 (i): %d\n", count_leaves(D));

  C = new_tree('C');
  B = add_l(C, 'B');
  A = add_l(B, 'A');
  D = add_r(C, 'D');
  E = add_r(D, 'E');
  printf("Leaves in the tree of E05.79 (ii): %d\n", count_leaves(C));

  E = new_tree('E');
  C = add_l(E, 'C');
  B = add_l(C, 'B');
  A = add_l(B, 'A');
  D = add_r(C, 'D');
  link H = add_r(E, 'H');
  link I = add_r(H, 'I');
  F = add_l(H, 'F');
  G = add_r(F, 'G');
  printf("Leaves in the tree of E05.79 (iii): %d\n", count_leaves(E));

  E = new_tree('E');
  D = add_l(E, 'D');
  B = add_l(D, 'B');
  A = add_l(B, 'A');
  C = add_r(B, 'C');
  H = add_r(E, 'H');
  F = add_l(H, 'F');
  G = add_r(F, 'G');
  printf("Leaves in the tree of figure 5.26: %d\n", count_leaves(E));
  (void)A;
  (void)G;
  (void)I;
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.86.exe
Leaves in the tree of E05.79 (i): 4
Leaves in the tree of E05.79 (ii): 2
Leaves in the tree of E05.79 (iii): 3
Leaves in the tree of figure 5.26: 3
--------------------------------------------------------------------- */
