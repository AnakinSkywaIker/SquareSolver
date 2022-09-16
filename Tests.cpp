#include "Calculations.h"

static const int Maxline = 40;

void SquareEquationTest(const char *name_test_file)
{
    double a  = NAN;
    double b  = NAN;
    double c  = NAN;
    double x1 = NAN;
    double x2 = NAN;

    double right_x1 = NAN;
    double right_x2 = NAN;

    int num_roots   = 0;
    int right_tests = 0;
    int count_tests = 0;
    bool flag_test  = false;

    FILE *test_data = fopen (name_test_file, "r");
    if (test_data == NULL)
    {
        REDCONSOLE;
        printf("Error: ");
        WHITECONSOLE;
        printf("can not open file with data\n");
        return;
    }

    char line[Maxline] = "";
    int num_cymbols = 0;
    while (fgets (line, Maxline, test_data) != NULL)
    {
        count_tests++;
        //char sep = 0;
        num_cymbols = sscanf(line, "%lg %lg %lg %d %lg %lg",
                                &a, &b, &c, &num_roots, &right_x1, &right_x2);
        x1 = 0;
        x2 = 0;

        if (num_cymbols < 3 || (num_cymbols != 4 + num_roots && !(num_roots == INF_ROOTS)))
        {
            REDCONSOLE;
            printf("Error: ");
            WHITECONSOLE;
            printf("wrong data in SquareEquationTestData.txt\n");
            continue;
        }

        TestData DataForTest = {};

        DataForTest.a         = a;
        DataForTest.b         = b;
        DataForTest.c         = c;
        DataForTest.num_roots = num_roots;
        DataForTest.x1        = &x1;
        DataForTest.x2        = &x2;
        DataForTest.rightx1   = right_x1;
        DataForTest.rightx2   = right_x2;

        flag_test = OneTest(&DataForTest);
        right_tests += flag_test;
        if (flag_test)
        {
            GREENCONSOLE;
            printf("Test OK\n");
            WHITECONSOLE;
        }
        else
        {
            REDCONSOLE;
            printf("Test error: ");
            WHITECONSOLE;
            printf("a = %lg, b = %lg, c = %lg, num of roots = %d\n", a, b, c, num_roots);
            printf( "Expected roots: x1 = %lg, x2 = %lg, Your roots: x1 = %lg, x2 = %lg\n",
                   right_x1, right_x2, x1, x2);
        }
    }

    printf("Tests completed %d/%d\n", right_tests, count_tests);
    printf("End of test\n");
    fclose(test_data);
}


int OneTest(TestData *DataForTest)
{
    double a         = (*DataForTest).a;
    double b         = (*DataForTest).b;
    double c         = (*DataForTest).c;
    int    num_roots = (*DataForTest).num_roots;
    double *x1       = (*DataForTest).x1;
    double *x2       = (*DataForTest).x2;
    double rightx1   = (*DataForTest).rightx1;
    double rightx2   = (*DataForTest).rightx2;


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
        REDCONSOLE;
        printf("Error: wrong number of roots in function OneTest, GOT: %d\n", num_roots);
        WHITECONSOLE;
        return 0;
    }
}
