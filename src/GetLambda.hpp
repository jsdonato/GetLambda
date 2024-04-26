#ifndef GETLAMBDA_HPP
#define GETLAMBDA_HPP

#include "Utility.hpp"
#include <vector>

std::vector<uint64_t> getLambdaFromSequence(mpz_t* const seq, const uint64_t& len, const PascalsTriangle& pt);

std::vector<uint64_t> getLambdaFromPolynomial(const Polynomial& poly, const PascalsTriangle& pt);


#endif
