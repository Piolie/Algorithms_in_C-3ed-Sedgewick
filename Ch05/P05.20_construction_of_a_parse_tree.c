/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 5.20
                      Construction of a parse tree
------------------------------------------------------------------------
Using the same strategy that we used to evaluate prefix expressions (see
Program 5.4), this program builds a parse tree from a prefix expression.
For simplicity, we assume that operands are single characters. Each call
of the recursive function creates a new node with the next character
from the input as the token. If the token is an operand, we return the
new node; if it is an operator, we set the left and right pointers to
the tree built (recursively) for the two arguments.
--------------------------------------------------------------------- */

char *a;
int i;
typedef struct Tnode *link;
struct Tnode {
  char token;
  link l, r;
};

link NEW(char token, link l, link r) {
  link x = malloc(sizeof *x);
  x->token = token;
  x->l = l;
  x->r = r;
  return x;
}

link parse(void) {
  char t = a[i++];
  link x = NEW(t, NULL, NULL);
  if ((t == '+') || (t == '*')) {
    x->l = parse();
    x->r = parse();
  }
  return x;
}
