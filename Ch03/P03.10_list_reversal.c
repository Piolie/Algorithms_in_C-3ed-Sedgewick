/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 3.10
                             List reversal
------------------------------------------------------------------------
This function reverses the links in a list, returning a pointer to the
final node, which then points to the next-to-final node, and so forth,
with the link in the first node of the original list set to NULL. To
accomplish this task, we need to maintain links to three consecutive
nodes in the list.
--------------------------------------------------------------------- */

link reverse(link x) {
  link t, y = x, r = NULL;
  while (y != NULL) {
    t = y->next;
    y->next = r;
    r = y;
    y = t;
  }
  return r;
}
