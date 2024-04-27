#include <iostream>
#include "Pascal.hpp"

inline uint64_t getIndex(const uint64_t& n, const uint64_t& k) {
  return (n * (n + 1) / 2) + k;
}

PascalsTriangle::PascalsTriangle() {
  for (uint64_t i = 0; i < len; ++i) {
    mpz_init(data[i]);
  }

  if (PASCALS_TRIANGLE_DEPTH >= 1) {
    mpz_set_ui(data[0], 1);
  }
  if (PASCALS_TRIANGLE_DEPTH >= 2) {
    mpz_set_ui(data[1], 1);
    mpz_set_ui(data[2], 1);
  }

  for (uint64_t n = 2; n < PASCALS_TRIANGLE_DEPTH; ++n) {
    mpz_set_ui(data[getIndex(n, 0)], 1);
    mpz_set_ui(data[getIndex(n, n)], 1);
    for (uint64_t k = 1; k <= n - 1; ++k) {
      mpz_add(data[getIndex(n, k)], data[getIndex(n - 1, k - 1)], data[getIndex(n - 1, k)]);
    }
  }
}

void PascalsTriangle::binomial(mpz_t res, const int64_t& n, const uint64_t& k) const {
  if (n >= 0) {
    if (n >= PASCALS_TRIANGLE_DEPTH) {
      fprintf(stderr, "PASCALS_TRIANGLE_DEPTH not large enough for this problem.\n");
      exit(1);
    }
    if (n < k) {
      mpz_set_ui(res, 0);
    }
    else {
      mpz_set(res, data[getIndex(n, k)]);
    }
  }
  else {
    const uint64_t n_ = abs(n) + k - 1;
    if (n_ >= PASCALS_TRIANGLE_DEPTH) {
      fprintf(stderr, "PASCALS_TRIANGLE_DEPTH not large enough for this problem. \n");
      exit(1);
    }
    const int64_t coef = k % 2 == 0 ? 1 : -1;
    mpz_mul_si(res, data[getIndex(n_, k)], coef);
  }
}

PascalsTriangle::~PascalsTriangle() {
  for (uint64_t i = 0; i < len; ++i) {
    mpz_clear(data[i]);
  }
}
