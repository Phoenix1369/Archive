#include <cstdio>
#include <queue>
typedef long long lld;
const int MAXN = 2e5+5;
const int NOPE = -1;
int A[MAXN];
int B[MAXN];
int N;

bool local_max(int i) {
    int u = (i + N - 1) % N;
    int v = (i + 1) % N;
    return (B[i] > B[u] + B[v]);
}

lld solve() {
  std::queue<int> Q;
  for (int i = 0; i < N; ++i) {
    if (local_max(i)) Q.push(i);
  }
  lld ret = 0LL;
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    if (B[cur] < A[cur]) break;
    if (!local_max(cur)) continue;

    int u = (cur + N - 1) % N;
    int v = (cur + 1) % N;
    int sum = B[u] + B[v];
    int step = (B[cur] - A[cur]) / sum;
    B[cur] -= 1LL * step * sum;
    ret += step;

    if (local_max(u)) Q.push(u);
    if (local_max(v)) Q.push(v);
  }
  for (int i = 0; i < N; ++i) {
    if (B[i] != A[i]) return NOPE;
  }
  return ret;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
  for (int i = 0; i < N; ++i) scanf("%d", &B[i]);
  printf("%lld\n", solve());
  return 0;
}
