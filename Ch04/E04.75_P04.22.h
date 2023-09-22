/* ---------------------------------------------------------------------
                             EXERCISE 4.75
------------------------------------------------------------------------
Extend your polynomial ADT from Exercise 4.73 to include polynomial
division and composition.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
What should the division return? Only the quotient? Both quotient and
remainder? What if the divisor is null?
I'll only return the quotient (modifications also to return the
remainder would be easy to implement) and ignore the null divisor case.
The algorithm for long division was adapted from the
[Wikipedia](https://en.wikipedia.org/wiki/Polynomial_long_division#Pseudocode)

Division returns n/d. Composition returns p(q).

The implementation uses a couple private auxiliary functions:
- POLYbyscalar: multiplies a polynomial by a scalar number;
- POLYdeg: returns the highest exponent of the nonzero terms,
  irrespective of the value of N; and
- POLYisnull: determines if the polynomial has all zero coefficients.
scalar.
--------------------------------------------------------------------- */

typedef struct poly *Poly;
void showPOLY(Poly p);
Poly POLYterm(float coeff, int exp);
Poly POLYadd(Poly p, Poly q);
Poly POLYmult(Poly p, Poly q);
float POLYeval(Poly p, float x);
Poly POLYintegrate(Poly p);
Poly POLYdifferentiate(Poly p);
Poly POLYdivide(Poly n, Poly d);
Poly POLYcompose(Poly p, Poly q);
void POLYdestroy(Poly p);
Poly POLYcopy(Poly p);
