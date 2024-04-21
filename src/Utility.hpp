#ifndef PASCAL_HPP
#define PASCAL_HPP

#include "Pascal.hpp"
#include "Polynomial.hpp"

void initZSequence(mpz_t* const seq, const uint64_t& len);

void clearZSequence(mpz_t* const seq, const uint64_t& len);

void initQSequence(mpq_t* const seq, const uint64_t& len);

void clearQSequence(mpq_t* const seq, const uint64_t& len);

bool isZeroSequence(mpz_t* const seq, const uint64_t& len);

bool isZSequence(mpq_t* const seq, const uint64_t& len);




#endif
