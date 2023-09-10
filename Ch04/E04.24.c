/* ---------------------------------------------------------------------
                             EXERCISE 4.24
------------------------------------------------------------------------
Develop an ADT that provides clients with two different pushdown stacks.
Use an array implementation. Keep one stack at the beginning of the
array and the other at the end. (If the client program is such that one
stack grows while the other one shrinks, this implementation uses less
space than other alternatives.)
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I won't. We simply have to duplicate the functions from STACK.h (P04.01)
and for the implementation keep one index for each stack and index one
with s[N1] and the other with s[maxN - 1 - N2], or the like.
--------------------------------------------------------------------- */
