/* ---------------------------------------------------------------------
                             EXERCISE 5.30
------------------------------------------------------------------------
Write a bottom-up nonrecursive program (similar to Program 5.9) that
draws the bottom diagram in Figure 5.12, in the manner described in
Exercise 5.30.
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
The fractal function is almost identical to rule() in P05.09. It has an
extra loop to generate the boxes in the second dimension and the update
rule for t changes, since the side of the squares should double each
time.

This program outputs the complete PostScript code to generate the last
diagram in figure 5.12 when invoked with the argument 5.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

void fractal(int l, int r, int d, int u, int h) {
  int i, j, t, k;
  for (t = 1, j = 1; t < h; j += j, t *= 2)
    for (k = 0; d + j + k <= u; k += j + j)
      for (i = 0; l + j + i <= r; i += j + j)
        printf("%4d %4d %4d box\n", (l + j + i), (d + j + k), t);
}

int main(int argc, char *argv[]) {
  (void)argc;
  int n = atoi(argv[1]);
  int d = 1 << n;
  float scale = 72 / 2.54; // make the page dimensions d-by-d cm
  printf("%%!PS\n");
  printf("<< /PageSize [%f %f] >> setpagedevice\n", scale * d, scale * d);
  printf("/box\n"
         "{\n"
         "  /r exch def               %% load r,\n"
         "  /y exch def               %% x, and\n"
         "  /x exch def               %% y with the values from the stack\n"
         "  newpath                   %% define new path\n"
         "    x y moveto              %% position at x, y\n"
         "    r 2 div r 2 div rmoveto %% offset r/2 in both directions\n"
         "    r neg 0 rlineto         %% draw the path\n"
         "    0 r neg rlineto\n"
         "    r 0 rlineto\n"
         "  closepath\n"
         "  gsave\n"
         "  0.5 setgray\n"
         "  fill                      %% fill\n"
         "  grestore\n"
         "  0 setgray\n"
         "  stroke                    %% stroke\n"
         "  } def\n");
  printf("%f dup scale\n", scale);
  printf("%f setlinewidth\n", 1.0 / scale);
  fractal(0, d, 0, d, d);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.31.exe 3
%!PS
<< /PageSize [226.771652 226.771652] >> setpagedevice
/box
{
  /r exch def               % load r,
  /y exch def               % x, and
  /x exch def               % y with the values from the stack
  newpath                   % define new path
    x y moveto              % position at x, y
    r 2 div r 2 div rmoveto % offset r/2 in both directions
    r neg 0 rlineto         % draw the path
    0 r neg rlineto
    r 0 rlineto
  closepath
  gsave
  0.5 setgray
  fill                      % fill
  grestore
  0 setgray
  stroke                    % stroke
  } def
28.346457 dup scale
0.035278 setlinewidth
   1    1    1 box
   3    1    1 box
   5    1    1 box
   7    1    1 box
   1    3    1 box
   3    3    1 box
   5    3    1 box
   7    3    1 box
   1    5    1 box
   3    5    1 box
   5    5    1 box
   7    5    1 box
   1    7    1 box
   3    7    1 box
   5    7    1 box
   7    7    1 box
   2    2    2 box
   6    2    2 box
   2    6    2 box
   6    6    2 box
   4    4    4 box
--------------------------------------------------------------------- */
