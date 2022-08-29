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

