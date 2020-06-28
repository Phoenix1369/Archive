#include <cstdio>
const int MOD = 1e9+7;
int n;

int main() {
  scanf("%d", &n);
  int res = 1;
  for (int i = 0; i < n; ++i) {
    res = 2LL * res % MOD;
  }
  printf("%d\n", res);
  return 0;
}
