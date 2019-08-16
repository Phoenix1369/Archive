#include <algorithm>
#include <cstdio>
const int MAXN = 105;
int n, r;

int sgn(int x) { return (x > 0) - (x < 0); }

struct Pair {
  int a, b;

  bool operator < (const Pair& o) const {
    int s = sgn(b);
    int os = sgn(o.b);

    if (s != os) return (s > os);  // +1 -> 0 -> -1
    if (s >= 0) return (a < o.a);  // (s == os)
    // (s == -1)
    int c = a + b;
    int oc = o.a + o.b;
    if (c == oc) return (a > o.a);
    return (c > oc);
  }
} P[MAXN];

bool solve(int R) {
  int ret = 0;

  // Maximize rating
  for (int i = 1; i <= n; ++i) {
    if (R < P[i].a) return false;

    int sum = R + P[i].b;
    if (sum < 0) return false;
    R = sum;
    ++ret;
  }
  return true;
}

int main() {
  scanf(" %d%d", &n, &r);
  for (int i = 1; i <= n; ++i) {
    scanf(" %d%d", &P[i].a, &P[i].b);
    P[i].a = std::max(P[i].a, -P[i].b);
  }
  std::sort(P+1, P+n+1);
  puts(solve(r) ? "YES" : "NO");
  return 0;
}
