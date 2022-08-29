#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

#include "Calculations.h"
#include "Terminal.h"

void Input (double * a, double * b, double * c)
{
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    printf ("Enter coefficients a, b and c divided space:\n");

    while (scanf ("%lg %lg %lg", a, b, c) != 3)
    {
        printf ("These are not numbers, repeat please:\n");
        CleanBuffer();
    }
}


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
        break;

    default:
        assert (0 && "Something wrong with roots and output\n");
    }
}

void CleanBuffer()
{
    while (getchar () != '\n')
            continue;
}
