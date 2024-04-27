#include "tests.hpp"

void testGetLambda() {
  PascalsTriangle pt;
  std::vector<uint64_t> res;
  std::vector<uint64_t> comp;
  Polynomial poly (3);

  // TEST 1
  poly.setDegree(0, 1);
  poly.setDegree(1, 4);
  poly.setDegree(2, 5);

  poly.setCoefficient(0, "2");
  poly.setCoefficient(1, "50/3");
  poly.setCoefficient(2, "2/3");

  res = getLambdaFromPolynomial(poly, pt);

  assert(res.empty());

  // TEST 2
  poly.reInit(10);

  poly.setDegree(0, 0);
  poly.setDegree(1, 1);
  poly.setDegree(2, 2);
  poly.setDegree(3, 3);
  poly.setDegree(4, 4);
  poly.setDegree(5, 5);
  poly.setDegree(6, 6);
  poly.setDegree(7, 7);
  poly.setDegree(8, 8);
  poly.setDegree(9, 9);

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

  assert(res.size() == comp.size());
  for (uint64_t i = 0; i < res.size(); ++i) {
    assert(res[i] == comp[i]);
  }

  poly.destroy();

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

  assert(res.size() == comp.size());
  for (uint64_t i = 0; i < res.size(); ++i) {
    assert(res[i] == comp[i]);
  }

  clearZSequence(seq_z, 9);
  free(seq_z);

  pt.destroy();
}
