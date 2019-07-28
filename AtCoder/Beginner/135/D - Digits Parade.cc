#include <cstdio>
#include <cstring>
const int BASE = 10;
const int DIVS = 13;
const int MAXS = 1e5+5;
const int MOD = 1e9+7;
const int REM = 5;
char buff[MAXS];
int dp[MAXS][DIVS];
int S;

void place(int i, int msb) {
  for (int k = 0; k < DIVS; ++k) {
    int pos = (msb + k * BASE) % DIVS;
    dp[i][pos] = (1LL * dp[i-1][k] + dp[i][pos]) % MOD;
  }
}

int solve() {
  for (int i = 0; i <= S; ++i) {
    for (int j = 0; j < DIVS; ++j) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;

  for (int i = 1; i <= S; ++i) {
    if (buff[i] == '?') {
      for (int j = 0; j < BASE; ++j) {
        place(i, j);
      }
    } else {
      place(i, buff[i]-'0');
    }
  }
  return dp[S][REM];
}

int main() {
  scanf(" %s", buff+1);
  S = strlen(buff+1);
  printf("%d\n", solve());
  return 0;
}
