#ifndef TERMINAL
#define TERMINAL

/**
@brief  Used to enter coefficients of square equation
@param[out] coefficient a of square equation
@param[out] coefficient b of square equation
@param[out] coefficient c of square equation
*/
void Input (double *a, double *b, double *c);

/**
@brief Used to write in command line number of roots and roots of equation
@param[in] number of roots of equation
@param[in] root one of equation (if exist)
@param[in] root two of equation (if exist)
*/
void Output (const int num_roots, const double x1, const double x2);

/**
@brief Used to clean buffer in command line while entering symbols
*/
void CleanBuffer(void);

/**
@brief Used to switch between test mode and calculating mode in program
@param[in] number of arguments of command line
@param[in] list of strings, which are arguments of command line
*/
void SwitchTestOrCalc(int argc, const char *argv[]);

#endif //Terminal.h
