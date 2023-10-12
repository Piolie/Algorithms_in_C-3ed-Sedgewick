/* ---------------------------------------------------------------------
                             EXERCISE 5.84
------------------------------------------------------------------------
Write a program that takes as input the preorder and inorder traversals
of a binary tree, and produces as output the level-order traversal of
the tree.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Adapted from [How to find level order traversal from Preorder and
Inorder Traversal](https://stackoverflow.com/questions/55363157/).

The function recursively creates, for each node in the preorder
sequence, a new node and then appends its two subtrees that it creates
from the inorder sequence.

The function needs to keep an index on the preorder sequence. That index
has to persist between function calls and be reset between non-recursive
calls. To achieve that, I've used a helper function that initializes an
int and passes a pointer to the building function. This function then
operates on the pointed integer, but receives it reinitialized each time
the helper function is called. (build_tree() is in fact the helper
function.)
--------------------------------------------------------------------- */

#include "P05_tree_ADT.c"
#include <stdio.h>
#include <string.h>

link helper(char *pre, char *in, int l, int r, int *ixpre) {
  if (l > r)
    return NULL;

  int curr = pre[(*ixpre)++];
  link node = new_tree(curr);
  if (l == r)
    return node;

  int ixin = (int)(strchr(in, curr) - in);
  append_l(node, helper(pre, in, l, ixin - 1, ixpre));
  append_r(node, helper(pre, in, ixin + 1, r, ixpre));
  return node;
}

link build_tree(char *pre, char *in) { // helper function
  int ixpre = 0;
  link tree = helper(pre, in, 0, strlen(pre) - 1, &ixpre);
  return tree;
}

int main(void) {
  link tree;

  printf("Checking E05.79 (i):\n");
  tree = build_tree("DBACFEG", "ABCDEFG");
  printf("levelorder original: ");
  printf("D - B - F - A - C - E - G -\n");
  printf("levelorder computed: ");
  traverse_level(tree, print_node);
  printf("\n");

  printf("\nChecking E05.79 (ii):\n");
  tree = build_tree("CBADE", "ABCDE");
  printf("levelorder original: ");
  printf("C - B - D - A - E -\n");
  printf("levelorder computed: ");
  traverse_level(tree, print_node);
  printf("\n");

  printf("\nChecking E05.79 (iii):\n");
  tree = build_tree("ECBADHFGI", "ABCDEFGHI");
  printf("levelorder original: ");
  printf("E - C - H - B - D - F - I - A - G -\n");
  printf("levelorder computed: ");
  traverse_level(tree, print_node);
  printf("\n");

  printf("\nChecking E05.80:\n");
  tree = build_tree("EDBACHFG", "ABCDEFGH");
  printf("levelorder original: ");
  printf("E - D - H - B - F - A - C - G -\n");
  printf("levelorder computed: ");
  traverse_level(tree, print_node);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.84.exe
Checking E05.79 (i):
levelorder original: D - B - F - A - C - E - G -
levelorder computed: D - B - F - A - C - E - G -

Checking E05.79 (ii):
levelorder original: C - B - D - A - E -
levelorder computed: C - B - D - A - E -

Checking E05.79 (iii):
levelorder original: E - C - H - B - D - F - I - A - G -
levelorder computed: E - C - H - B - D - F - I - A - G -

Checking E05.80:
levelorder original: E - D - H - B - F - A - C - G -
levelorder computed: E - D - H - B - F - A - C - G -
--------------------------------------------------------------------- */
