#include <cmath>
#include <cstdio>
typedef long long lld;
const int MAXN = 4e5+5;
lld A;
int N;

template <typename T> T gcd(T a, T b) { return (b) ? gcd(b, a % b) : a; }

int main() {
  scanf("%d", &N);
  lld G = 0LL;
  for (int i = 1; i <= N; ++i) {
    scanf("%lld", &A);
    G = gcd(A, G);
  }
  int ret = 0;
  int sqrtG = sqrt(G);
  for (int i = 1; i <= sqrtG; ++i) {
    if ((G % i) != 0) continue;
    if ((G / i) != i) ++ret;
    ++ret;
  }
  printf("%d\n", ret);
  return 0;
}
