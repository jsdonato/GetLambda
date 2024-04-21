#ifndef PASCAL_HPP
#define PASCAL_HPP

#include "Pascal.hpp"
#include "Polynomial.hpp"
#include <utility>

void initZSequence(mpz_t* const seq, const uint64_t& len);

void clearZSequence(mpz_t* const seq, const uint64_t& len);

void initQSequence(mpq_t* const seq, const uint64_t& len);

void clearQSequence(mpq_t* const seq, const uint64_t& len);

bool isZeroSequence(mpz_t* const seq, const uint64_t& len);

bool isZSequence(mpq_t* const seq, const uint64_t& len);

bool isConstantZSequence(mpz_t* const seq, const uint64_t& len);

std::pair<uint64_t, int64_t> reduce(mpz_t* const seq, const uint64_t& len);

void subtract(mpz_t* const seq, const uint64_t& len,
              const uint64_t& lambda,
              const uint64_t& start, const uint64_t& end);


#endif
