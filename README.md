In this repo I'll be adding my solutions to the exercises in the book [Algorithms in C, Third Edition, Parts 1-4](https://www.pearson.com/us/higher-education/program/Sedgewick-Algorithms-in-C-Parts-1-4-Fundamentals-Data-Structures-Sorting-Searching-3rd-Edition/PGM295950.html), by Robert Sedgewick.

I aim to solve every single exercise, although this is just for fun and may never be finished. Some "solutions" only contain the problem statement and a `MISSING!` notice. Others just some hints or musings.

# Printing number

The copy I have available is of a 14th printing, dated January 2006. There have been some modifications and corrections both before and after this printing, so if you are working with a different one keep an eye out for some (hopefully) minor discrepancies.

# Project structure

Each chapter has its own folder and for convenience I've also included the original programs from the book ready to be compiled and run (where it makes sense).

Files for the solutions are named `E<CC>.<XX>.<ext>`, where `<CC>` is the chapter number, `<XX>` is the exercise number and `<ext>` is the corresponding file extension: either `h`/`c` for code solutions or `txt` for the rest. Some solutions include output from the respective program at the bottom of the file and maybe some comments.

Similarly, programs are named `P<CC>.<XX>_<description>.<ext>`, where the extra `<description>` is the title given in the book. Since the book calls some programs by one name (e.g. "Program 3.3") but then refers to a different filename (e.g. "Point.h"), I have included more than one copy of some files with different filenames, so as to be both easy to find and to include in other programs/solutions.

There are also some additional notes pertaining to the topics of the corresponding chapter, which I have taken to aid me in working out the solutions.

# Compiling
I used GCC 10.3.0 (MSYS2) and compiled all single file programs with options:

    -m64 -std=c99 -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes

For those cases in which it is necessary to compile and link several files, I have also included a `makefile`. You can run it with

    make -f <E/P>.<CC>.mak

See [Makefile Tutorial](https://makefiletutorial.com/) for a nice introduction to makefiles.

# Warranty
It goes without saying that the solutions are not guaranteed to be good or even working. Feel free to open an issue or file a pull request if you believe there is an addition/improvement/correction to make.

# License
The code from the book, as stated in the author's [(archived)](https://web.archive.org/web/20211221063054/https://www.cs.princeton.edu/~rs/Algs3.c1-4/code.txt) page, comes with some strings attached. See [COPYRIGHT](COPYRIGHT.md) for more information.

I release my modifications and all original works made by me under the MIT License. See [LICENSE](LICENSE.md) for the details.

**IANAL:** Since some of the exercises consist of modifying the supplied programs, I think it's permitted to share and reuse those modifications for the purposes explained in the copyright notice, though I cannot guarantee it.
