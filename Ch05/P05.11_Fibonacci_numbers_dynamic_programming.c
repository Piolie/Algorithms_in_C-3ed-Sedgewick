/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 5.11
                Fibonacci numbers (dynamic programming)
------------------------------------------------------------------------
By saving the values that we compute in an array external to the
recursive procedure, we explicitly avoid any recomputation. This program
computes F_N in time proportional to N, in stark contrast to the O(ϕ^N)
time used by Program 5.10.
--------------------------------------------------------------------- */

int F(int i) {
  int t;
  if (knownF[i] != unknown)
    return knownF[i];
  if (i == 0)
    t = 0;
  if (i == 1)
    t = 1;
  if (i > 1)
    t = F(i - 1) + F(i - 2);
  return knownF[i] = t;
}
