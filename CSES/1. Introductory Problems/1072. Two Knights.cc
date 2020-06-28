#include <cstdio>
typedef long long lld;
int n;

lld all(lld k) { return 1LL * k * (k-1) / 2; }
lld sqr(int k) { return 1LL * k * k; }

lld cnt(int k) {
  if (k <= 2) return 0;
  if (k == 3) return 16;
  return ((2 + 4) * 4) + (3 * 8) +
    ((4 + 6) * (k-4) * 4LL) + (8LL * sqr(k-4));
}

lld solve(int k) {
  return all(sqr(k)) - cnt(k) / 2;
}

int main() {
  scanf("%d", &n);
  for (int k = 1; k <= n; ++k) {
    printf("%lld\n", solve(k));
  }
  return 0;
}
