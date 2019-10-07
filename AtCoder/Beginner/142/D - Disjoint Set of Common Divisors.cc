#include <cmath>
#include <cstdio>
typedef long long lld;
lld A, B;

template <typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int main() {
  scanf(" %lld%lld", &A, &B);
  lld G = gcd(A, B);
  lld S = sqrt(G);
  int ret = 1;
  for (int i = 2; i <= S; ++i) {
    if (G % i) continue;
    while ((G % i) == 0) {
      G /= i;
    }
    ++ret;
  }
  if (G > 1) ++ret;
  printf("%d\n", ret);
  return 0;
}
