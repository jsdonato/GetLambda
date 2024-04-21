#ifndef GETLAMBDA_HPP
#define GETLAMBDA_HPP

#include "Utility.hpp"
#include <vector>

std::vector<uint64_t> getLambdaFromSequence(mpz_t* const seq, const uint64_t& len);

std::vector<uint64_t> getLambdaFromPolynomial(const Polynomial& poly);


#endif
