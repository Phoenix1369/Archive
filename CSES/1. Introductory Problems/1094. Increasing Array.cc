#include <cstdio>
typedef long long lld;
int a, n, x;

int main() {
  scanf("%d", &n);
  scanf("%d", &x);
  lld ret = 0;
  for (int i = 1; i < n; ++i) {
    scanf("%d", &a);
    if (a < x) {
      ret += x - a;
    } else {
      x = a;
    }
  }
  printf("%lld\n", ret);
  return 0;
}
