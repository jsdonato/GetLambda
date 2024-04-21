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
  return res;
}
