#include <cstdio>
typedef long long lld;
lld X;

int main() {
  scanf("%lld", &X);
  int ret = 0;
  for (lld cur = 100; cur < X; cur = 1.01 * cur) ++ret;
  printf("%d\n", ret);
  return 0;
}
