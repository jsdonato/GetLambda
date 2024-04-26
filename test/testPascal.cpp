#include "tests.hpp"
#include <iostream>
void testPascal() {
  PascalsTriangle pt;

  mpz_t num;
  mpz_init(num);

  mpz_t comp;
  mpz_init(comp);

  // TEST 1
  pt.binomial(num, 40, 20);

  mpz_set_str(comp, "137846528820", 0);

  assert(mpz_cmp(num, comp) == 0);

  // TEST 2
  pt.binomial(num, 49, 60);

  mpz_set_str(comp, "0", 0);

  assert(mpz_cmp(num, comp) == 0);

  // TEST 3
  pt.binomial(num, 49, 49);

  mpz_set_str(comp, "1", 0);

  assert(mpz_cmp(num, comp) == 0);

  // TEST 4
  pt.binomial(num, -30, 15);

  mpz_set_str(comp, "-229911617056", 0);

  assert(mpz_cmp(num, comp) == 0);

  pt.destroy();
}
