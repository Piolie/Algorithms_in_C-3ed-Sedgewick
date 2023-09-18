/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.16
                  First-class ADT for complex numbers
------------------------------------------------------------------------
This interface provides clients with handles to complex number objects,
but does not give any information about the representation—it is a
struct that is not specified, except for its tag name.
--------------------------------------------------------------------- */

typedef struct complex *Complex;
Complex COMPLEXinit(float, float);
float Re(Complex);
float Im(Complex);
Complex COMPLEXmult(Complex, Complex);
