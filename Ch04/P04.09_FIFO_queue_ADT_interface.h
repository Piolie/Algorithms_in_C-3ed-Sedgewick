/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 4.9
                        FIFO queue ADT interface
------------------------------------------------------------------------
This interface is identical to the pushdown stack interface of
Program 4.1, except for the names of the structure. The two ADTs differ
only in the specification, which is not reflected in the code.
--------------------------------------------------------------------- */

void QUEUEinit(int);
int QUEUEempty();
void QUEUEput(Item);
Item QUEUEget();
