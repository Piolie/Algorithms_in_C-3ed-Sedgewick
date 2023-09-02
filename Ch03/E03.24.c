/* ---------------------------------------------------------------------
                             EXERCISE 3.24
------------------------------------------------------------------------
Write a function that returns the number of nodes on a circular list,
given a pointer to one of the nodes on the list.
--------------------------------------------------------------------- */

int circular_list_count(link first_node) {
  if (!first_node)
    return 0;

  link temp = first_node;
  int count = 1;
  while (temp->next != first_node) {
    count++;
    temp = temp->next;
  }
  return count;
}
