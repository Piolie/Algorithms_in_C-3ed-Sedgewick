/* ---------------------------------------------------------------------
                      Tree header & implementation
------------------------------------------------------------------------
This is an all-in-one library that I implemented in order to test the
solutions of the different exercises. It incorporates the stack and
queue implementations. The Item type for the queues has been changed to
link, since we want to put and get nodes, not items. The traverse
functions have also been included. Everything was slightly modified to
play nicely with each other. I use it by directly including this file,
not very ADT-like.
--------------------------------------------------------------------- */

// #define DEBUG_TREE_ADT

#include <stdlib.h>
#include <stdio.h>

typedef int Item;

typedef struct btree_node *link;
struct btree_node {
  Item item;
  link l;
  link r;
};

link new_tree(Item item) {
  link root = malloc(sizeof *root);
  root->item = item;
  root->l = NULL;
  root->r = NULL;
  return root;
}

Item get_item(link node) { return node->item; }

void set_item(link node, Item item) { node->item = item;}

link next_l(link node) { return node->l; }

link next_r(link node) { return node->r; }

link add_l(link tree, Item item) {
  link node = new_tree(item);
  tree->l = node;
  return node;
}

link add_r(link tree, Item item) {
  link node = new_tree(item);
  tree->r = node;
  return node;
}

link append_l(link tree, link lnode) {
  tree->l = lnode;
  return tree;
}

link append_r(link tree, link rnode) {
  tree->r = rnode;
  return tree;
}

/* ---------------------------------------------------------------------
                        Stack ADT implementation
--------------------------------------------------------------------- */

typedef struct STACKnode *qlink;
struct STACKnode {
  link item;
  qlink next;
};

static qlink shead;

qlink qNEW(link item, qlink next) {
  qlink x = malloc(sizeof *x);
  x->item = item;
  x->next = next;
  return x;
}

void STACKinit(int maxN) {
  (void)maxN;
  shead = NULL;
}

int STACKempty(void) { return shead == NULL; }

void STACKpush(link item) { shead = qNEW(item, shead); }

link STACKpop(void) {
  link item = shead->item;
  qlink t = shead->next;
  free(shead);
  shead = t;
  return item;
}

/* ---------------------------------------------------------------------
                        Queue ADT implementation
--------------------------------------------------------------------- */

static qlink qhead, qtail;

void QUEUEinit(int maxN) {
  (void)maxN;
  qhead = NULL;
}

int QUEUEempty(void) { return qhead == NULL; }

void QUEUEput(link item) {
  if (qhead == NULL) {
    qhead = (qtail = qNEW(item, qhead));
    return;
  }
  qtail->next = qNEW(item, qtail->next);
  qtail = qtail->next;
}

link QUEUEget(void) {
  link item = qhead->item;
  qlink t = qhead->next;
  free(qhead);
  qhead = t;
  return item;
}

/* ---------------------------------------------------------------------
                        Traverse/visit functions
--------------------------------------------------------------------- */

#define MAX 20

void traverse_preorder(link h, void (*visit)(link)) {
  if (h == NULL)
    return;
  (*visit)(h);
  traverse_preorder(h->l, visit);
  traverse_preorder(h->r, visit);
}

void traverse_inorder(link h, void (*visit)(link)) {
  if (h == NULL)
    return;
  traverse_inorder(h->l, visit);
  (*visit)(h);
  traverse_inorder(h->r, visit);
}

void traverse_postorder(link h, void (*visit)(link)) {
  if (h == NULL)
    return;
  traverse_postorder(h->l, visit);
  traverse_postorder(h->r, visit);
  (*visit)(h);
}

void traverse_level(link h, void (*visit)(link)) {
  QUEUEinit(MAX);
  QUEUEput(h);
  while (!QUEUEempty()) {
    (*visit)(h = QUEUEget());
    if (h->l != NULL)
      QUEUEput(h->l);
    if (h->r != NULL)
      QUEUEput(h->r);
  }
}

void print_node(link node) { printf("%c - ", node->item); }

#ifdef DEBUG_TREE_ADT
int main(void) {
  printf("Checking E05.79 (i):\n");
  link D = new_tree('D');
  link B = add_l(D, 'B');
  link F = add_r(D, 'F');
  link A = add_l(B, 'A');
  link C = add_r(B, 'C');
  link E = add_l(F, 'E');
  link G = add_r(F, 'G');
  printf("preorder:   ");
  traverse_preorder(D, print_node);
  printf("\n");
  printf("inorder:    ");
  traverse_inorder(D, print_node);
  printf("\n");
  printf("postorder:  ");
  traverse_postorder(D, print_node);
  printf("\n");
  printf("levelorder: ");
  traverse_level(D, print_node);
  printf("\n");

  printf("\nChecking E05.79 (ii):\n");
  C = new_tree('C');
  B = add_l(C, 'B');
  A = add_l(B, 'A');
  D = add_r(C, 'D');
  E = add_r(D, 'E');
  printf("preorder:   ");
  traverse_preorder(C, print_node);
  printf("\n");
  printf("inorder:    ");
  traverse_inorder(C, print_node);
  printf("\n");
  printf("postorder:  ");
  traverse_postorder(C, print_node);
  printf("\n");
  printf("levelorder: ");
  traverse_level(C, print_node);
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
  printf("preorder:   ");
  traverse_preorder(E, print_node);
  printf("\n");
  printf("inorder:    ");
  traverse_inorder(E, print_node);
  printf("\n");
  printf("postorder:  ");
  traverse_postorder(E, print_node);
  printf("\n");
  printf("levelorder: ");
  traverse_level(E, print_node);
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
  printf("preorder:   ");
  traverse_preorder(E, print_node);
  printf("\n");
  printf("inorder:    ");
  traverse_inorder(E, print_node);
  printf("\n");
  printf("postorder:  ");
  traverse_postorder(E, print_node);
  printf("\n");
  printf("levelorder: ");
  traverse_level(E, print_node);
  printf("\n");
}
#endif // #ifdef DEBUG_TREE_ADT

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./P05_tree_ADT.exe
Checking E05.79 (i):
preorder:   D - B - A - C - F - E - G -
inorder:    A - B - C - D - E - F - G -
postorder:  A - C - B - E - G - F - D -
levelorder: D - B - F - A - C - E - G -

Checking E05.79 (ii):
preorder:   C - B - A - D - E -
inorder:    A - B - C - D - E -
postorder:  A - B - E - D - C -
levelorder: C - B - D - A - E -

Checking E05.79 (iii):
preorder:   E - C - B - A - D - H - F - G - I -
inorder:    A - B - C - D - E - F - G - H - I -
postorder:  A - B - D - C - G - F - I - H - E -
levelorder: E - C - H - B - D - F - I - A - G -

Checking E05.80:
preorder:   E - D - B - A - C - H - F - G -
inorder:    A - B - C - D - E - F - G - H -
postorder:  A - C - B - D - G - F - H - E -
levelorder: E - D - H - B - F - A - C - G -
--------------------------------------------------------------------- */
