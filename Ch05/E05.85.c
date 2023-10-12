/* ---------------------------------------------------------------------
                             EXERCISE 5.85
------------------------------------------------------------------------
Modify Program 5.18 to output a PostScript program that draws the tree,
in a format like that used in Figure 5.23, but without the small boxes
to represent the external nodes. Use moveto and lineto to draw lines,
and the user-defined operator
  /node { newpath moveto currentpoint 0 360 arc fill} def
to draw nodes. After this definition, the call node draws a black dot at
the coordinates on the stack (see Section 4·3).
--------------------------------------------------------------------- */

/* ---------------------------------------------------------------------
I've managed to print the nodes correctly. However, I could not figure
the edges out. At least not without substantially modifying the program.

This program prints the tree from figure 5.26 rotated 180 degrees.
--------------------------------------------------------------------- */

#include "P05_tree_ADT.c"
#include <stdio.h>

static int x = 10;

void printnode(char c, int h) {
  if (c != '*')
    printf("%3d %3d node\n", x, 30 * h);

  printf("%3d %3d moveto (%c) show\n", x - 2, 30 * h - 2, c);
}

void show(link tree, int h) {
  if (tree == NULL) {
    printnode('*', h);
    return;
  }
  show(next_r(tree), h + 1);
  x += 20;
  printnode(get_item(tree), h);
  x += 20;
  show(next_l(tree), h + 1);
}

int main(void) {
  printf("%%!PS\n");
  printf("<< /PageSize [350 150] >> setpagedevice\n");
  printf("/node {moveto currentpoint newpath 4 0 360 arc stroke} def\n");
  printf("/Courier-Bold findfont 7 scalefont setfont\n");
  printf("0 10 translate\n");

  link E = new_tree('E');
  link D = add_l(E, 'D');
  link B = add_l(D, 'B');
  link A = add_l(B, 'A');
  link C = add_r(B, 'C');
  link H = add_r(E, 'H');
  link F = add_l(H, 'F');
  link G = add_r(F, 'G');

  (void)G;
  (void)C;
  (void)A;

  show(E, 0);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
./E05.85.exe
%!PS
<< /PageSize [350 150] >> setpagedevice
/node {moveto currentpoint newpath 4 0 360 arc stroke} def
/Courier-Bold findfont 7 scalefont setfont
0 10 translate
  8  58 moveto (*) show
 30  30 node
 28  28 moveto (H) show
 48 118 moveto (*) show
 70  90 node
 68  88 moveto (G) show
 88 118 moveto (*) show
110  60 node
108  58 moveto (F) show
128  88 moveto (*) show
150   0 node
148  -2 moveto (E) show
168  58 moveto (*) show
190  30 node
188  28 moveto (D) show
208 118 moveto (*) show
230  90 node
228  88 moveto (C) show
248 118 moveto (*) show
270  60 node
268  58 moveto (B) show
288 118 moveto (*) show
310  90 node
308  88 moveto (A) show
328 118 moveto (*) show
--------------------------------------------------------------------- */
