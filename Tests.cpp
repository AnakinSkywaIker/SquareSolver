#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <TXLib.h>

#include "Calculations.h"
#include "Tests.h"

#define RedConsole   txSetConsoleAttr(FOREGROUND_RED)
#define WhiteConsole txSetConsoleAttr(FOREGROUND_WHITE)
#define GreenConsole txSetConsoleAttr(FOREGROUND_GREEN)

const int Maxline = 40;

void SquareEquationTest(const char * name_test_file)
{
    double a  = NAN;
    double b  = NAN;
    double c  = NAN;
    double x1 = NAN;
    double x2 = NAN;

    double right_x1 = NAN;
    double right_x2 = NAN;

    int num_roots = NAN;
    int right_tests = 0;
    int count_tests = 0;
    bool flag_test = false;

    FILE * test_data = fopen (name_test_file, "r");
    if (test_data == NULL)
    {
        RedConsole;
        printf("Error: ");
        WhiteConsole;
        printf("can not open file with data\n");
        return;
    }

    char line[Maxline] = "";
    int num_cymbols = 0;
    while (fgets (line, Maxline, test_data) != NULL)
    {
        count_tests++;
        num_cymbols = sscanf(line, "%lg %lg %lg %d %lg %lg",
                                &a, &b, &c, &num_roots, &right_x1, &right_x2);
        x1 = 0;
        x2 = 0;

        if (num_cymbols < 3 || (num_cymbols != 4 + num_roots && !(num_roots == INF_ROOTS)))
        {
            RedConsole;
            printf("Error: ");
            WhiteConsole;
            printf("wrong data in SquareEquationTestData.txt\n");
            continue;
        }

        flag_test = OneTest(a, b, c, num_roots, &x1, &x2, right_x1, right_x2);
        right_tests += flag_test;
        if (flag_test)
        {
            GreenConsole;
            printf("Test OK\n");
            WhiteConsole;
        }
        else
        {
            RedConsole;
            printf("Test error: ");
            WhiteConsole;
            printf("a = %lg, b = %lg, c = %lg, num of roots = %d\n", a, b, c, num_roots);
            printf( "Expected roots: x1 = %lg, x2 = %lg, Your roots: x1 = %lg, x2 = %lg\n",
                   right_x1, right_x2, x1, x2);
        }
    }

    printf("Tests completed %d/%d\n", right_tests, count_tests);
    printf("End of test\n");
    fclose(test_data);
}


int OneTest(const double a, const double b, const double c, const int num_roots,
    double * x1, double * x2, const double rightx1, const double rightx2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    int calc_num_roots = Square_solver (a, b, c, x1, x2);

    switch (num_roots)
    {
    case ZERO_ROOTS:
        return (calc_num_roots == ZERO_ROOTS);
        break;

    case ONE_ROOT:
        return ((calc_num_roots == ONE_ROOT) && (Compare (*x1, rightx1) == C_EQUAL));
        break;

    case TWO_ROOTS:
        return ((calc_num_roots == TWO_ROOTS) && (Compare (*x1, rightx1) == C_EQUAL)
                && (Compare (*x2, rightx2) == C_EQUAL));
        break;

    case INF_ROOTS:
        return (calc_num_roots == INF_ROOTS);

    default:
        RedConsole;
        printf("Smth wrong with test data file or OneTest function\n");
        WhiteConsole;
        return 0;
    }
}
