#include <algorithm>
#include <cstdio>
const int INFN = 1e9+7;
const int MAXM = 1005;
const int MAXN = 12;
const int NOPE = -1;
int A[MAXM];
int B[MAXM];
int C[MAXM];
int dp[1 << MAXN]{ };
int c, M, N;
int L;

void init() {
  for (int i = 0; i < L; ++i) {
    dp[i] = INFN;
  }
  dp[0] = 0;
}

void read() {
  for (int i = 0; i < M; ++i) {
    scanf(" %d%d", &A[i], &B[i]);
    C[i] = 0;
    for (int j = 0; j < B[i]; ++j) {
      scanf("%d", &c);
      C[i] |= (1 << (c - 1));
    }
  }
  L = (1 << N);
}

int solve() {
  for (int mask = 0; mask < L; ++mask) {
    for (int j = 0; j < M; ++j) {
      int next = (mask | C[j]);
      if (next == mask) {
        continue;
      }
      dp[next] = std::min(dp[mask] + A[j], dp[next]);
    }
  }
  int ret = dp[L-1];
  return (ret == INFN) ? NOPE : ret;
}

int main() {
  scanf(" %d%d", &N, &M);
  read();
  init();
  printf("%d\n", solve());
  return 0;
}
