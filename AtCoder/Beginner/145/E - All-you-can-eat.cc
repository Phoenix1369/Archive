#include <algorithm>
#include <cstdio>
const int MAXN = 3005;
int A[MAXN];
int B[MAXN];
int dp[MAXN][MAXN];
int pd[MAXN][MAXN];
int N, T;

void prefix() {
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= T; ++j) {
      dp[i][j] = dp[i-1][j];
      if (j >= 1)    dp[i][j] = std::max(dp[i][j-1], dp[i][j]);
      if (j >= A[i]) dp[i][j] = std::max(dp[i-1][j - A[i]] + B[i], dp[i][j]);
    }
  }
}

void suffix() {
  for (int j = 0; j <= T; ++j) {
    pd[N+1][j] = 0;
  }
  for (int i = N; i >= 1; --i) {
    for (int j = 0; j <= T; ++j) {
      pd[i][j] = pd[i+1][j];
      if (j >= 1)    pd[i][j] = std::max(pd[i][j-1], pd[i][j]);
      if (j >= A[i]) pd[i][j] = std::max(pd[i+1][j - A[i]] + B[i], pd[i][j]);
    }
  }
}

int solve() {
  prefix();
  suffix();
  int ret = dp[N][T];
  // Fix final dish
  for (int i = 1; i <= N; ++i) {
    int cur = 0;
    for (int j = 0; j < T; ++j) {
      cur = std::max(dp[i-1][j] + pd[i+1][T-j-1], cur);
    }
    cur += B[i];
    ret = std::max(cur, ret);
  }
  return ret;
}

void init() {
  for (int j = 0; j <= T; ++j) {
    dp[0][j] = 0;
    pd[N+1][j] = 0;
  }
}

int main() {
  scanf(" %d%d", &N, &T);
  init();
  for (int i = 1; i <= N; ++i) {
    scanf(" %d%d", &A[i], &B[i]);
  }
  printf("%d\n", solve());
  return 0;
}
