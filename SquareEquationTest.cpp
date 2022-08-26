#include <stdio.h>
#include "functions.h"
#include <TXLib.h>
#include <stdlib.h>


const int maxline = 40;
char line[40];


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
        txSetConsoleAttr(FOREGROUND_RED);
        printf("Error: can not open file with data\n");
        txSetConsoleAttr(FOREGROUND_WHITE);
        return;
    }


    int num_cymbols = 0;
    while (fgets (line, maxline, test_data) != NULL)
    {
        count_tests++;
        num_cymbols = sscanf(line, "%lg %lg %lg %d %lg %lg",
                                &a, &b, &c, &num_roots, &rightx1, &rightx2);
        x1 = 0;
        x2 = 0;

        if (num_cymbols < 3)
        {
            txSetConsoleAttr(FOREGROUND_RED);
            printf("Error: wrong data in SquareEquationTestData.txt\n");
            txSetConsoleAttr(FOREGROUND_WHITE);
            continue;
        }

        flag_test = OneTest(a, b, c, num_roots, &x1, &x2, rightx1, rightx2);
        right_tests += flag_test;
        if (flag_test)
        {
            txSetConsoleAttr(FOREGROUND_GREEN);
            printf("Test OK\n");
            txSetConsoleAttr(FOREGROUND_WHITE);
        }
        else
        {
            txSetConsoleAttr(FOREGROUND_RED);
            printf("Test error: a = %lg, b = %lg, c = %lg, num of roots = %d\n", a, b, c, num_roots);
            printf( "Expected roots: x1 = %lg, x2 = %lg, Your roots: x1 = %lg, x2 = %lg\n",
                   rightx1, rightx2, x1, x2);
            txSetConsoleAttr(FOREGROUND_WHITE);
        }
    }
    printf("Tests completed %d/%d\n", right_tests, count_tests);
    printf("End of test\n");
    fclose(test_data);
}
