#include <cstdio>
typedef long long lld;
int a, n;

lld sum(int n) { return 1LL * n * (n+1) / 2; }

int main() {
  scanf("%d", &n);
  lld cur = 0;
  for (int i = 1; i < n; ++i) {
    scanf("%d", &a);
    cur += a;
  }
  printf("%lld\n", sum(n) - cur);
  return 0;
}
