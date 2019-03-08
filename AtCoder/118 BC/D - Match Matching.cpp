#include <algorithm>
#include <cstdio>
const int MAXN = 1e4+5;
const int MAXM = 10;
const int S[MAXM] = {6,2,5,5,4,5,6,3,7,6};
int dp[MAXN][MAXM]{ };
// dp[i][j] = Max length with i matches beginning with digit j
bool yes[MAXM]{ };
int a, M, N;

int main() {
  scanf(" %d%d", &N, &M);
  for (int i = 0; i < M; ++i) {
    scanf("%d", &a);
    yes[a] = true;
  }
  yes[0] = true;
  for (int i = 0; i < N; ++i)
  for (int j = 0; j < MAXM; ++j) {
    dp[i][j] = -1;
  }
  dp[0][0] = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < MAXM; ++j) {
      if (yes[j] && (dp[i][j] >= 0)) {
        for (int k = std::max(j, 1); k < MAXM; ++k) {
          if (yes[k] && (i+S[k] <= N)) {
            dp[i+S[k]][k] = std::max(dp[i][j] + 1, dp[i+S[k]][k]);
          }
        }
      }
    }
  }
  int msd = 9;
  for (int i = MAXM-1; i >= 0; --i) {
    if (dp[N][i] > dp[N][msd]) {
      msd = i;
    }
  }
  int pos = msd;
  for (int i = N; i > 0;) {
    putchar('0' + pos);
    for (int j = MAXM-1; j >= 0; --j) if (yes[j]) {
      if (dp[i-S[pos]][j] + 1 == dp[i][pos]) {
        i -= S[pos];
        pos = j;
        break;
      }
    }
  }
  putchar('\n');
  return 0;
}
