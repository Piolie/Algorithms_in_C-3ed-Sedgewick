/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 5.17
                     Computation of tree parameters
------------------------------------------------------------------------
We can use simple recursive procedures such as these to learn basic
structural properties of trees.
--------------------------------------------------------------------- */

int count(link h) {
  if (h == NULL)
    return 0;
  return count(h->l) + count(h->r) + 1;
}

int height(link h) {
  int u, v;
  if (h == NULL)
    return -1;
  u = height(h->l);
  v = height(h->r);
  if (u > v)
    return u + 1;
  else
    return v + 1;
}
