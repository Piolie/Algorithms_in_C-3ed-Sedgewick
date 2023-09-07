/* ---------------------------------------------------------------------
                              EXERCISE 4.2
------------------------------------------------------------------------
Give a definition for Item and eq that might be used for points in the
plane (see Section 3.1).
--------------------------------------------------------------------- */

typedef struct {
  float x;
  float y;
} point;

#define eq(A, B) (float_eq(A.x, B.x) && float_eq(A.y, B.y) ? 1 : 0)
#define float_eq(A, B) (abs(A - B) / max(abs(A), abs(B)) < 1e-6 ? 1 : 0)
#define abs(X) (X > 0 ? (X) : (-X))
#define max(A, B) (A > B ? (A) : (B))
