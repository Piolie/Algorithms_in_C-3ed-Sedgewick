/* ---------------------------------------------------------------------
                             EXERCISE 5.30
------------------------------------------------------------------------
Write a recursive C program that outputs a PostScript program that draws
the bottom diagram in Figure 5.12, in the form of a list of function
calls x y r box, which draws an r-by-r square at (x, y). Implement box
in PostScript (see Section 4.3).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
fractal() divides the region in four parts and acts recursively on each
one:

  l       mh      r
   ---------------  u
  |       |       |
  |   3   |   4   |
  |       |       |
   ---------------  mv
  |       |       |
  |   1   |   2   |
  |       |       |
   ---------------  d

The call to printf to generate the boxes has to come after the recursive
calls, in order for the smaller boxes to show bellow the larger ones.

This program outputs the complete PostScript code to generate the last
diagram in figure 5.12 when invoked with the argument 5.
--------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

void fractal(int l, int r, int d, int u, int h) {
  int mh = (l + r) / 2;
  int mv = (d + u) / 2;
  if (h > 1) {
    fractal(l, mh, d, mv, h / 2); // 1
    fractal(mh, r, d, mv, h / 2); // 2
    fractal(l, mh, mv, u, h / 2); // 3
    fractal(mh, r, mv, u, h / 2); // 4
    printf("%4d %4d %4d box\n", mh, mv, h / 2);
  }
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
./E05.30.exe 3
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
   1    3    1 box
   3    3    1 box
   2    2    2 box
   5    1    1 box
   7    1    1 box
   5    3    1 box
   7    3    1 box
   6    2    2 box
   1    5    1 box
   3    5    1 box
   1    7    1 box
   3    7    1 box
   2    6    2 box
   5    5    1 box
   7    5    1 box
   5    7    1 box
   7    7    1 box
   6    6    2 box
   4    4    4 box
--------------------------------------------------------------------- */
