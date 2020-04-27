#include <algorithm>
#include <cstdio>
typedef long long lld;
int a, b, x, y;
int T;

lld solve() {
  scanf(" %d%d%d%d", &x, &y, &a, &b);
  if (x < y) {
    std::swap(x, y);
  }
  return (a*2 <= b) ?
    1LL * a * (x + y) :
    1LL * a * (x - y) + 1LL * b * y;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    printf("%lld\n", solve());
  }
  return 0;
}
