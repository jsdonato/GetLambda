#include "Polynomial.hpp"

Polynomial::Polynomial(const uint64_t& degree_) {
  degree = degree_;
  coefficients = (mpq_t*)malloc(sizeof(mpq_t) * (degree + 1));
  for (uint64_t i = 0; i <= degree; ++i) {
    mpq_init(coefficients[i]);
  }
}

void Polynomial::reInit(const uint64_t& degree_) {
  for (uint64_t d = 0; d <= degree; ++d) {
    mpq_clear(coefficients[d]);
  }
  free(coefficients);
  coefficients = (mpq_t*)malloc(sizeof(mpq_t) * (degree_ + 1));
  for (uint64_t d = 0; d <= degree_; ++d) {
    mpq_init(coefficients[d]);
  }
  degree = degree_;
}

void Polynomial::setCoefficient(const uint64_t& d, const char* str) {
  mpq_set_str(coefficients[d], str, 0);
  mpq_canonicalize(coefficients[d]);
}

void Polynomial::eval(mpq_t res, const uint64_t& x) const {
  mpq_clear(res);
  mpq_init(res);

  mpq_t prod;
  mpq_t sum;
  mpq_t mpq_x;

  mpq_init(prod);
  mpq_init(sum);
  mpq_init(mpq_x);

  mpq_set_ui(mpq_x, x, 1);

  for (int d = degree; d >= 0; --d) {
    mpq_mul(prod, mpq_x, res);
    mpq_canonicalize(prod);
    mpq_add(sum, coefficients[d], prod);
    mpq_canonicalize(sum);
    mpq_set(res, sum);
    mpq_canonicalize(res);
  }

  mpq_clear(prod);
  mpq_clear(sum);
  mpq_clear(mpq_x);
}

Polynomial::~Polynomial() {
  for (uint64_t d = 0; d <= degree; ++d) {
    mpq_clear(coefficients[d]);
  }
  free(coefficients);
}
