#include <assert.h>
#include <stdlib.h>

#include <TXLib.h>

#include "functions.h"

#define RedConsole   txSetConsoleAttr(FOREGROUND_RED)
#define WhiteConsole txSetConsoleAttr(FOREGROUND_WHITE)
#define GreenConsole txSetConsoleAttr(FOREGROUND_GREEN)

int OneTest(const double a, const double b, const double c, const int num_roots,
    double * x1, double * x2, const double rightx1, const double rightx2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (isfinite (rightx1));
    assert (isfinite (rightx2));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    switch (num_roots)
    {
    case ZERO_ROOTS:
        if (Square_solver (a, b, c, x1, x2) == ZERO_ROOTS)
            return 1;
        else
            return 0;
        break;
    case ONE_ROOT:
        if ((Square_solver (a, b, c, x1, x2) == ONE_ROOT) && (Compare (*x1, rightx1) == C_EQUAL))
            return 1;
        else
            return 0;
        break;
    case TWO_ROOTS:
        if ((Square_solver (a, b, c, x1, x2) == TWO_ROOTS)
        && (Compare (*x1, rightx1) == C_EQUAL) && (Compare (*x2, rightx2) == C_EQUAL))
            return 1;
        else
            return 0;
        break;
    case INF_ROOTS:
        if (Square_solver (a, b, c, x1, x2) == INF_ROOTS)
            return 1;
        else
            return 0;
    default:
        RedConsole;
        printf("Smth wrong with test data file or OneTest function\n");
        WhiteConsole;
        return 0;
    }
}
