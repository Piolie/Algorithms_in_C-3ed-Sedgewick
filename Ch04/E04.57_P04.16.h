/* ---------------------------------------------------------------------
                             EXERCISE 4.57
------------------------------------------------------------------------
Add a function CDMPLEXadd to the ADT for complex numbers in the
text (Programs 4.16 and 4.17).
--------------------------------------------------------------------- */

typedef struct complex *Complex;
Complex COMPLEXinit(float, float);
float Re(Complex);
float Im(Complex);
Complex COMPLEXadd(Complex, Complex);
Complex COMPLEXmult(Complex, Complex);
