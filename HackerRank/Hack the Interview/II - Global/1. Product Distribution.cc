#include <algorithm>
#include <cstdio>
const int MAXN = 1e6+5;
const int MOD = 1e9+7;
int A[MAXN];
int M, N;

int solve() {
  std::sort(A, A+N);
  int rem = N % M;
  int ret = 0;
  for (int i = 0; i < N; ++i) {
    int mul = i / M;
    if (i + rem < N) ++mul;
    ret = (1LL * mul * A[i] % MOD + ret) % MOD;
  }
  return ret;
}

int main() {
  scanf(" %d%d", &N, &M);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  printf("%d\n", solve());
  return 0;
}
