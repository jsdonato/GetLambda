#include "constants.hpp"
#include "gmp.h"
#include <stdlib.h>

constexpr uint64_t len = PASCALS_TRIANGLE_DEPTH * (PASCALS_TRIANGLE_DEPTH + 1) / 2;

inline uint64_t getIndex(const uint64_t& n, const uint64_t& k);

struct PascalsTriangle {
public:
  PascalsTriangle();

  void binomial(mpz_t res, const int64_t& n, const uint64_t& k);

private:
  mpz_t data[len];
};
