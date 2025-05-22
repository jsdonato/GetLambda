#ifndef TESTS_HPP
#define TESTS_HPP

#include <assert.h>
#include "Pascal.hpp"
#include "Polynomial.hpp"
#include "Utility.hpp"
#include "GetLambda.hpp"

#define ASSERT_TRUE(b) { \
  if (!(b)) { \
    fprintf(stderr, "FAIL: in file %s on line %d\n", __FILE__, __LINE__); \
    return EXIT_FAILURE; \
  } \
} \

int testPascal();
int testPolynomial();
int testUtility();
int testGetLambda();

#endif
