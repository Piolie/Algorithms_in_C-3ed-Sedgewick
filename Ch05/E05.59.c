/* ---------------------------------------------------------------------
                             EXERCISE 5.59
------------------------------------------------------------------------
Assume that trees contain items for which eq is defined. Write a
recursive program that deletes all the leaves in a binary tree with
items equal to a given item (see Program 5.5).
--------------------------------------------------------------------- */

typedef struct node *link;
struct node {
  Item item;
  link l, r;
};

link delete_leaves(link root, Item item) {
  if (root == NULL)
    return NULL;

  if ((root->l == NULL) && (root->r == NULL) && (eq(root->item, item)))
    return NULL;

  root->l = delete_leaves(root->l, item);
  root->r = delete_leaves(root->r, item);
  return root;
}
