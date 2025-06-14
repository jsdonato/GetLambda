#include "tests.hpp"

int testGetLambda() {
  fprintf(stderr, "=== BEGIN testGetLambda ===\n");

  PascalsTriangle pt;
  std::vector<uint64_t> res;
  std::vector<uint64_t> comp;
  Polynomial poly (5);

  // TEST 1
  poly.setCoefficient(1, "2");
  poly.setCoefficient(4, "50/3");
  poly.setCoefficient(5, "2/3");

  res = getLambdaFromPolynomial(poly, pt);

  ASSERT_TRUE(res.empty());

  // TEST 2
  poly.reInit(9);

  poly.setCoefficient(0, "4717440/362880");
  poly.setCoefficient(1, "-3920976/362880");
  poly.setCoefficient(2, "4791204/362880");
  poly.setCoefficient(3, "-489200/362880");
  poly.setCoefficient(4, "634095/362880");
  poly.setCoefficient(5, "53781/362880");
  poly.setCoefficient(6, "17766/362880");
  poly.setCoefficient(7, "1830/362880");
  poly.setCoefficient(8, "135/362880");
  poly.setCoefficient(9, "5/362880");

  res = getLambdaFromPolynomial(poly, pt);
  comp = {10, 10, 10, 10, 10, 7, 7, 7, 7, 1, 1, 1, 1};

  ASSERT_TRUE(res.size() == comp.size());
  for (uint64_t i = 0; i < res.size(); ++i) {
    ASSERT_TRUE(res[i] == comp[i]);
  }

  // TEST 3
  mpz_t* seq_z = (mpz_t *)malloc(9 * sizeof(mpz_t));
  initZSequence(seq_z, 9);

  mpz_set_si(seq_z[0], -30);
  mpz_set_si(seq_z[1], -12);
  mpz_set_si(seq_z[2], 37);
  mpz_set_si(seq_z[3], 205);
  mpz_set_si(seq_z[4], 703);
  mpz_set_si(seq_z[5], 1990);
  mpz_set_si(seq_z[6], 4972);
  mpz_set_si(seq_z[7], 11301);
  mpz_set_si(seq_z[8], 23804);

  res = getLambdaFromSequence(seq_z, 9, pt);
  comp = {9, 9, 9, 9, 6, 6, 6, 6, 2, 2, 2};

  ASSERT_TRUE(res.size() == comp.size());
  for (uint64_t i = 0; i < res.size(); ++i) {
    ASSERT_TRUE(res[i] == comp[i]);
  }

  clearZSequence(seq_z, 9);
  free(seq_z);

  fprintf(stderr, "=== END testGetLambda ===\n");
  return EXIT_SUCCESS;
}
