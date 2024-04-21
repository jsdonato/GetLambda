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

bool isConstantZSequence(mpz_t* const seq, const uint64_t& len);

void reduce(mpz_t* const seq, const uint64_t& len);

void subtract(mpz_t* const seq, const uint64_t& len,
              const uint64_t& lambda,
              const uint64_t& start, const uint64_t& end);


#endif
