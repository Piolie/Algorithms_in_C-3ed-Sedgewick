"""
------------------------------------------------------------------------
                              EXERCISE 2.1
------------------------------------------------------------------------
Translate the programs in Chapter 1 to another programming language,
and answer Exercise 1.22 for your implementations.
------------------------------------------------------------------------

------------------------------------------------------------------------
I've chosen Python for the reimplementation.
------------------------------------------------------------------------
                             QUICK-FIND
------------------------------------------------------------------------
"""

N = 10000
id = []

for i in range(N):
    id.append(i)

while True:
    pair = input()
    p, q = [int(x) for x in pair.split()]

    if id[p] == id[q]:
        continue

    t = id[p]
    for i in range(N):
        if id[i] == t:
            id[i] = id[q]
    print("", p, q)
