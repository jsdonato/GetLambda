#include "Utility.hpp"

void initZSequence(mpz_t* const seq, const uint64_t& len) {
  for (uint64_t i = 0; i < len; ++i) {
    mpz_init(seq[i]);
  }
}

void clearZSequence(mpz_t* const seq, const uint64_t& len) {
  for (uint64_t i = 0; i < len; ++i) {
    mpz_clear(seq[i]);
  }
}

void initQSequence(mpq_t* const seq, const uint64_t& len) {
  for (uint64_t i = 0; i < len; ++i) {
    mpq_init(seq[i]);
  }
}

void clearQSequence(mpq_t* const seq, const uint64_t& len) {
  for (uint64_t i = 0; i < len; ++i) {
    mpq_clear(seq[i]);
  }
}

bool isZeroSequence(mpz_t* const seq, const uint64_t& len) {
  bool res = true;
  for (uint64_t i = 0; i < len; ++i) {
    res = res && (mpz_cmp_ui(seq[i], 0) == 0);
  }
  return res;
}

bool isZSequence(mpq_t* const seq, const uint64_t& len) {
  mpz_t denominator;
  mpz_init(denominator);
  bool res = true;
  for (uint64_t i = 0; i < len; ++i) {
    mpq_get_den(denominator, seq[i]);
    res = res && (mpz_cmp_ui(denominator, 1) == 0);
  }
  mpz_clear(denominator);
  return res;
}

bool isConstantZSequence(mpz_t* const seq, const uint64_t& len) {
  bool res = true;
  for (uint64_t i = 1; i < len; ++i) {
    res = res && (mpz_cmp(seq[i], seq[1]) == 0);
  }
  return res;
}

std::pair<uint64_t, int64_t> reduce(mpz_t* const seq, const uint64_t& len) {
  uint64_t counter = 0;
  uint64_t end = len;
  mpz_t seq_i_copy;
  mpz_init(seq_i_copy);
  while (!isConstantZSequence(seq, end)) {
    for (uint64_t i = 0; i < end - 1; ++i) {
      mpz_set(seq_i_copy, seq[i]);
      mpz_sub(seq[i], seq[i + 1], seq_i_copy);
    }
    ++counter;
    --end;
  }
  mpz_clear(seq_i_copy);
  return std::make_pair(counter, mpz_get_si(seq[0]));
}

void subtract(mpz_t* const seq, const uint64_t& len,
              const uint64_t& lambda,
              const uint64_t& start, const uint64_t& end,
              const PascalsTriangle& pt) {
  mpz_t b;
  mpz_t sum;
  mpz_t sum_copy;
  mpz_t seq_x_copy;
  mpz_init(b);
  mpz_init(sum);
  mpz_init(sum_copy);
  mpz_init(seq_x_copy);
  for (uint64_t x = 0; x < len; ++x) {
    mpz_set_ui(sum, 0);
    for (uint64_t i = start; i <= end; ++i) {
      pt.binomial(b, x + lambda - i, lambda - 1);
      mpz_set(sum_copy, sum);
      mpz_add(sum, b, sum_copy);
    }
    mpz_set(seq_x_copy, seq[x]);
    mpz_sub(seq[x], seq_x_copy, sum);
  }
  mpz_clear(b);
  mpz_clear(sum);
  mpz_clear(sum_copy);
  mpz_clear(seq_x_copy);
}
