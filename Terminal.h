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
@brief Used to clean buffer in command line
*/
void CleanBuffer(void);

