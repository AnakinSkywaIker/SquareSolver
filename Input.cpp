#include <stdio.h>
#include "functions.h"
#include <assert.h>
#include <stdlib.h>
#include <math.h>


void Input (double * a, double * b, double * c)
{
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    printf ("Enter coefficients a, b and c divided space:\n");

    while (scanf ("%lg %lg %lg", a, b, c) != 3)
    {
        printf ("These are not numbers, repeat please:\n");

        while (getchar () != '\n')
            continue;
    }
}
