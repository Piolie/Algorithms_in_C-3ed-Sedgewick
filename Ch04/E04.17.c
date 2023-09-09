/* ---------------------------------------------------------------------
                             EXERCISE 4.17
------------------------------------------------------------------------
Implement a compiler and interpreter for a programming language where
each program consists of a single arithmetic expression preceded by a
sequence of assignment statements with arithmetic expressions involving
integers and variables named with single lower-case characters. For
example, given the input
  (x = 1)
  (y = (x + 1))
  (((x + y) * 3) + (4 * x)
your program should print the value 13.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
Like in E04.16, we could use two stacks and push the operands to one and
the operators to the other. If we find a ')' we pop, apply the operator
and push to the stack. Since we now have to deal with '=', we use an
array to store the values of each of the single lower-case characters.
If the "operator" is '=', we don't push, but instead assign to the
corresponding entry in the array. If one of the operands is a letter, we
read it from the array and proceed as if it was an Item popped from the
operands stack.

We can do this for each line of the program and finally pop and print
the result.
--------------------------------------------------------------------- */
