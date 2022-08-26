#include <assert.h>
#include <math.h>

#include "functions.h"

int Compare (const double n1, const double n2)
{
    assert (isfinite (n1));
    assert (isfinite (n2));

    if (fabs (n1 - n2) < 1e-3)
        return C_EQUAL;
    else if (n1 - n2 > 1e-3)
        return C_MORE;
    else
        return C_LESS;
}
