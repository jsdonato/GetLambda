#include "tests.hpp"

#undef NUM_TESTS
#define NUM_TESTS 4

int main() {
  int tests[NUM_TESTS];

  tests[0] = testPascal();
  tests[1] = testPolynomial();
  tests[2] = testUtility();
  tests[3] = testGetLambda();

  for (int i = 0; i < NUM_TESTS; ++i) {
    if (tests[i] == EXIT_FAILURE) {
      return 1;
    }
  }

  return 0;
}
