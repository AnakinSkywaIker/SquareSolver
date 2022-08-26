#include "functions.h"
#include <math.h>
#include <assert.h>
#include <stdlib.h>


int Square_solver (const double a, const double b, const double c, double * x1, double * x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (Compare (a, 0) == C_EQUAL)                  // a == 0
        return Linear_solver (b, c, x1);

    if (Compare (b, 0) == C_EQUAL)                  // b == 0
    {
        if (Compare (c, 0) == C_EQUAL)              // c == 0 b == 0
        {
            *x1 = 0;
            return ONE_ROOT;
        }

        if (-c / a > 0)
        {
            *x1 = sqrt (-c / a);
            *x2 = -sqrt (-c / a);
            return TWO_ROOTS;
        }
        else
            return ZERO_ROOTS;
    }

    double d = Calculate_discriminant (a, b, c);

    if ((Compare (d, 0) == C_MORE))
    {
        *x1 = (-b - sqrt (d)) / (2 * a);
        *x2 = (-b + sqrt (d)) / (2 * a);
        return TWO_ROOTS;
    }
    else if (Compare (d, 0) == C_EQUAL)
    {
        *x1 = (-b + sqrt (d)) / (2 * a);
        return ONE_ROOT;
    }
    else
        return ZERO_ROOTS;

  return WRONG;
}
