#include "Pascal.hpp"

inline uint64_t getIndex(const uint64_t& n, const uint64_t& k) {
  return (n * (n + 1) / 2) + k;
}

PascalsTriangle::PascalsTriangle() {
  
}
