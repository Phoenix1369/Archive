#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 2e5+5;
int a[MAXN];
int k, n;

int solve() {
  int M = n/2;
  for (int i = M+1; i < n; ++i) {
    lld delta = 1LL * (i - M) * (a[i] - a[i-1]);
    if (delta > k) {
      return a[i-1] + k / (i - M);
    }
    k -= delta;
  }
  return a[n-1] + k / (n - M);
}

int main() {
  scanf(" %d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a, a + n);
  printf("%d\n", solve());
  return 0;
}
