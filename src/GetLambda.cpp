#include "GetLambda.hpp"

std::vector<uint64_t> getLambdaFromSequence(mpz_t* const seq, const uint64_t& len) {
  std::vector<uint64_t> res;
  uint64_t s, e;

  while (!isZeroZSequence(seq, len)) {
  
  }

  return res;
}

std::vector<uint64_t> getLambdaFromPolynomial(const Polynomial& poly) {
  uint64_t degree = poly.getDegree();

  mpq_t* const q_seq = (mpq_t *)malloc(sizeof(mpq_t) * (degree + 1));
  initQSequence(q_seq, degree + 1);

  for (uint64_t i = 0; i < degree + 1; ++i) {
    poly.eval(q_seq[i], i);
  }

  if (!isZSequence(q_seq, degree + 1)) {
    return {};
  }

  mpz_t* const z_seq = (mpz_t *)malloc(sizeof(mpz_t) * (degree + 1));
  initZSequence(z_seq, degree + 1);

  for (uint64_t i = 0; i < degree + 1; ++i) {
    mpq_get_num(z_seq[i], q_seq[i]);
  }

  clearQSequence(q_seq, degree + 1);
  free(q_seq);

  std::vector<uint64_t> res = getLambdaFromSequence(z_seq, degree + 1);

  clearZSequence(z_seq, degree + 1);
  free(z_seq);

  return res;
}
