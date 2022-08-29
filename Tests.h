/**
@brief Used to test program solving square equation using test data from file
@param[in] name of file with tests
*/
void SquareEquationTest(const char * name_test_file);

/**
@brief Used to do one iteration of test
@param[in] coefficient a of square equation
@param[in] coefficient b of square equation
@param[in] coefficient c of square equation
@param[in] number of roots of square equation
@param[out] calculated first  root of square equation
@param[out] calculated second root of square equation
@param[in] first  root of equation from file with tests
@param[in] second root of equation from file with tests
@return result of test: true if test ok, false if test error
*/
int OneTest(const double a, const double b, const double c, const int num_roots,
            double * x1, double * x2, const double righxtx1, const double rightx2);

