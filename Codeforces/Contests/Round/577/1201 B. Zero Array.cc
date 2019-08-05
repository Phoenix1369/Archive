#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 1e5+5;
int a[MAXN];
int n;

int main() {
  scanf("%d", &n);
  lld ret = 0LL;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ret += a[i];
  }
  std::sort(a, a + n);
  bool nope = (2*a[n-1] > ret) || (ret & 1LL);
  puts(nope ? "NO" : "YES");
  return 0;
}
