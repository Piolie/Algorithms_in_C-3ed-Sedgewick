/* ---------------------------------------------------------------------
                             EXERCISE 3.27
------------------------------------------------------------------------
Given pointers x and t to nodes on a circular list, write a code
fragment that moves the node following t to the position following the
node following x on the list.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Again, the intention of the author is not clear. The problem doesn't
require that we end with a circular list as a result of the "moving
operation" or even with a circular list that includes all the previous
nodes. Simply doing x->next->next = t->next would accomplish:

       x                    x
    -- * --              -- * --
   /       \            /       \
  *         *          *         *
  |         |    -->   |        /
  |         |          |       /
  *         * t        *      /  * t
   \       /            \    /  /
    -- * --              -- * --

I guess the author was thinking more of a solution like this:

       x                    x
    -- * --              -- * --
   /       \            /       \
  *         *          *         *
  |         |    -->   |        /
  |         |          |       /
  *         * t        *      /  * t
   \       /           |     /  /|
    -- * --            \    * -  /
                        ---------

Step by step: (in this drawing p1 coincides with t, but it's irrelevant)

       x                  x                  x                  x
    -- * --            -- * --            -- * --            -- * --
   /       \          /       \          /       \          /       \
  *         *        *         *        *         *        *         *
  |         |   -->  |         |   -->  |        /    -->  |        /
  |         |        |         |        |       /          |       /
  *      p1 * t      *      p1 * t      *      p1 * t      *      p1 * t
   \       /         |\        |        |\    /   |        |     /  /|
    -- * --          | -- *    |        | -- *    |        |    * -  |
       p2            \    p2   /        \    p2   /        \    p2   /
                      ---------          ---------          ---------
--------------------------------------------------------------------- */

link p1 = x->next->next;
link p2 = t->next;

t->next = t->next->next;

x->next->next = p2;
p2->next = p1;
