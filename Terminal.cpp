#include "Calculations.h"

void Input (double *a, double *b, double *c)
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
        REDCONSOLE;
        printf ("Error with number roots, in function Square_solver\n");
        WHITECONSOLE;
        break;

    default:
        REDCONSOLE;
        printf ("Error with number of roots in function Output. Got: %d\n", num_roots);
        WHITECONSOLE;
        assert (0);
    }
}

void CleanBuffer()
{
    while (getchar () != '\n') {};
}

void SwitchTestOrCalc(int argc, const char *argv[])
{
    switch (argc)
    {
        case 1:
        {
            double a  = NAN;
            double b  = NAN;
            double c  = NAN;
            double x1 = NAN;
            double x2 = NAN;

            Input (&a, &b, &c);
            int num_roots =  Square_solver (a, b, c, &x1, &x2);
            Output (num_roots, x1, x2);
            break;
        }
        case 2:
        {
            printf("Test mode:\n");
            SquareEquationTest(argv[1]);
            break;
        }
        default:
        {
            REDCONSOLE;
            printf("Error unexpected num of args. expected <= 1. GOT: %d\n", argc);
            WHITECONSOLE;
        }
    }
}
