#include <cstdio>
typedef long long lld;
const int LOGA = 60;
const int MAXN = 1e5+5;
int cnt[LOGA];
lld A[MAXN];
lld B[LOGA];
int N;

void augment_basis(lld vec) {
  for (int j = LOGA-1; j >= 0; --j) {
    if ((vec >> j) & 1) {
      if (B[j]) {
        vec ^= B[j]; // Subtract basis vector.
      } else {
        B[j] = vec;
        return;
      }
    }
  }
}

void init() {
  for (int j = 0; j < LOGA; ++j) {
    B[j] = cnt[j] = 0;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < LOGA; ++j) {
      if ((A[i] >> j) & 1) ++cnt[j];
    }
  }
}

// Greedily augment MSBs of basis vectors

lld max_xor() {
  lld sum = 0LL;
  for (int j = LOGA-1; j >= 0; --j) {
    if (!B[j]) continue;
    if ((sum >> j) & 1) continue;
    sum ^= B[j];
  }
  return sum;
}

// Bits of odd multiplicity contribute exactly once.

lld odd_bits() {
  lld sum = 0LL;
  for (int j = 0; j < LOGA; ++j) {
    if (cnt[j] & 1) {
      lld two = (1LL << j);
      for (int i = 0; i < N; ++i) {
        A[i] &= ~two;
      }
      sum |= two;
    }
  }
  return sum;
}

// Bits of even multiplicity contribute either zero or twice.

lld solve() {
  lld ret = odd_bits();
  for (int i = 0; i < N; ++i) {
    augment_basis(A[i]);
  }
  ret += max_xor() << 1;
  return ret;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld", &A[i]);
  }
  init();
  printf("%lld\n", solve());
  return 0;
}
