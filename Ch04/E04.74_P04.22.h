/* ---------------------------------------------------------------------
                             EXERCISE 4.74
------------------------------------------------------------------------
Modify your polynomial ADT from Exercise 4.73 to ignore all terms with
exponents greater than or equal to an integer M, which is provided by
the client at initialization.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
What is initialization supposed to mean? Should M be provided at each
call of POLYterm? Should it be a global variable instead?

I'll add a function to initialize a global variable. The client will be
responsible for calling POLYinit before using any of the other
functions. Only the first call will set the value. Subsequent calls will
be ignored.

For simplicity, I'll add a private function, POLYtrunc, that truncates
the corresponding terms, and apply it to the return value of functions
that could potentially exceed the exponent (POLYterm, POLYmult and
POLYintegrate).
--------------------------------------------------------------------- */

typedef struct poly *Poly;
void POLYinit(int);
void showPOLY(Poly);
Poly POLYterm(float, int);
Poly POLYadd(Poly, Poly);
Poly POLYmult(Poly, Poly);
float POLYeval(Poly, float);
Poly POLYintegrate(Poly);
Poly POLYdifferentiate(Poly);
void POLYdestroy(Poly);
Poly POLYcopy(Poly);
