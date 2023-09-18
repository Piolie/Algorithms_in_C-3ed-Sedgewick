/* ---------------------------------------------------------------------
                             EXERCISE 4.58
------------------------------------------------------------------------
Convert the equivalence-relations ADT in Section 4.5 to a first-class
type.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The exercise refers to P04.06 and P04.08. I've also adapted the client
from P04.07 and provided a makefile that uses this implementation.
--------------------------------------------------------------------- */

typedef struct uf *Uf;
Uf UFinit(int);
int UFfind(Uf, int, int);
void UFunion(Uf, int, int);
