#include "gmp.h"
#include <stdint.h>
#include <stdlib.h>
#include <algorithm>

struct Polynomial {
public:
  Polynomial(const uint64_t& num_terms_);

  void reInit(const uint64_t& num_terms_);

  void setCoefficient(const uint64_t& i, const char* str);

  void setDegree(const uint64_t& i, const uint64_t& d);

  inline uint64_t getDegree();

  void eval(mpq_t res, const uint64_t& x);

private:
  uint64_t degree;
  uint64_t num_terms;
  mpq_t* coefficients;
  uint64_t*  degrees;
};
