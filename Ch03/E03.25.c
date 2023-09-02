/* ---------------------------------------------------------------------
                             EXERCISE 3.25
------------------------------------------------------------------------
Write a code fragment that determines the number of nodes that are
between the nodes referenced by two given pointers x and t to nodes on a
circular list.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
In a circular list, the number of nodes between any two nodes N1 and N2
depends on whether we start counting from N1 or N2. (Assuming the links
are followed clockwise.)

                      N1
                      *
                    /   \
                   *     *    1 node?
                   |     |    (start from N1)
         3 nodes?  *     * N2
  (start from N2)   \   /
                      *

If the list has M nodes and the number of nodes between N1 and N2 is d,
then the number of nodes between N2 and N1 is simply M - 2 - d.

The statement doesn't say how to count. I'll do it from x to t.
--------------------------------------------------------------------- */

link temp = x;
int count = 0;
while (temp->next != t) {
  count++;
  temp = temp->next;
}
