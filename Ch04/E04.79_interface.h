/* ---------------------------------------------------------------------
                             EXERCISE 4.79
------------------------------------------------------------------------
Develop an ADT that provides clients with the ability to perform
algebraic operations on vectors of floating-point numbers.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The vectors are stored as arrays of floats. The implementation does not
check for consistent vector types. The first operand in the add and mult
operations is modified. Nothing is freed.
--------------------------------------------------------------------- */

typedef struct fvec *Fvec;
void FVECshow(Fvec v);
Fvec FVECinit(int len);
void FVECset(Fvec v, int pos, float val);
Fvec FVECadd(Fvec u, Fvec v);
Fvec FVECmult(Fvec u, Fvec v);
