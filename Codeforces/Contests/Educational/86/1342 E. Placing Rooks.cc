#include <cstdio>
typedef long long lld;
const int MAXN = 2e5+5;
const int MOD = 998244353;
int F[MAXN];
int G[MAXN];
int N;
lld K;

int fpm(int b, int e) {
  int r = 1;
  while (e) {
    if (e & 1) {
      r = 1LL * b * r % MOD;
    }
    b = 1LL * b * b % MOD;
    e >>= 1;
  }
  return r;
}

int inv(int x) {
  return fpm(x, MOD-2);
}

int C(int n, int r) {
  return 1LL * F[n] * G[r] % MOD * G[n-r] % MOD;
}

void init() {
  F[0] = 1;
  G[0] = 1;
  for (int i = 1; i <= N; ++i) {
    F[i] = 1LL * F[i-1] * i % MOD;
    G[i] = inv(F[i]);
  }
}

int solve() {
  // Place N rooks in exactly N-K columns
  // Principle of Inclusion-Exclusion:
  //   Placements such that all P columns contain rooks
  // Choose the set of P columns
  // Transpose and consider rows
  // See "Stirling numbers of the second kind"
  if (K >= N) {
    return 0;
  }
  init();
  int P = N-K;
  int sum = 0;
  for (int i = 0; i <= P; ++i) {
    int val = 1LL * C(P, i) * fpm(i, N) % MOD;
    if ((i & 1) == (P & 1)) {
      sum = (1LL * sum + val) % MOD;
    } else {
      sum = (1LL * sum - val + MOD) % MOD;
    }
  }
  int ret = 1LL * sum * C(N, P) % MOD;
  if (K != 0) {
    ret = 2LL * ret % MOD;
  }
  return ret;
}

int main() {
  scanf(" %d%lld", &N, &K);
  printf("%d\n", solve());
  return 0;
}
