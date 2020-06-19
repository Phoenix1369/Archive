#include <algorithm>
#include <cstdio>
#include <cstdlib>
typedef long long lld;
const int MAXN = 20;
int p[MAXN];
int n;

int main() {
  scanf("%d", &n);
  lld sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    sum += p[i];
  }
  int m = (1 << n);
  lld ret = sum;
  for (int mask = 1; mask < m; ++mask) {
    lld cur = 0;
    for (int bit = 0; bit < n; ++bit) {
      if ((mask >> bit) & 1) {
        cur += p[bit];
      }
    }
    lld val = std::llabs(sum - 2 * cur);
    ret = std::min(val, ret);
  } 
  printf("%lld\n", ret);
  return 0;
}
