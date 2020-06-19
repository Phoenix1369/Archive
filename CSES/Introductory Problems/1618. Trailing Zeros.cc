#include <cstdio>
typedef long long lld;
int n;

int main() {
  scanf("%d", &n);
  lld five = 5;
  int res = 0;
  while (five <= n) {
    res += n / five;
    five *= 5;
  }
  printf("%d\n", res);
  return 0;
}
