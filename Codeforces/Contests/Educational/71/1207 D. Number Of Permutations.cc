#include <algorithm>
#include <cstdio>
#include <utility>
#define X first
#define Y second
typedef std::pair<int,int> pii;
const int MAXN = 3e5+5;
const int MOD = 998244353;
int cntA[MAXN]{ };
int cntB[MAXN]{ };
int F[MAXN];
pii P[MAXN];
int A, B, N;

void init() {
  F[0] = 1;
  for (int i = 1; i <= N; ++i) {
    F[i] = 1LL * F[i-1] * i % MOD;
  }
}

int count_both() {
  int cnt = 1;
  int res = 1;
  for (int i = 1; i < N; ++i) {
    if (P[i-1].Y > P[i].Y) {
      res = 0;
      break;
    }
    if (P[i] != P[i-1]) {
      res = 1LL * res * F[cnt] % MOD;
      cnt = 1;
    } else {
      ++cnt;
    }
  }
  res = 1LL * res * F[cnt] % MOD;
  return res;
}

int main() {
  scanf("%d", &N);
  init();
  for (int i = 0; i < N; ++i) {
    scanf(" %d%d", &P[i].X, &P[i].Y);
    ++cntA[P[i].X];
    ++cntB[P[i].Y];
  }
  int ret = F[N];
  int ant = 1;
  int bnt = 1;
  for (int i = 1; i <= N; ++i) {
    ant = 1LL * F[cntA[i]] * ant % MOD;
    bnt = 1LL * F[cntB[i]] * bnt % MOD;
  }
  std::sort(P, P+N);
  ret = (1LL * ret + MOD - ant) % MOD;
  ret = (1LL * ret + MOD - bnt) % MOD;
  ret = (1LL * ret + count_both()) % MOD;
  printf("%d\n", ret);
  return 0;
}
