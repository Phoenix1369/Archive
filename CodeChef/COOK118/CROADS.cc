#include <cstdio>
typedef long long lld;
int N, T;

lld solve() {
  int lsb = (N & -N);
  if (lsb == N) {
    return -1;
  }
  lld ret = 0LL;
  for (int k = 0; (1 << k) <= N; ++k) {
    int cnt = (N + (1 << k)) / (1 << (k+1));
    ret += (1LL << k) * (cnt - 1);
    if (k) ret += (1 << k);
  }
  return ret;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    printf("%lld\n", solve());
  }
  return 0;
}
