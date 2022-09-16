#ifndef CALCULATIONS
#define CALCULATIONS

#include <TXLib.h>

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

#include "Tests.h"
#include "Terminal.h"

#define REDCONSOLE   txSetConsoleAttr(FOREGROUND_RED)
#define WHITECONSOLE txSetConsoleAttr(FOREGROUND_WHITE)
#define GREENCONSOLE txSetConsoleAttr(FOREGROUND_GREEN)

/**
@brief Used to solve square equation of the form a * x^2 + bx + c = 0
@param[in] coefficient a of square equation
@param[in] coefficient b of square equation
@param[in] coefficient c of square equation
@param[out] first root of square equation (if exist)
@param[out] second root of square equation (if exist)
@return Number of roots of square equation
*/
int Square_solver (const double a, const double b, const double c, double *x1, double *x2);

/**
@brief Used to solve linear equation of the form kx + b = 0
@param[in] coefficient k of linear equation
@param[in] coefficient b of equation
@param[out] root of equation (if exist)
@return Number of roots of linear equation
*/
int Linear_solver (const double k, const double b, double *x);

/**
@brief Used to calculate discriminant of equation of the form /f$(a * x^2)/f$ + bx + c = 0
@param[in] coefficient a of square equation
@param[in] coefficient b of square equation
@param[in] coefficient c of square equation
@return discriminant of square equation
*/
double Calculate_discriminant (const double a, const double b, const double c);

/**
@brief Used to compare two double numbers
@param[in] first number to compare
@param[in] second number to compare with first
@return Result of comparing: C_EQUAL, C_LESS OR C_MORE
*/
int Compare (const double n1, const double n2);

/**
@brief Used to assign numerical values to the written result of compare function
*/
enum comp {
    C_MORE  = 1,    /// <is assigned the value 1 to result more of comparison
    C_EQUAL = 0,    /// <is assigned the value 0 to result equal of comparison
    C_LESS  = -1    /// <is assigned the value -1 to result less of comparison
};

/**
@brief Used to assign numerical values to the number of roots of equation
*/
enum roots {
    INF_ROOTS  = -1,    /// <is assigned the value -1 to an infinity number of roots
    ZERO_ROOTS = 0,     /// <is assigned the value 0 to zero roots
    ONE_ROOT   = 1,     /// <is assigned the value 1 to one root
    TWO_ROOTS  = 2,     /// <is assigned the value 2 to two roots
    WRONG      = 7      /// <is assigned the value 7 to something wrong
};

#endif //Calculations.h
