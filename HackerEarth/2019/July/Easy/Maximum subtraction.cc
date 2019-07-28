#include <cstdio>
typedef long long lld;
int k, m, n;

lld sum(int n) { return 1LL * n * (n+1) / 2; }

int main() {
  scanf(" %d%d%d", &n, &m, &k);
  k = m - k - 1;
  lld ms = sum(m);
  lld ks = sum(k);

  // Bulk K-loop
  int ret = n / (ms - ks) * (m - k);
  n %= (ms - ks);

  // Remainder
  int lo = k;
  int hi = m;
  while (lo < hi) {
    int ce = (lo + hi + 1) / 2;
    if (1LL * n + sum(ce) < ms) {
      lo = ce;
    } else {
      hi = ce - 1;
    }
  }
  ret += (m - lo);
  printf("%d\n", ret);
  return 0;
}
