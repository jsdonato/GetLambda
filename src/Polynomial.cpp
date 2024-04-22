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

void Polynomial::eval(mpq_t res, const uint64_t& x) const {
  mpz_t pow_x_d;
  mpz_t numerator;
  mpz_t denominator;
  mpz_t new_numerator;
  mpq_t summand;
  mpq_t res_copy;
  mpz_init(pow_x_d);
  mpz_init(numerator);
  mpz_init(denominator);
  mpz_init(new_numerator);
  mpq_init(summand);
  mpq_init(res_copy);

  for (uint64_t i = 0 ; i < num_terms; ++i) {
    mpz_ui_pow_ui(pow_x_d, x, degrees[i]);

    mpq_get_num(numerator, coefficients[i]);
    mpq_get_den(denominator, coefficients[i]);

    mpz_mul(new_numerator, numerator, pow_x_d);

    mpq_set_num(summand, new_numerator);
    mpq_set_den(summand, denominator);
    mpq_canonicalize(summand);

    mpq_set(res_copy, res);
    mpq_add(res, res_copy, summand);

    mpq_canonicalize(res);
  }

  mpz_clear(pow_x_d);
  mpz_clear(numerator);
  mpz_clear(denominator);
  mpz_clear(new_numerator);
  mpq_clear(summand);
  mpq_clear(res_copy);
}

void Polynomial::destroy() {
  for (uint64_t i = 0; i < num_terms; ++i) {
    mpq_clear(coefficients[i]);
  }
  free(coefficients);
  free(degrees);
}
