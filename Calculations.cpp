#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "Calculations.h"

const long double EPSILON = 1e-3;

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
            double sqr_ca = sqrt (-c / a);
            *x1 =  sqr_ca;
            *x2 = -sqr_ca;
            return TWO_ROOTS;
        }
        else
            return ZERO_ROOTS;
    }

    double d = Calculate_discriminant (a, b, c);
    if ((Compare (d, 0) == C_MORE))
    {
        double sqr_d = sqrt (d);
        *x1 = (-b - sqr_d) / (2 * a);
        *x2 = (-b + sqr_d) / (2 * a);
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


int Linear_solver (const double k, const double b, double * x1)
{
    assert (isfinite (k));
    assert (isfinite (b));
    assert (x1 != NULL);

    if (Compare (k, 0) == C_EQUAL)
    {
        if (Compare (b, 0) == C_EQUAL)
            return INF_ROOTS;
        return ZERO_ROOTS;
    }

    *x1 = -b / k;
    return ONE_ROOT;
}


double Calculate_discriminant (const double a, const double b, const double c)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    return b*b - 4*a*c;
}


int Compare (const double n1, const double n2)
{
    assert (isfinite (n1));
    assert (isfinite (n2));

    if (fabs (n1 - n2) < EPSILON)
        return C_EQUAL;
    else if (n1 - n2 > EPSILON)
        return C_MORE;
    else
        return C_LESS;
}

