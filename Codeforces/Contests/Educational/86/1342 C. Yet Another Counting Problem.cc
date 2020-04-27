#include <algorithm>
#include <cstdio>
typedef long long lld;
int A, B, Q, T;
lld L, R;
int M;

template <typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

lld f(lld x) {
  lld K = x / M;
  lld y = (M - B) * K;
  int rem = x % M;
  if (rem >= B) {
    y += rem - B + 1;
  }
  return y;
}

lld solve() {
  return f(R) - f(L-1);
}

void testset() {
  scanf(" %d%d%d", &A, &B, &Q);
  if (A > B) {
    std::swap(A, B);
  }
  M = lcm(A, B);
  for (int q = 0; q < Q; ++q) {
    scanf(" %lld%lld", &L, &R);
    printf("%lld ", solve());
  }
  putchar('\n');
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    testset();
  }
  return 0;
}
