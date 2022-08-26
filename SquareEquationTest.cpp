#include <stdio.h>
#include <stdlib.h>

#include <TXLib.h>

#include "functions.h"

#define RedConsole   txSetConsoleAttr(FOREGROUND_RED)
#define WhiteConsole txSetConsoleAttr(FOREGROUND_WHITE)
#define GreenConsole txSetConsoleAttr(FOREGROUND_GREEN)

const int Maxline = 40;

void SquareEquationTest(void)
{
    double a  = 0;
    double b  = 0;
    double c  = 0;
    double x1 = 0;
    double x2 = 0;
    double rightx1 = 0;
    double rightx2 = 0;
    int num_roots = 0;
    int right_tests = 0;
    int count_tests = 0;
    bool flag_test = 0;

    FILE * test_data = fopen ("SquareEquationTestData.txt", "r");
    if (test_data == NULL)
    {
        RedConsole;
        printf("Error: can not open file with data\n");
        WhiteConsole;
        return;
    }

    char line[40] = "";
    int num_cymbols = 0;
    while (fgets (line, Maxline, test_data) != NULL)
    {
        count_tests++;
        num_cymbols = sscanf(line, "%lg %lg %lg %d %lg %lg",
                                &a, &b, &c, &num_roots, &rightx1, &rightx2);
        x1 = 0;
        x2 = 0;

        if (num_cymbols < 3)
        {
            RedConsole;
            printf("Error: wrong data in SquareEquationTestData.txt\n");
            WhiteConsole;
            continue;
        }

        flag_test = OneTest(a, b, c, num_roots, &x1, &x2, rightx1, rightx2);
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
            printf("Test error: a = %lg, b = %lg, c = %lg, num of roots = %d\n", a, b, c, num_roots);
            printf( "Expected roots: x1 = %lg, x2 = %lg, Your roots: x1 = %lg, x2 = %lg\n",
                   rightx1, rightx2, x1, x2);
            WhiteConsole;
        }
    }

    printf("Tests completed %d/%d\n", right_tests, count_tests);
    printf("End of test\n");
    fclose(test_data);
}
