#include <cstdio>
#include <cstring>
const int HASH = 131;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int  H[MAXN];
int  P[MAXN];
char S[MAXN];
int N, T;

int get(int pos, int len) {
  int pre = 1LL * H[len] * P[pos-len] % MOD;
  return   (1LL * P[pos] - pre + MOD) % MOD;
}

void init() {
  H[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    H[i] = 1LL * HASH * H[i-1] % MOD;
  }
}

int solve() {
  P[0] = 0;
  for (int i = 1; i <= N; ++i) {
    P[i] = (1LL * HASH * P[i-1] + S[i]) % MOD;
  }
  int ret = 0;
  int N2 = N/2;
  for (int i = 1; i < N2; ++i) {
    int one = 2*i;
    int t1  = get(one, i);
    if (t1 != P[i]) {
      continue;
    }
    int K = (N - one) / 2;
    int cur = get(one + K, K);
    int t2  = get(N, K);
    if (t2 == cur) ++ret;
  }
  return ret;
}

int main() {
  scanf("%d", &T);
  init();
  for (int t = 0; t < T; ++t) {
    scanf(" %s", S+1);
    N = strlen(S+1);
    printf("%d\n", solve());
  }
  return 0;
}
