/* ---------------------------------------------------------------------
                             EXERCISE 4.72
------------------------------------------------------------------------
Modify the polynomial ADT interface, implementation, and client in the
text (Programs 4.21 through 4.23) such that there are no memory leaks.
To do so, define new operations POLYdestroy and POLYcopy, which should
free the memory for an object and copy one object's values to another,
respectively; and modify POLYadd and POLYmult to destroy their arguments
and return a newly created object, by convention.
--------------------------------------------------------------------- */

typedef struct poly *Poly;
void showPOLY(Poly);
Poly POLYterm(int, int);
Poly POLYadd(Poly, Poly);
Poly POLYmult(Poly, Poly);
float POLYeval(Poly, float);
void POLYdestroy(Poly);
Poly POLYcopy(Poly);
