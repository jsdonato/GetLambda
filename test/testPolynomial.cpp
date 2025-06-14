#include "tests.hpp"

int testPolynomial() {
  fprintf(stderr, "=== BEGIN testPolynomial ===\n");

  Polynomial poly(5);
  mpq_t num;
  mpq_init(num);
  mpq_t comp;
  mpq_init(comp);

  // TEST 1
  poly.setCoefficient(0, "5");
  poly.setCoefficient(4, "20/30");
  poly.setCoefficient(5, "3/5");

  poly.eval(num, 50);
  mpq_set_str(comp, "575000015/3", 0);

  ASSERT_TRUE(mpq_cmp(num, comp) == 0);
  ASSERT_TRUE(poly.getDegree() == 5);
  // TEST 2
  poly.reInit(99);

  poly.setCoefficient(51, "3000/9015");
  poly.setCoefficient(99, "12/300");

  poly.eval(num, 3);
  mpq_set_str(comp, "103247296653312936650981814799528172753487093975867/15025", 0);

  ASSERT_TRUE(mpq_cmp(num, comp) == 0);
  ASSERT_TRUE(poly.getDegree() == 99);
  // TEST 3
  poly.reInit(31);

  poly.setCoefficient(3, "40");
  poly.setCoefficient(20, "10");
  poly.setCoefficient(31, "7");

  poly.eval(num, 20);

  mpq_set_str(comp, "150323855360001048576000000000000000320000/1", 0);

  ASSERT_TRUE(mpq_cmp(num, comp) == 0);
  ASSERT_TRUE(poly.getDegree() == 31);

  mpq_clear(num);
  mpq_clear(comp);

  fprintf(stderr, "=== END testPolynomial ===\n");
  return EXIT_SUCCESS;
}
