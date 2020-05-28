#include <cstdio>
const int M = 3;
const int MAXX = 1e6+5;
const int MOD = 1e9+7;
int F[MAXX];
int X, Y;

/*
1........
..1......
.1..1....
...2..1..
..1..3..1
....3..4.
...1..6..
.....4..A
*/

int extended_gcd(int a, int b, int s, int t) {
  if (!b) return s;
  int q = a / b;
  return extended_gcd(b, a - q * b, t, s - q * t);
}

int inv(int x) {
  int res = extended_gcd(x, MOD, 1, 0);
  if (res < 0) res += MOD;
  return res;
}

void init(int N) {
  F[0] = 1;
  for (int i = 1; i <= N; ++i) {
      F[i] = 1LL * F[i-1] * i % MOD;
  }
}

int ncr(int N, int R) {
  return 1LL * F[N] * inv(1LL * F[R] * F[N-R] % MOD) % MOD;
}

int solve() {
  if ((X + Y) % M) {
    return 0;
  }
  if ((2 * X < Y) || (2 * Y < X)) {
    return 0;
  }
  int N = (X + Y) / M;
  int R = X - N;
  init(N);
  return ncr(N, R);
}

int main() {
  scanf(" %d%d", &X, &Y);
  printf("%d\n", solve());
  return 0;
}
