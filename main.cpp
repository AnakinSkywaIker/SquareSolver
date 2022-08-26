#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "functions.h"
//#define TEST_MODE true        //Uncomment this to use program in test mode

int main (void)
{

    printf ("Square equation solver\n");
    printf ("a*x^2 + b*x + c = 0\n");

    #if TEST_MODE
        printf("Test mode:\n");
        SquareEquationTest();
    #else

        double a  = 0;
        double b  = 0;
        double c  = 0;
        double x1 = 0;
        double x2 = 0;

        Input (&a, &b, &c);
        int num_roots =  Square_solver (a, b, c, &x1, &x2);
        Output (num_roots, x1, x2);

    #endif

        return 0;
}
