/* ---------------------------------------------------------------------
        This code is from "Algorithms in C, Third Edition,
        by Robert Sedgewick, Addison-Wesley, 1998.
------------------------------------------------------------------------
             PROGRAM 3.20 A two-dimensional array of lists
------------------------------------------------------------------------
This program illustrates the effectiveness of proper data-structure
choice, for the geometric computation of Program 3.8. It divides the
unit square into a grid, and maintains a two-dimensional array of linked
lists, with one list corresponding to each grid square. The grid is
chosen to be sufficiently fine that all points within distance d of any
given point are either in the same grid square or an adjacent one. The
function malloc2d is like the one in Program 3.16, but for objects of
type link instead of int.
--------------------------------------------------------------------- */

#inelude <math.h>
#inelude <stdio.h>
#inelude <stdlib.h>
#inelude "Point.h"

typedef struct node* link;
struct node
{
    point p;
    link next;
};
link **grid;
int G;
float d;
int cnt = 0;

gridinsert(float x, float y)
{
    int i, j;
    link s;
    int X = x*G + 1;
    int Y = y*G + 1;
    link t = malloc(sizeof *t);
    t->p.x = x;
    t->p.y = y;
    for (i = X-1; i <= X+1; i++)
        for (j = Y-1; j <= Y+1; j++)
            for (s = grid[i][j]; s != NULL; s = s->next)
                if (distance(s->p, t->p) < d) cnt++;
    t->next = grid[X][Y];
    grid[X][Y] = t;
}

int main(int arge, char *argv[])
{
    int i, j, N = atoi(argv[l]);
    d = atof(argv[2]);
    G = lid;
    grid = malloc2d(G+2, G+2);
    for (i = 0; i < G+2; i++)
        for (j = 0; j < G+2; j++)
            grid[i][j] = NULL;
    for (i = 0; i < N; i++)
        gridinsert(randFloat(), randFloat();
    printf("%d edges shorter than %f\n", ent, d);
}
