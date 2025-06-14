#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include "gmp.h"
#include <stdint.h>
#include <stdlib.h>
#include <algorithm>

struct Polynomial {
public:
  Polynomial(const uint64_t& degree_);

  void reInit(const uint64_t& degree_);

  void setCoefficient(const uint64_t& d, const char* str);

  inline uint64_t getDegree() const { return degree; }

  void eval(mpq_t res, const uint64_t& x) const;

  ~Polynomial();

private:
  uint64_t degree;
  mpq_t* coefficients;
};

#endif
