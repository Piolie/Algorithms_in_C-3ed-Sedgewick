/* ---------------------------------------------------------------------
                             EXERCISE 5.83
------------------------------------------------------------------------
Give a nonrecursive implementation of postorder traversal.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Same as E05.82, but the line that pushes the node goes first.
--------------------------------------------------------------------- */

// #define DEBUG_E05_83

#ifdef DEBUG_E05_83
#include "P05_tree_ADT.c"
#include <stdio.h>
#endif // #ifdef DEBUG_E05_83

void traverse(link h, void (*visit)(link)) {
  STACKinit(MAX);
  STACKpush(h);
  while (!STACKempty()) {
    h = STACKpop();
    if (next_l(h) == NULL && next_r(h) == NULL)
      (*visit)(h);
    else {
      STACKpush(new_tree(get_item(h)));
      if (next_r(h) != NULL)
        STACKpush(next_r(h));
      if (next_l(h) != NULL)
        STACKpush(next_l(h));
    }
  }
}

#ifdef DEBUG_E05_83
int main(void) {
  printf("Checking E05.79 (i):\n");
  link D = new_tree('D');
  link B = add_l(D, 'B');
  link F = add_r(D, 'F');
  link A = add_l(B, 'A');
  link C = add_r(B, 'C');
  link E = add_l(F, 'E');
  link G = add_r(F, 'G');
  printf("postorder (recursive): ");
  traverse_postorder(D, print_node);
  printf("\npostorder (iterative): ");
  traverse(D, print_node);
  printf("\n");

  printf("\nChecking E05.79 (ii):\n");
  C = new_tree('C');
  B = add_l(C, 'B');
  A = add_l(B, 'A');
  D = add_r(C, 'D');
  E = add_r(D, 'E');
  printf("postorder (recursive): ");
  traverse_postorder(C, print_node);
  printf("\npostorder (iterative): ");
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
  printf("postorder (recursive): ");
  traverse_postorder(E, print_node);
  printf("\npostorder (iterative): ");
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
  printf("postorder (recursive): ");
  traverse_postorder(E, print_node);
  printf("\npostorder (iterative): ");
  traverse(E, print_node);
  printf("\n");

  (void)A;
  (void)G;
  (void)I;
}
#endif // #ifdef DEBUG_E05_83

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.83.exe
Checking E05.79 (i):
postorder (recursive): A - C - B - E - G - F - D -
postorder (iterative): A - C - B - E - G - F - D -

Checking E05.79 (ii):
postorder (recursive): A - B - E - D - C -
postorder (iterative): A - B - E - D - C -

Checking E05.79 (iii):
postorder (recursive): A - B - D - C - G - F - I - H - E -
postorder (iterative): A - B - D - C - G - F - I - H - E -

Checking E05.80:
postorder (recursive): A - C - B - D - G - F - H - E -
postorder (iterative): A - C - B - D - G - F - H - E -
--------------------------------------------------------------------- */
