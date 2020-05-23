#include <cstdio>
const int MAXN = 2e5+5;
const int MOD = 998244353;
int F[MAXN];
int G[MAXN];
int P[MAXN];
int K, M, N;

int fpm(int b, int e) {
  int r = 1;
  while (e) {
    if (e & 1) {
      r = 1LL * r * b % MOD;
    }
    b = 1LL * b * b % MOD;
    e >>= 1;
  }
  return r;
}

int inv(int x) { return fpm(x, MOD-2); }

int ncr(int n, int r) {
  return 1LL * F[n] * G[n-r] % MOD * G[r] % MOD;
}

void init() {
  F[0] = 1;
  G[0] = 1;
  P[0] = 1;
  for (int i = 1; i <= N; ++i) {
    F[i] = 1LL * F[i-1] * i % MOD;
    G[i] = inv(F[i]);
    P[i] = 1LL * P[i-1] * (M - 1) % MOD;
  }
}

int main() {
  scanf(" %d%d%d", &N, &M, &K);
  init();
  int ret = 0;
  for (int i = 0; i <= K; ++i) {
    int col = 1LL * M * P[N-i-1] % MOD;
    int val = 1LL * ncr(N-1, i) * col % MOD;
    ret = (1LL * ret + val) % MOD;
  }
  printf("%d\n", ret);
  return 0;
}
