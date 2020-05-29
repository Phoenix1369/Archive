#include <cstdio>
#include <unordered_map>
typedef long long lld;
const int MAXN = 2e5+5;
std::unordered_map<int,int> seen;
int A[MAXN];
int P[MAXN];
int K, N;

lld solve() {
  A[0] = 0;
  for (int i = 1; i <= N; ++i) {
    A[i] = (1LL * A[i-1] + A[i]) % K;
  }
  seen.reserve(N+1);
  ++seen[0];
  lld ret = 0LL;
  for (int i = 1; i <= N; ++i) {
    int cur = (1LL * A[i] - i) % K;
    if (cur < 0) cur += K;
    if (i >= K) {
      int prev = P[i-K];
      if (!--seen[prev]) {
        seen.erase(prev);
      }
    }
    if (seen.count(cur)) {
      ret += seen.at(cur);
    }
    ++seen[cur];
    P[i] = cur;
  }
  return ret;
}

int main() {
  scanf(" %d%d", &N, &K);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
  }
  printf("%lld\n", solve());
  return 0;
}
