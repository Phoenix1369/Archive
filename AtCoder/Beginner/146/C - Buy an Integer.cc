#include <cstdio>
typedef long long lld;
const int BASE = 10;
const int MAXN = 1e9;
int A, B;
lld X;

int d(int x) {
  int cnt = 0;
  while (x) {
    ++cnt;
    x /= BASE;
  }
  return cnt;
}

bool f(int N) {
  return (1LL * A * N + 1LL * B * d(N)) <= X;
}

int solve() {
  int lo = 0;
  int hi = MAXN;
  while (lo < hi) {
    int x = (lo + hi + 1) / 2;
    if (f(x)) {
      lo = x;
    } else {
      hi = x - 1;
    }
  }
  return lo;
}

int main() {
    scanf(" %d%d%lld", &A, &B, &X);
    printf("%d\n", solve());
    return 0;
}
