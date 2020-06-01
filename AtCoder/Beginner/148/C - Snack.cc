#include <cstdio>
typedef long long lld;
int A, B;

template <typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
lld lcm(int a, int b) { return 1LL * a / gcd(a, b) * b; }

int main() {
  scanf(" %d%d", &A, &B);
  printf("%lld\n", lcm(A, B));
  return 0;
}
