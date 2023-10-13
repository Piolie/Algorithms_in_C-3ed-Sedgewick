/* ---------------------------------------------------------------------
                             EXERCISE 5.89
------------------------------------------------------------------------
Determine the number of function calls made by your program when it
is computing the internal path length of a binary tree. Prove your
answer by induction.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The program makes 2N + 1 calls, where N is the number of internal nodes.

The proof is analogous to the one for Property 5.5:
If N = 0, the function is called once, so the property holds for N = 0.
For N > 0, any binary tree with N internal nodes has k internal nodes in
its left subtree and N - 1 - k internal nodes in its right subtree for
some k between 0 and N - 1, since the root is an internal node. By the
inductive hypothesis, the function is called 2k + 1 times for the left
subtree, 2(N - 1 - k) + 1 times for the right subtree, with an extra
call for the root. Adding these three we have:
  C(N) = [2k + 1] + [2(N - 1 - k) + 1] + [1]
       = 2k + 1 + 2N - 2 - 2k + 1 + 1
       = 1 + 2N - 2 + 1 + 1
       = 2N + 1.
--------------------------------------------------------------------- */

#include "P05_tree_ADT.c"

int internal_path(link tree, int *calls) {
  static int level = -1;
  (*calls)++;
  level++;
  if (tree == NULL)
    return 0 * level--;

  int tmp =
      internal_path(next_l(tree), calls) + internal_path(next_r(tree), calls);
  return level-- + tmp;
}

int count_calls(link tree) {
  int calls = 0;
  internal_path(tree, &calls);
  return calls;
}

int main(void) {
  link D = new_tree('D');
  link B = add_l(D, 'B');
  link F = add_r(D, 'F');
  link A = add_l(B, 'A');
  link C = add_r(B, 'C');
  link E = add_l(F, 'E');
  link G = add_r(F, 'G');
  printf("Recursive calls for the tree of E05.79 (i): %d\n", count_calls(D));

  C = new_tree('C');
  B = add_l(C, 'B');
  A = add_l(B, 'A');
  D = add_r(C, 'D');
  E = add_r(D, 'E');
  printf("Recursive calls for the tree of E05.79 (ii): %d\n", count_calls(C));

  E = new_tree('E');
  C = add_l(E, 'C');
  B = add_l(C, 'B');
  A = add_l(B, 'A');
  D = add_r(C, 'D');
  link H = add_r(E, 'H');
  link I = add_r(H, 'I');
  F = add_l(H, 'F');
  G = add_r(F, 'G');
  printf("Recursive calls for the tree of E05.79 (iii): %d\n", count_calls(E));

  E = new_tree('E');
  D = add_l(E, 'D');
  B = add_l(D, 'B');
  A = add_l(B, 'A');
  C = add_r(B, 'C');
  H = add_r(E, 'H');
  F = add_l(H, 'F');
  G = add_r(F, 'G');
  printf("Recursive calls for the tree of figure 5.26: %d\n", count_calls(E));
  (void)A;
  (void)G;
  (void)I;
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.89.exe
Recursive calls for the tree of E05.79 (i): 15
Recursive calls for the tree of E05.79 (ii): 11
Recursive calls for the tree of E05.79 (iii): 19
Recursive calls for the tree of figure 5.26: 17
--------------------------------------------------------------------- */
