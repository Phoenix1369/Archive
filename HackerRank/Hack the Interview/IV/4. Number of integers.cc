#include <cstdio>
#include <cstring>
#define CLR(x) memset((x), -1, sizeof(x))
const int MAXK = 105;
const int MOD = 1e9+7;
int dp[MAXK][MAXK][2][2];
char L[MAXK];
char R[MAXK];
int K, N;

int dfs(int pos, int k, bool ls, bool rs) {
  if (k > K) {
    return 0;
  }
  if (dp[pos][k][ls][rs] != -1) {
    return dp[pos][k][ls][rs];
  }
  if (pos == N) {
    int res = (!ls && (k == K)) ? 1 : 0;
    return dp[pos][k][ls][rs] = res;
  }
  int lc = (ls) ? (L[pos] - '0') : 0;
  int rc = (rs) ? (R[pos] - '0') : 9;
  int res = 0;
  for (int d = lc; d <= rc; ++d) {
    int nk = k;
    if (d) ++nk;
    bool nls = ls && (d == lc);
    bool nrs = rs && (d == rc);
    int val = dfs(pos+1, nk, nls, nrs);
    res = (1LL * res + val) % MOD;
  }
  return dp[pos][k][ls][rs] = res;
}

void init() {
  N = strlen(R);
  int M = strlen(L);
  if (M == N) {
    return;
  }
  L[N] = '\0';
  for (int i = 0; i < M; ++i) {
    L[N-i-1] = L[M-i-1];
  }
  for (int i = N-M-1; i >= 0; --i) {
    L[i] = '0';
  }
}

int main() {
  scanf(" %s", L);
  scanf(" %s", R);
  scanf("%d", &K);
  init();
  CLR(dp);
  printf("%d\n", dfs(0, 0, true, true));
  return 0;
}
