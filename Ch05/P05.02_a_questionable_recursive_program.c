/* ---------------------------------------------------------------------
          This code is from "Algorithms in C, Third Edition,"
              by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
                              PROGRAM 5.2
                    A questionable recursive program
------------------------------------------------------------------------
If the argument N is odd, this function calls itself with 3N +1 as an
argument; if N is even, it calls itself with N/2 as an argument. We
cannot use induction to prove that this program terminates, because not
every recursive call uses an argument smaller than the one given.
--------------------------------------------------------------------- */

int puzzle(int N) {
  if (N == 1)
    return 1;
  if (N % 2 == 0)
    return puzzle(N / 2);
  else
    return puzzle(3 * N + 1);
}

/* ---------------------------------------------------------------------
  Figure 5.1
  Example of a recursive call chain

  This nested sequence of function calls eventually terminates, but we
  cannot prove that the recursive function in Program 5.2 does not have
  arbitrarily deep nesting for some argument. We prefer recursive
  programs that always invoke themselves with smaller arguments.

  puzzle(3)
    puzzle(10)
      puzzle(5)
        puzzle(16)
          puzzle 8)
            puzzle(4)
              puzzle(2)
                puzzle(1)
--------------------------------------------------------------------- */
