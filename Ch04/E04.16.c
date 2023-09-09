/* ---------------------------------------------------------------------
                             EXERCISE 4.16
------------------------------------------------------------------------
Combine Program 4.2 and Program 4.3 into a single module that uses
two different stack ADTs: a stack of integers and a stack of operators.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
This exercise is in fact an implementation of [Dijkstra’s Shunting yard
algorithm](https://en.wikipedia.org/wiki/Shunting_yard_algorithm)
(or Dijkstra’s two-stack arithmetic expression-evaluation algorithm, for
fully parenthesized arithmetic expressions).

It requires duplicating the Item.h definitions, so as to have functions
for manipulating the different stack types. It doesn't add much, so I'll
leave it unsolved.

It would be better to have implementations that don't depend on the
concrete types defined in Item.h, and that allowed us to work with
multiple stacks at the same time. That way, we could use two stacks for
the conversion and another for the evaluation.
--------------------------------------------------------------------- */
