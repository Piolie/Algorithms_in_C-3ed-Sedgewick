/* ---------------------------------------------------------------------
                             EXERCISE 4.22
------------------------------------------------------------------------
Modify the linked-list-based pushdown-stack implementation in the text
(Program 4.5) to use an array of indices to implement the list (see
Figure 3.4).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Figure 3.4 illustrates linked-list insertion, maybe it's referring to
figure 3.6 (Array representation of a linked list)?
See E03.33 for a similar exercise.
I don't see how to prevent this from degenerating into an array
implementation without developing a mini-malloc to assign the array
entries each time STACKpush is invoked. In contrast with E03.33, the
item array is not assigned at the beginning. If we push each item to the
end of the item_array[], then we don't need the auxiliary next[] array
to keep track of the links, because next[i] == i - 1. If we push them
another way, then we have to keep record of which entries are taken,
which is what malloc does.
--------------------------------------------------------------------- */
