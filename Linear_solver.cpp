#include <assert.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h"

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


