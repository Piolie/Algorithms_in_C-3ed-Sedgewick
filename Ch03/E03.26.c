/* ---------------------------------------------------------------------
                             EXERCISE 3.26
------------------------------------------------------------------------
Write a code fragment that, given pointers x and t to two disjoint
circular lists, inserts the list pointed to by t into the list pointed
to by x, at the point following x.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Nowhere has it been defined what inserting a circular list into another
circular list is. Also the exercise doesn't state that we have to end
with a circular list as a result of the "inserting operation". For what
I know, we could simply do x->next = t and be done with it.

   x           t                x          t
   *           *                * -------- *
 /   \       /   \            /          /   \
*     *     *     *          *     *    *     *
|     |     |     |    -->   |     |    |     |
*     *     *     *          *     *    *     *
 \   /       \   /            \   /      \   /
   *           *                *          *

I guess the author was thinking more of a solution like this:

   x           t                x          t
   *           *                * -------- *
 /   \       /   \            /              \
*     *     *     *          *     * -- *     *
|     |     |     |    -->   |     |    |     |
*     *     *     *          *     *    *     *
 \   /       \   /            \   /      \   /
   *           *                *          *

Here, we end with a big circular list and the sequence of nodes from
each list is preserved.

--------------------------------------------------------------------- */

link last = x->next;
link temp = t;
x->next = t;
while (temp->next != t)
    temp = temp->next;
temp->next = last;
