/* ---------------------------------------------------------------------
                              EXERCISE 4.3
------------------------------------------------------------------------
Add a macro ITEMshow to the generic object type definitions for integers
and strings described in the text. Your macro should print the value of
the item on standard output.
--------------------------------------------------------------------- */

typedef char *Item;
#define eq(A, B) (strcmp(A, B) == 0)
#define ITEMshow(X) printf("%s", X);
