/* ---------------------------------------------------------------------
                             EXERCISE 4.73
------------------------------------------------------------------------
Extend the polynomial ADT given in the text to include integration and
differentiation of polynomials.
--------------------------------------------------------------------- */

typedef struct poly *Poly;
void showPOLY(Poly);
Poly POLYterm(float, int);
Poly POLYadd(Poly, Poly);
Poly POLYmult(Poly, Poly);
float POLYeval(Poly, float);
Poly POLYintegrate(Poly);
Poly POLYdifferentiate(Poly);
void POLYdestroy(Poly);
Poly POLYcopy(Poly);
