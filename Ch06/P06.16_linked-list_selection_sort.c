/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 6.16
                       Linked-list selection sort
------------------------------------------------------------------------
Selection sort of a linked list is straightforward, but differs slightly
from the array version because it is easier to insert at the front of a
list. We maintain an input list (pointed to by h->next), and an output
list (pointed to by out). While it is nonempty, we scan the input list
to find the maximum remaining element, then remove that element from the
input list and insert it at the front of the output list. This
implementation uses an auxiliary routine findmax, which returns a link
to the node whose link points to the maximum element on a list (see
Exercise 3.34).
--------------------------------------------------------------------- */

link listselection(link h) {
  link max, t, out = NULL;
  while (h->next != NULL) {
    max = findmax(h);
    t = max->next;
    max->next = t->next;
    t->next = out;
    out = t;
  }
  h->next = out;
  return (h);
}
