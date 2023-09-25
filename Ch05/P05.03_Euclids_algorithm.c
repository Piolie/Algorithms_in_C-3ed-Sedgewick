/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 5.3
                           Euclid's algorithm
------------------------------------------------------------------------
One of the oldest-known algorithms, dating back over 2000 years, is this
recursive method for finding the greatest common divisors of two
integers.
--------------------------------------------------------------------- */

int gcd(int m, int n) {
  if (n == 0)
    return m;
  return gcd(n, m % n);
}

/* ---------------------------------------------------------------------
  Figure 5.2
  Example of Euclid's algorithm

  This nested sequence of function calls illustrates the operation of
  Euclid's algorithm in discovering that 314159 and 271828 are
  relatively prime.

  gcd(314159, 271828)
    gcd(271828, 42331)
      gcd(42331 , 17842)
        gcd(17842, 6647)
          gcd(6647, 4458)
            gcd(4458 , 2099)
              gcd (2099, 350)
                gcd(350, 349)
                  gcd(349, 1)
                    gcd(1, 0)
--------------------------------------------------------------------- */
