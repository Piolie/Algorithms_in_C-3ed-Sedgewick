/* ---------------------------------------------------------------------
                              EXERCISE 4.3
------------------------------------------------------------------------
Add a macro ITEMshow to the generic object type definitions for integers
and strings described in the text. Your macro should print the value of
the item on standard output.
--------------------------------------------------------------------- */

typedef int Item;
#define eq(A, B) (A == B)
#define ITEMshow(X) printf("%d", X);
