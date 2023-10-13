/* ---------------------------------------------------------------------
                             EXERCISE 5.88
------------------------------------------------------------------------
Write a recursive program that computes the internal path length of a
binary tree, using Definition 5.6.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Definition 5.6
The level of a node in a tree is one higher than the level of its parent
(with the root at level 0). The height of a tree is the maximum of the
levels of the tree's nodes. The path length of a tree is the sum of the
levels of all the tree's nodes. The internal path length of a binary
tree is the sum of the levels of all the tree's internal nodes. The
external path length of a binary tree is the sum of the levels of all
the tree's external nodes.
--------------------------------------------------------------------- */

#include "P05_tree_ADT.c"

int internal_path(link tree) {
  static int level = -1;
  level++;
  if (tree == NULL)
    return 0 * level--;

  int tmp = internal_path(next_l(tree)) + internal_path(next_r(tree));
  return level-- + tmp;
}

int main(void) {
  link D = new_tree('D');
  link B = add_l(D, 'B');
  link F = add_r(D, 'F');
  link A = add_l(B, 'A');
  link C = add_r(B, 'C');
  link E = add_l(F, 'E');
  link G = add_r(F, 'G');
  printf("Internal path length of the tree of E05.79 (i): %d\n",
         internal_path(D));

  C = new_tree('C');
  B = add_l(C, 'B');
  A = add_l(B, 'A');
  D = add_r(C, 'D');
  E = add_r(D, 'E');
  printf("Internal path length of the tree of E05.79 (ii): %d\n",
         internal_path(C));

  E = new_tree('E');
  C = add_l(E, 'C');
  B = add_l(C, 'B');
  A = add_l(B, 'A');
  D = add_r(C, 'D');
  link H = add_r(E, 'H');
  link I = add_r(H, 'I');
  F = add_l(H, 'F');
  G = add_r(F, 'G');
  printf("Internal path length of the tree of E05.79 (iii): %d\n",
         internal_path(E));

  E = new_tree('E');
  D = add_l(E, 'D');
  B = add_l(D, 'B');
  A = add_l(B, 'A');
  C = add_r(B, 'C');
  H = add_r(E, 'H');
  F = add_l(H, 'F');
  G = add_r(F, 'G');
  printf("Internal path of the tree of figure 5.26: %d\n", internal_path(E));
  (void)A;
  (void)G;
  (void)I;
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.88.exe
Internal path length of the tree of E05.79 (i): 10
Internal path length of the tree of E05.79 (ii): 6
Internal path length of the tree of E05.79 (iii): 16
Internal path of the tree of figure 5.26: 15
--------------------------------------------------------------------- */
