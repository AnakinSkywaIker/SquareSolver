#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "Terminal.h"
#include "Tests.h"
#include "Calculations.h"
//#define TEST_MODE         //Uncomment this to use program in test mode

int main (int argc, const char* argv[])
{
    printf ("Square equation solver\n");
    printf ("a*x^2 + b*x + c = 0\n");

    TestCalcSwitch(argc, argv);

    return 0;
}
