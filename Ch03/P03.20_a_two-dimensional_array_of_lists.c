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

/* ---------------------------------------------------------------------
I have added the necessary auxiliary functions to compile and run the
program. In particular, malloc2d has been modified as requested in the
statement.

Note that the assignments G = 1/d and similar ones risk invoking UB in
case the assigned value (a float) doesn’t fit into the destination type
(an int).

Also, in my system this program crashes if N is set to 19362 or more.
That's because for that value, randFloat() produces 1.00000. This makes
X in gridinsert equal to 10001, which makes it possible for the i
variable inside the for loop to reach 10002 (i <= X+1), which then
enables an attempt to access an out of bounds index in grid[i][j].
I'd say the bug is in the definition of randFloat. Diving by
(RAND_MAX + 1) instead of by RAND_MAX solves the issue.
--------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

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

link **malloc2d(int r, int c)
{
    int i;
    link **t = malloc(r * sizeof(link *));
    for (i = 0; i < r; i++)
        t[i] = malloc(c * sizeof(link));
    return t;
}

float randFloat(void)
{
    return 1.0*rand()/RAND_MAX;
}

float distance(point a, point b)
{
    float dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

void gridinsert(float x, float y)
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
                if (distance(s->p, t->p) < d)
                    cnt++;
    t->next = grid[X][Y];
    grid[X][Y] = t;
}

int main(int argc, char *argv[])
{
    (void)argc;
    int i, j, N = atoi(argv[1]);
    d = atof(argv[2]);
    G = 1/d;
    grid = malloc2d(G+2, G+2);
    for (i = 0; i < G+2; i++)
        for (j = 0; j < G+2; j++)
            grid[i][j] = NULL;
    for (i = 0; i < N; i++)
        gridinsert(randFloat(), randFloat());
    printf("%d edges shorter than %f\n", cnt, d);
}

/* ---------------------------------------------------------------------
                                 OUTPUT
------------------------------------------------------------------------
P03.20_a_two-dimensional_array_of_lists.exe 1000 1
488477 edges shorter than 1.000000

P03.20_a_two-dimensional_array_of_lists.exe 1000 0.1
14293 edges shorter than 0.100000

P03.20_a_two-dimensional_array_of_lists.exe 1000 0.01
130 edges shorter than 0.010000

P03.20_a_two-dimensional_array_of_lists.exe 1000 0.001
2 edges shorter than 0.001000

P03.20_a_two-dimensional_array_of_lists.exe 1000 0.0001
0 edges shorter than 0.000100

P03.20_a_two-dimensional_array_of_lists.exe 10000 0.0001
3 edges shorter than 0.000100

P03.20_a_two-dimensional_array_of_lists.exe 100000 0.0001
kaput! see note at the beggining

--------------------------------------------------------------------- */
