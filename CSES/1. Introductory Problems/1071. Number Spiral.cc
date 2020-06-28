#include <cstdio>
typedef long long lld;
int T, x, y;

lld sqr(int x) { return 1LL * x * x; }

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf(" %d%d", &y, &x);
    if (y > x) {
      if (y & 1) {
        printf("%lld\n", sqr(y-1) + (x));
      } else {
        printf("%lld\n", sqr(y) - (x-1));
      }
    } else {
      if (x & 1) {
        printf("%lld\n", sqr(x) - (y-1));
      } else {
        printf("%lld\n", sqr(x-1) + (y));
      }
    }
  }
  return 0;
}
