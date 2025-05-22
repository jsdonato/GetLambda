#include "tests.hpp"

int testUtility() {
  fprintf(stderr, "=== BEGIN testUtility ===\n");

  mpq_t* seq_q = (mpq_t *)malloc(3 * sizeof(mpq_t));

  // TEST 1
  initQSequence(seq_q, 3);
  for (uint64_t i = 0; i < 3; ++i) {
    mpq_set_ui(seq_q[i], i + 1, i + 2);
  }
  ASSERT_TRUE(mpq_cmp_ui(seq_q[0], 1, 2) == 0);
  ASSERT_TRUE(mpq_cmp_ui(seq_q[1], 2, 3) == 0);
  ASSERT_TRUE(mpq_cmp_ui(seq_q[2], 3, 4) == 0);
  clearQSequence(seq_q, 3);
  free(seq_q);

  mpz_t* seq_z = (mpz_t *)malloc(4 * sizeof(mpz_t));

  // TEST 2
  initZSequence(seq_z, 4);
  for (uint64_t i = 0; i < 4; ++i) {
    mpz_set_si(seq_z[i], i - 9);
  }
  ASSERT_TRUE(mpz_cmp_si(seq_z[0], -9) == 0);
  ASSERT_TRUE(mpz_cmp_si(seq_z[1], -8) == 0);
  ASSERT_TRUE(mpz_cmp_si(seq_z[2], -7) == 0);
  ASSERT_TRUE(mpz_cmp_si(seq_z[3], -6) == 0);
  clearZSequence(seq_z, 4);
  free(seq_z);

  // TEST 3
  seq_z = (mpz_t *)malloc(4 * sizeof(mpz_t));
  initZSequence(seq_z, 4);

  mpz_set_si(seq_z[0], 0);
  mpz_set_si(seq_z[1], -1);
  mpz_set_si(seq_z[2], 0);
  mpz_set_si(seq_z[3], 0);

  ASSERT_TRUE(!isZeroZSequence(seq_z, 4));

  mpz_set_si(seq_z[0], 0);
  mpz_set_si(seq_z[1], 0);
  mpz_set_si(seq_z[2], 0);
  mpz_set_si(seq_z[3], 0);

  ASSERT_TRUE(isZeroZSequence(seq_z, 4));

  clearZSequence(seq_z, 4);
  free(seq_z);

  //TEST 4
  seq_q  = (mpq_t *)malloc(3 * sizeof(mpq_t));
  initQSequence(seq_q, 3);

  mpq_set_ui(seq_q[0], 2, 3);
  mpq_set_ui(seq_q[1], 3, 1);
  mpq_set_ui(seq_q[2], 5, 1);

  ASSERT_TRUE(!isZSequence(seq_q, 3));

  mpq_set_ui(seq_q[0], 1010, 1);
  mpq_set_ui(seq_q[1], 91, 1);
  mpq_set_ui(seq_q[2], 80, 1);

  ASSERT_TRUE(isZSequence(seq_q, 3));

  clearQSequence(seq_q, 3);
  free(seq_q);

  // TEST 5
  seq_z = (mpz_t *)malloc(4 * sizeof(mpz_t));

  mpz_set_si(seq_z[0], -5);
  mpz_set_si(seq_z[1], 3);
  mpz_set_si(seq_z[2], -5);
  mpz_set_si(seq_z[3], 3);

  ASSERT_TRUE(!isConstantZSequence(seq_z, 4));

  mpz_set_si(seq_z[0], 99);
  mpz_set_si(seq_z[1], 99);
  mpz_set_si(seq_z[2], 99);
  mpz_set_si(seq_z[3], 99);

  ASSERT_TRUE(isConstantZSequence(seq_z, 4));

  clearZSequence(seq_z, 4);
  free(seq_z);

  // TEST 6
  seq_z = (mpz_t *)malloc(3 * sizeof(mpz_t));
  mpz_t* seq_z_temp = (mpz_t *)malloc(3 * sizeof(mpz_t));
  initZSequence(seq_z, 3);
  initZSequence(seq_z_temp, 3);

  mpz_set_si(seq_z[0], -20);
  mpz_set_si(seq_z[1], 10);
  mpz_set_si(seq_z[2], -5);

  copyZSequence(seq_z_temp, seq_z, 3);

  ASSERT_TRUE(mpz_cmp_si(seq_z_temp[0], -20) == 0);
  ASSERT_TRUE(mpz_cmp_si(seq_z_temp[1], 10) == 0);
  ASSERT_TRUE(mpz_cmp_si(seq_z_temp[2], -5) == 0);

  clearZSequence(seq_z, 3);
  clearZSequence(seq_z_temp, 3);
  free(seq_z);
  free(seq_z_temp);

  // TEST 7
  seq_z = (mpz_t *)malloc(4 * sizeof(mpz_t));
  initZSequence(seq_z, 4);

  mpz_set_si(seq_z[0], -10);
  mpz_set_si(seq_z[1], -50);
  mpz_set_si(seq_z[2], -370);
  mpz_set_si(seq_z[3], -1270);

  std::pair<uint64_t, int64_t> reduce_res;
  reduce_res = reduce(seq_z, 4);

  ASSERT_TRUE(reduce_res.first == 3);
  ASSERT_TRUE(reduce_res.second == -300);

  mpz_set_si(seq_z[0], 10);
  mpz_set_si(seq_z[1], 10);
  mpz_set_si(seq_z[2], 10);
  mpz_set_si(seq_z[3], 10);

  reduce_res = reduce(seq_z, 4);

  ASSERT_TRUE(reduce_res.first == 0);
  ASSERT_TRUE(reduce_res.second == 10);

  clearZSequence(seq_z, 4);
  free(seq_z);

  // TEST 8
  PascalsTriangle pt;
  seq_z = (mpz_t *)malloc(5 * sizeof(mpz_t));
  initZSequence(seq_z, 5);

  mpz_set_si(seq_z[0], -101);
  mpz_set_si(seq_z[1], 2034);
  mpz_set_si(seq_z[2], 200);
  mpz_set_si(seq_z[3], -371);
  mpz_set_si(seq_z[4], 5);

  subtract(seq_z, 5,
           7, 20, 31, pt);

  ASSERT_TRUE(mpz_cmp_si(seq_z[0], -2004077) == 0);
  ASSERT_TRUE(mpz_cmp_si(seq_z[1], -1539298) == 0);
  ASSERT_TRUE(mpz_cmp_si(seq_z[2], -1172400) == 0);
  ASSERT_TRUE(mpz_cmp_si(seq_z[3], -881966) == 0);
  ASSERT_TRUE(mpz_cmp_si(seq_z[4], -654363) == 0);

  clearZSequence(seq_z, 5);
  free(seq_z);

  fprintf(stderr, "=== END testUtility ===\n");
  return EXIT_SUCCESS;
}
