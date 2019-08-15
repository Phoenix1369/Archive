#include <algorithm>
#include <cstdio>
const int MAXN = 105;
int dp[MAXN]; // implicit dp[i][j] = dp[j]
// maximum rating after completing j projects among the first i.
int n, r;

int sgn(int x) { return (x > 0) - (x < 0); }

struct Pair {
  int a, b;

  bool operator < (const Pair& o) const {
    int s = sgn(b);
    int os = sgn(o.b);
    // +1 -> 0 -> -1
    if (s != os) return (s > os);
    // (s == os)
    if (s >= 0) return (a < o.a);
    // (sl == -1)
    int c = a + b;
    int oc = o.a + o.b;
    if (c == oc) {
      return (a > o.a);
    }
    return (c > oc);
  }
} P[MAXN];

void init() {
  for (int i = 0; i <= n; ++i) {
    dp[i] = -1;
  }
}

int solve() {
  dp[0] = r;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j >= 1; --j) {
      if (dp[j-1] < P[i].a) {
        continue;
      }
      dp[j] = std::max(dp[j-1] + P[i].b, dp[j]);
    } // Augment with P[i]
  }
  for (int i = n; i >= 0; --i) {
    if (dp[i] >= 0) return i;
  }
  return -1;
}

int main() {
  scanf(" %d%d", &n, &r);
  init();
  for (int i = 1; i <= n; ++i) {
    scanf(" %d%d", &P[i].a, &P[i].b);
    P[i].a = std::max(P[i].a, -P[i].b);
  }
  std::sort(P+1, P+n+1);
  printf("%d\n", solve());
  return 0;
}
