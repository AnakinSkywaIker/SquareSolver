/**
@brief Used to solve square equation of the form ax^2 + bx + c = 0
@param[in] coefficient a
@param[in] coefficient b
@param[in] coefficient c
@param[out] first root
@param[out] second root
@return Number of roots
*/
int Square_solver (const double a, const double b, const double c, double *x1, double *x2);

/**
@brief Used to solve linear equation of the form kx + b = 0
@param[in] coefficient k
@param[in] coefficient b
@param[out] root of equation
@return Number of roots
*/
int Linear_solver (const double k, const double b, double *x);

/**
@brief  Used to enter coefficients of square equation
@param[out] coefficient a
@param[out] coefficient b
@param[out] coefficient c
*/
void Input (double * a, double * b, double * c);

/**
@brief Used to write number of roots and roots of equation
@param[in] number of roots
@param[in] root one (if exist)
@param[in] root two (if exist)
*/
void Output (const int num_roots, const double x1, const double x2);

/**
@brief Used to calculate discriminant of equation of the form ax^2 + bx + c = 0
@param[in] coefficient a
@param[in] coefficient b
@param[in] coefficient c
@return discriminant
*/
double Calculate_discriminant (const double a, const double b, const double c);

/**
@brief Used to compare two double numbers
@param[in] first number
@param[in] second number
@return Result of comparing: C_EQUAL, C_LESS OR C_MORE
*/
int Compare (const double n1, const double n2);

/**
@brief Used to test program solving square equation using test data from file
*/
void SquareEquationTest(void);

/**
@brief Used to do one iteration of test file
@param[in] coefficient a
@param[in] coefficient b
@param[in] coefficient c
@param[in] number of roots
@param[out] calculated first root
@param[out] calculated second root
@param[in] first root from file with tests
@param[in] second root from file with tests
@return result of test: true if test ok, false if test error
*/
int OneTest(const double a, const double b, const double c, const int num_roots,
            double * x1, double * x2, const double righxtx1, const double rightx2);

/**
@brief Used to assign numerical values to the result of compare function
*/
enum comp {
    C_MORE  = 1,    /// <is assigned the value 1
    C_EQUAL = 0,    /// <is assigned the value 0
    C_LESS  = -1    /// <is assigned the value -1
};

/**
@brief Used to assign numerical values to the number of roots
*/
enum roots {
    INF_ROOTS  = -1,    /// <is assigned the value -1
    ZERO_ROOTS = 0,     /// <is assigned the value 0
    ONE_ROOT   = 1,     /// <is assigned the value 1
    TWO_ROOTS  = 2,     /// <is assigned the value 2
    WRONG      = 7      /// <is assigned the value 7
};
