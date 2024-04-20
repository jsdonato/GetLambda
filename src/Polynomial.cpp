#include "Polynomial.hpp"

Polynomial::Polynomial(const uint64_t& num_terms_) :
  degree(0),
  num_terms(num_terms_),
  coefficients((mpq_t*)malloc(sizeof(mpq_t) * num_terms)),
  degrees((uint64_t*)malloc(sizeof(uint64_t) * num_terms)) {
  memset(degrees, 0, sizeof(uint64_t) * num_terms);
  for (uint64_t i = 0; i < num_terms; ++i) {
    mpq_init(coefficients[i]);
  }
}

void Polynomial::reInit(const uint64_t& num_terms_) {
  for (uint64_t i = 0; i < num_terms; ++i) {
    mpq_clear(coefficients[i]);
  }
  num_terms = num_terms_;
  degree = 0;
  free(coefficients);
  free(degrees);
  coefficients = (mpq_t*)malloc(sizeof(mpq_t) * num_terms);
  degrees = (uint64_t*)malloc(sizeof(uint64_t) * num_terms);
  memset(degrees, 0, sizeof(uint64_t) * num_terms);
  for (uint64_t i = 0; i < num_terms; ++i) {
    mpq_init(coefficients[i]);
  }
}

void Polynomial::setCoefficient(const uint64_t& i, const char* str) {
  mpq_set_str(coefficients[i], str, 0);
  mpq_canonicalize(coefficients[i]);
}

void Polynomial::setDegree(const uint64_t& i, const uint64_t& d) {
  degree = std::max(d, degree);
  degrees[i] = d;
}

inline uint64_t Polynomial::getDegree() {
  return degree;
}

void Polynomial::eval(mpq_t res, const uint64_t& x) {
  
}
