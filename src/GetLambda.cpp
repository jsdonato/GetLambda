#include "GetLambda.hpp"

std::vector<uint64_t> getLambdaFromSequence(mpz_t* const seq, const uint64_t& len, const PascalsTriangle& pt) {
  std::vector<uint64_t> res;
  mpz_t* const seq_copy = (mpz_t *)malloc(sizeof(mpz_t) * len);
  uint64_t s = 1;
  uint64_t e;

  while (!isZeroZSequence(seq, len)) {
    copyZSequence(seq_copy, seq, len);
    std::pair<uint64_t, int64_t> reduce_res = reduce(seq_copy, len);
    if (reduce_res.second < 0) {
      clearZSequence(seq_copy, len);
      free(seq_copy);
      return {};
    }
    res.insert(res.end(), reduce_res.second, reduce_res.first + 1);
    e = s + reduce_res.second - 1;
    subtract(seq, len, reduce_res.first + 1, s, e, pt);
    s = s + reduce_res.second;
  }
  clearZSequence(seq_copy, len);
  free(seq_copy);
  return res;
}

std::vector<uint64_t> getLambdaFromPolynomial(const Polynomial& poly, const PascalsTriangle& pt) {
  uint64_t degree = poly.getDegree();

  mpq_t* const q_seq = (mpq_t *)malloc(sizeof(mpq_t) * (degree + 1));
  initQSequence(q_seq, degree + 1);

  for (uint64_t i = 0; i < degree + 1; ++i) {
    poly.eval(q_seq[i], i);
  }

  if (!isZSequence(q_seq, degree + 1)) {
    clearQSequence(q_seq, degree + 1);
    free(q_seq);
    return {};
  }

  mpz_t* const z_seq = (mpz_t *)malloc(sizeof(mpz_t) * (degree + 1));
  initZSequence(z_seq, degree + 1);

  for (uint64_t i = 0; i < degree + 1; ++i) {
    mpq_get_num(z_seq[i], q_seq[i]);
  }

  clearQSequence(q_seq, degree + 1);
  free(q_seq);

  std::vector<uint64_t> res = getLambdaFromSequence(z_seq, degree + 1, pt);

  clearZSequence(z_seq, degree + 1);
  free(z_seq);

  return res;
}
