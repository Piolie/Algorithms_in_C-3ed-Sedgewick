/* ---------------------------------------------------------------------
                             EXERCISE 5.87
------------------------------------------------------------------------
Write a program that counts the number of nodes in a binary tree that
have one external and one internal child.
--------------------------------------------------------------------- */

#include "P05_tree_ADT.c"

int count_mixed(link tree) {
  if (tree == NULL)
    return 0;
  if ((next_l(tree) == NULL) != (next_r(tree) == NULL))
    return 1 + count_mixed(next_l(tree)) + count_mixed(next_r(tree));
  else
    return 0 + count_mixed(next_l(tree)) + count_mixed(next_r(tree));
}

int main(void) {
  link D = new_tree('D');
  link B = add_l(D, 'B');
  link F = add_r(D, 'F');
  link A = add_l(B, 'A');
  link C = add_r(B, 'C');
  link E = add_l(F, 'E');
  link G = add_r(F, 'G');
  printf("Mixed nodes in the tree of E05.79 (i): %d\n", count_mixed(D));

  C = new_tree('C');
  B = add_l(C, 'B');
  A = add_l(B, 'A');
  D = add_r(C, 'D');
  E = add_r(D, 'E');
  printf("Mixed nodes in the tree of E05.79 (ii): %d\n", count_mixed(C));

  E = new_tree('E');
  C = add_l(E, 'C');
  B = add_l(C, 'B');
  A = add_l(B, 'A');
  D = add_r(C, 'D');
  link H = add_r(E, 'H');
  link I = add_r(H, 'I');
  F = add_l(H, 'F');
  G = add_r(F, 'G');
  printf("Mixed nodes in the tree of E05.79 (iii): %d\n", count_mixed(E));

  E = new_tree('E');
  D = add_l(E, 'D');
  B = add_l(D, 'B');
  A = add_l(B, 'A');
  C = add_r(B, 'C');
  H = add_r(E, 'H');
  F = add_l(H, 'F');
  G = add_r(F, 'G');
  printf("Mixed nodes in the tree of figure 5.26: %d\n", count_mixed(E));
  (void)A;
  (void)G;
  (void)I;
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.87.exe
Mixed nodes in the tree of E05.79 (i): 0
Mixed nodes in the tree of E05.79 (ii): 2
Mixed nodes in the tree of E05.79 (iii): 2
Mixed nodes in the tree of figure 5.26: 3
--------------------------------------------------------------------- */
