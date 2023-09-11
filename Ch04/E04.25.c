/* ---------------------------------------------------------------------
                             EXERCISE 4.25
------------------------------------------------------------------------
Implement an infix-expression-evaluation function for integers that
includes Programs 4.2 and 4.3, using your ADT from Exercise 4.24.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Combining P04.02 and P04.03 requires two stacks of *char for converting
from infix to postfix, and another of the appropriate element type to
evaluate the postfix expression (see E04.16). We could use the ADT from
E04.24 for the former, but we would still need another stack for the
latter.
--------------------------------------------------------------------- */
