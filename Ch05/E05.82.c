/* ---------------------------------------------------------------------
                             EXERCISE 5.82
------------------------------------------------------------------------
Give a nonrecursive implementation of inorder traversal.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
In this ADT, a node is simply a tree with null links. So, in order to
push a node to the stack, we call new_tree() with the desired value.
--------------------------------------------------------------------- */

// #define DEBUG_E05_82

#ifdef DEBUG_E05_82
#include "P05_tree_ADT.c"
#include <stdio.h>
#endif // #ifdef DEBUG_E05_82

void traverse(link h, void (*visit)(link)) {
  STACKinit(MAX);
  STACKpush(h);
  while (!STACKempty()) {
    h = STACKpop();
    if (next_l(h) == NULL && next_r(h) == NULL)
      (*visit)(h);
    else {
      if (next_r(h) != NULL)
        STACKpush(next_r(h));
      STACKpush(new_tree(h->item));
      if (next_l(h) != NULL)
        STACKpush(next_l(h));
    }
  }
}

#ifdef DEBUG_E05_82
int main(void) {
  printf("Checking E05.79 (i):\n");
  link D = new_tree('D');
  link B = add_l(D, 'B');
  link F = add_r(D, 'F');
  link A = add_l(B, 'A');
  link C = add_r(B, 'C');
  link E = add_l(F, 'E');
  link G = add_r(F, 'G');
  printf("inorder (recursive): ");
  traverse_inorder(D, print_node);
  printf("\ninorder (iterative): ");
  traverse(D, print_node);
  printf("\n");

  printf("\nChecking E05.79 (ii):\n");
  C = new_tree('C');
  B = add_l(C, 'B');
  A = add_l(B, 'A');
  D = add_r(C, 'D');
  E = add_r(D, 'E');
  printf("inorder (recursive): ");
  traverse_inorder(C, print_node);
  printf("\ninorder (iterative): ");
  traverse(C, print_node);
  printf("\n");

  printf("\nChecking E05.79 (iii):\n");
  E = new_tree('E');
  C = add_l(E, 'C');
  B = add_l(C, 'B');
  A = add_l(B, 'A');
  D = add_r(C, 'D');
  link H = add_r(E, 'H');
  link I = add_r(H, 'I');
  F = add_l(H, 'F');
  G = add_r(F, 'G');
  printf("inorder (recursive): ");
  traverse_inorder(E, print_node);
  printf("\ninorder (iterative): ");
  traverse(E, print_node);
  printf("\n");

  printf("\nChecking E05.80:\n");
  E = new_tree('E');
  D = add_l(E, 'D');
  B = add_l(D, 'B');
  A = add_l(B, 'A');
  C = add_r(B, 'C');
  H = add_r(E, 'H');
  F = add_l(H, 'F');
  G = add_r(F, 'G');
  printf("inorder (recursive): ");
  traverse_inorder(E, print_node);
  printf("\ninorder (iterative): ");
  traverse(E, print_node);
  printf("\n");
}
#endif // #ifdef DEBUG_E05_82

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.82.exe
Checking E05.79 (i):
inorder (recursive): A - B - C - D - E - F - G -
inorder (iterative): A - B - C - D - E - F - G -

Checking E05.79 (ii):
inorder (recursive): A - B - C - D - E -
inorder (iterative): A - B - C - D - E -

Checking E05.79 (iii):
inorder (recursive): A - B - C - D - E - F - G - H - I -
inorder (iterative): A - B - C - D - E - F - G - H - I -

Checking E05.80:
inorder (recursive): A - B - C - D - E - F - G - H -
inorder (iterative): A - B - C - D - E - F - G - H -
--------------------------------------------------------------------- */