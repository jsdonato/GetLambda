#include "gmp.h"
#include <stdint.h>
#include <stdlib.h>

struct Polynomial {
public:
  Polynomial(const uint64_t& num_terms_);

  void setCoefficient(const uint64_t& i, const char* str);

  void setDegree(const uint64_t& i, const uint64_t& d);

  void eval(mpq_t res, const uint64_t& x);

private:
  const uint64_t num_terms;
  mpq_t* const coefficients;
  uint64_t* const degrees;
};
