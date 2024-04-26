#include "tests.hpp"

void testPolynomial() {
  Polynomial poly(3);
  mpq_t num;
  mpq_init(num);
  mpq_t comp;
  mpq_init(comp);

  // TEST 1
  poly.setDegree(0, 0);
  poly.setDegree(1, 4);
  poly.setDegree(2, 5);

  poly.setCoefficient(0, "5");
  poly.setCoefficient(1, "20/30");
  poly.setCoefficient(2, "3/5");

  poly.eval(num, 50);

  mpq_set_str(comp, "575000015/3", 0);

  assert(mpq_cmp(num, comp) == 0);
  assert(poly.getDegree() == 5);

  // TEST 2
  poly.reInit(2);

  poly.setDegree(0, 51);
  poly.setDegree(1, 99);

  poly.setCoefficient(0, "3000/9015");
  poly.setCoefficient(1, "12/300");

  poly.eval(num, 3);

  mpq_set_str(comp, "103247296653312936650981814799528172753487093975867/15025", 0);

  assert(mpq_cmp(num, comp) == 0);
  assert(poly.getDegree() == 99);

  poly.destroy();
}
