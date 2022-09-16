#ifndef TESTS
#define TESTS

/**
@brief Used to test program solving square equation using test data from file
@param[in] name of file with tests
*/
void SquareEquationTest(const char *name_test_file);

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
int OneTest(struct TestData *DataForTest);

/**
@brief Used to give test data for test function in one structure
*/
struct TestData
{
    double a;         ///< coefficient a of square equation from file with test data
    double b;         ///< coefficient b of square equation from file with test data
    double c;         ///< coefficient c of square equation from file with test data
    int  num_roots;   ///< right number of roots from file with test data
    double *x1;       ///< pointer for function to write calculated x1 of square equation
    double *x2;       ///< pointer for function to write calculated x2 of square equation
    double rightx1;   ///< right value of x1 from file with test data
    double rightx2;   ///< right value of x2 from file with test data
};

#endif //Test.h
