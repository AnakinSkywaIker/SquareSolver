#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "functions.h"

void Output (const int num_roots, const double x1, const double x2)
{
    assert (isfinite (x1));
    assert (isfinite (x2));

    switch (num_roots)
    {
    case ZERO_ROOTS:
        printf ("no roots\n");
        break;
    case ONE_ROOT:
        printf ("one root: ");
        printf ("%.3lg\n", x1);
        break;
    case TWO_ROOTS:
        printf ("two roots: ");
        printf ("%.3lg, %.3lg\n", x1, x2);
        break;
    case INF_ROOTS:
        printf ("Infinite number of roots\n");
        break;
    case WRONG:
        printf ("Something wrong with roots\n");
    default:
        printf ("Something wrong with roots and output\n");
    }
}
