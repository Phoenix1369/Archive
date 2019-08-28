#include <algorithm>
#include <cstdio>
typedef long long lld;
const lld INFN = 1LL << 60;
const int MAXN = 2e5+5;
lld dp[MAXN][2];
char S[MAXN];
int A, B, N, T;

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf(" %d%d%d", &N, &A, &B);
    scanf("%s", S + 1);
    dp[0][0] = B;
    dp[0][1] = INFN;
    for (int i = 1; i <= N; ++i) {
      dp[i][0] = std::min(dp[i-1][0], dp[i-1][1] + A) + A + B;
      dp[i][1] = std::min(dp[i-1][0] + A, dp[i-1][1]) + A + 2*B;
      if ((S[i] == '1') || (S[i+1] == '1')) {
        dp[i][0] = INFN;
      }
    }
    printf("%lld\n", dp[N][0]);
  }
  return 0;
}
