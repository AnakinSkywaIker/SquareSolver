#include <assert.h>
#include <math.h>

double Calculate_discriminant (const double a, const double b, const double c)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    return b*b - 4*a*c;
}
