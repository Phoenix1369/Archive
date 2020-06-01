#include <cstdio>
typedef long long lld;
const int BASE = 5;
const int LOGN = 26;
lld N;

lld solve() {
  if (N & 1) return 0;
  lld mul = 2;
  lld ret = 0LL;
  for (int i = 1; i <= LOGN; ++i) {
    mul *= BASE;
    ret += N / mul;
  }
  return ret;
}

int main() {
  scanf("%lld", &N);
  printf("%lld\n", solve());
  return 0;
}
