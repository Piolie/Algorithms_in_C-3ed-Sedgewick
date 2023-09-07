/* ---------------------------------------------------------------------
                              EXERCISE 4.1
------------------------------------------------------------------------
Give a definition for Item and eq that might be used for floating-point
numbers, where two floating-point numbers are considered to be equal if
the absolute value of their difference divided by the larger (in
absolute value) of the two numbers is less than 10^-6.
--------------------------------------------------------------------- */

typedef float Item;
#define eq(A, B) (abs(A - B) / max(abs(A), abs(B)) < 1e-6 ? 1 : 0)
#define abs(X) (X > 0 ? (X) : (-X))
#define max(A, B) (A > B ? (A) : (B))
