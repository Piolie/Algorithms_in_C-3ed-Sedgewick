/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 5.10
              Fibonacci numbers (recursive implementation)
------------------------------------------------------------------------
This program, although compact and elegant, is not usable because it
takes exponential time to compute F_N. The running time to compute
F_(N+1) is ϕ ~= 1.6 times as long as the running time to compute F_N.
For example, since ϕ^9 > 60, if we notice that our computer takes about
a second to compute F_N, we know that it will take more than a minute
to compute F_(N+9) and more than an hour to compute F_(N+18).
--------------------------------------------------------------------- */

int F(int i) {
  if (i < 1)
    return 0;
  if (i == 1)
    return 1;
  return F(i - 1) + F(i - 2);
}
