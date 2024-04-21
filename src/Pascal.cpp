#include "Pascal.hpp"

inline uint64_t getIndex(const uint64_t& n, const uint64_t& k) {
  return (n * (n + 1) / 2) + k;
}

PascalsTriangle::PascalsTriangle() {
  for (uint64_t i = 0; i < len; ++i) {
    mpz_init(data[i]);
  }

  mpz_set_ui(data[0], 1);
  mpz_set_ui(data[1], 1);
  mpz_set_ui(data[2], 1);

  for (uint64_t n = 2; n < PASCALS_TRIANGLE_DEPTH; ++n) {
    for (uint64_t k = 0; k <= n; ++k) {
      mpz_add(data[getIndex(n, k)], data[getIndex(n - 1, k - 1)], data[getIndex(n - 1, k)]);
    }
  }
}

void PascalsTriangle::binomial(mpz_t res, const int64_t& n, const uint64_t& k) const {
  if (n >= 0) {
    if (n < k) {
      mpz_set_ui(res, 0);
    }
    else {
      mpz_set(res, data[getIndex(n, k)]);
    }
  }
  else {
    uint64_t n_ = abs(n) + k - 1;
    int64_t coef = k % 2 == 0 ? 1 : -1;
    mpz_mul_si(res, data[getIndex(n_, k)], coef);
  }
}

void PascalsTriangle::destroy() {
  for (uint64_t i = 0; i < len; ++i) {
    mpz_clear(data[i]);
  }
}
