#include "Polynomial.hpp"

Polynomial::Polynomial(const uint64_t& num_terms_) :
  num_terms(num_terms_),
  coefficients((mpq_t*)malloc(sizeof(mpq_t) * num_terms)),
  degrees((uint64_t*)malloc(sizeof(uint64_t) * num_terms)) {}

