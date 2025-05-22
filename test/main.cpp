#include "tests.hpp"

int main() {
  const int num_tests = 4;
  int tests[num_tests];

  tests[0] = testPascal();
  tests[1] = testPolynomial();
  tests[2] = testUtility();
  tests[3] = testGetLambda();

  for (int i = 0; i < num_tests; ++i) {
    if (tests[i] == EXIT_FAILURE) {
      return 1;
    }
  }

  return 0;
}
