"""
------------------------------------------------------------------------
                              EXERCISE 2.1
------------------------------------------------------------------------
Translate the programs in Chapter 1 to another programming language,
and answer Exercise 1.22 for your implementations.
------------------------------------------------------------------------

------------------------------------------------------------------------
I've only run the tests for the weighted quick-union algorithm.
------------------------------------------------------------------------
         Weighted quick-union with path compression by halving
------------------------------------------------------------------------
"""

from random import random

N = 1000000
RUNS = 1

total = 0

for N in [1000, 10000, 100000, 1000000]:
    for run in range(RUNS):
        union_counter = 0
        attempts = 0

        id = []
        for i in range(N):
            id.append(i)
        sz = [1] * N

        while union_counter < N - 1:
            attempts += 1
            p, q = int(N * random()), int(N * random())

            i = p
            while i != id[i]:
                id[i] = i = id[id[i]]
            j = q
            while j != id[j]:
                id[j] = j = id[id[j]]

            if i == j:
                continue

            union_counter += 1

            if sz[i] < sz[j]:
                id[i] = j
                sz[j] += sz[i]
            else:
                id[j] = i
                sz[i] += sz[j]

        total += attempts

    print(f"average attempts for N = {N}: {total//RUNS}")

"""
------------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
average attempts for N = 3795
average attempts for N = 48227
average attempts for N = 600117
average attempts for N = 7189346
------------------------------------------------------------------------

These results are consistent with the ones we got in exercise 1.22.

Note: CPython took several minutes to finish the runs for N = 10^6 on
my machine. Though this implementation is not optimized, C is still king
(performance-wise).
------------------------------------------------------------------------
"""
