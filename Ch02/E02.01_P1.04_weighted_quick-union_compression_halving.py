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
        WEIGHTED QUICK-UNION WITH PATH COMPRESSION BY HALVING
----------------------------------------------------------------------
"""

N = 10000
id = []
sz = [1]*N

for i in range(N):
    id.append(i)

while True:
    pair = input()
    p, q = [int(x) for x in pair.split()]

    i = p
    while i != id[i]:
        id[i] = i = id[id[i]]
    j = q
    while j != id[j]:
        id[j] = j = id[id[j]]

    if i == j:
        continue

    if sz[i] < sz[j]:
        id[i] = j
        sz[j] += sz[i]
    else:
        id[j] = i
        sz[i] += sz[j]

    print("", p, q)
