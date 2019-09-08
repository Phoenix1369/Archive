#include <cstdio>
const int MAXN = 2005;
const int MOD = 1e9+7;
int bc[MAXN][MAXN];
int K, N;
int N1;

void init() {
  int end = N + 1;
  bc[0][0] = 1;
  for (int i = 1; i <= end; ++i) {
    bc[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      bc[i][j] = (1LL * bc[i-1][j-1] + bc[i-1][j]) % MOD;
    }
  }
}

// Stars and Bars:
// Split K balls into i non-empty piles [K-1 choose i-1]
// Intersperse i piles between the N-K balls [N-K+1 choose i]

int main() {
  scanf(" %d%d", &N, &K);
  init();
  for (int i = 1; i <= K; ++i) {
    int res = 1LL * bc[K-1][i-1] * bc[N-K+1][i] % MOD;
    printf("%d\n", res);
  }
  return 0;
}
