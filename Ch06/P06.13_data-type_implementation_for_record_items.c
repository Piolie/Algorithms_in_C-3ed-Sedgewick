/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 6.13
               Data-type implementation for record items
------------------------------------------------------------------------
These implementations of the ITEMscan and ITEMshoy functions for records
operate in a manner similar to the string data-type implementation of
Program 6.11, in that they allocate and maintain the memory for the
records. We keep the implementation of less in a separate file, so that
we can substitute different implementations, and therefore change sort
keys, without changing any other code.
--------------------------------------------------------------------- */

struct record data[maxN];
int Nrecs = 0;

int ITEMscan(struct record **x) {
  *x = &data[Nrecs];
  return scanf("%30s %d\n", data[Nrecs].name, &data[Nrecs++].num);
}

void ITEMshow(struct record *x) { printf("%3d %-30s\n", x->num, x->name); }
