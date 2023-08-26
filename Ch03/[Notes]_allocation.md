MEMORY ALLOCATION NOTES
-----------------------

Given the book states in p. 93 that:

>When we remove a node from a linked list using `x->next = x->next->next`, we may never be able to access it again. For small programs such as the examples we consider at first, this is no special concern, but we generally regard it as good programming practice to use the function `free`, which is the counterpart to `malloc`, for any node that we no longer wish to use. Specifically, the sequence of instructions

>`t = x->next; x->next = t->next; free(t);`

>not only removes t from our list but also informs the system that the memory it occupies may be used for some other purpose. We pay particular attention to free when we have large list objects, or large numbers of them, but we will ignore it until Section 3.5, so that we may focus on appreciating the benefits of linked structures.

I don't pay too much attention to clean memory management. Particularly, I generally don't check for nullnes after malloc. However, in exercise 3.38 I experimented with some error handling using goto statements.

Also, there are very interesting questions in StackOverflow:

- [Correctly allocating multi-dimensional arrays](https://stackoverflow.com/questions/42094465/) and
- [Function to dynamically allocate matrix](https://stackoverflow.com/questions/32050256/)

which discourage using pointers-to-pointers. The book uses the wrong approach in several places, e.g., the `malloc2d` function in P3.16.
