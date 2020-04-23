#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 2e5+5;
int A[MAXN];
int N, T;
lld ret;

int sgn(int x) {
  return (x > 0) - (x < 0);
}

void solve() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  ret = 0LL;
  int best = A[0];
  for (int i = 1; i < N; ++i) {
    if (sgn(A[i]) != sgn(best)) {
      ret += best;
      best = A[i];
    } else {
      best = std::max(A[i], best);
    }
  }
  ret += best;
  printf("%lld\n", ret);
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
