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
                              Quick-union
------------------------------------------------------------------------
"""

N = 10000
id = []

for i in range(N):
    id.append(i)

while True:
    pair = input()
    p, q = [int(x) for x in pair.split()]

    i = p
    while i != id[i]:
        i = id[i]
    j = q
    while j != id[j]:
        j = id[j]

    if i == j:
        continue

    id[i] = j

    print("", p, q)
