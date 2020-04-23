#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using std::cin;
typedef long long lld;
const int MAXN = 2e5+5;
int da[MAXN], db[MAXN], dc[MAXN];
std::vector<int> G[MAXN];
lld P[MAXN];
int a, b, c, M, N, T;

void bfs(int src, int (&d)[MAXN]) {
  for (int i = 1; i <= N; ++i) {
    d[i] = -1;
  }
  d[src] = 0;
  std::queue<int> Q;
  Q.push(src);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int v: G[u]) {
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        Q.push(v);
      }
    }
  }
}

lld solve() {
  cin >> N >> M >> a >> b >> c;

  P[0] = 0;
  for (int i = 1; i <= M; ++i) {
    cin >> P[i];
  }
  std::sort(P+1, P+M+1);
  for (int i = 1; i <= M; ++i) {
    P[i] += P[i-1];
  }

  for (int i = 1; i <= N; ++i) {
    G[i].clear();
  }
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  bfs(a, da);
  bfs(b, db);
  bfs(c, dc);

  lld ret = 3LL * P[M];
  for (int i = 1; i <= N; ++i) {
    // Minimize: a -> i -> b -> i -> c
    int dabc = da[i] + db[i] + dc[i];
    // Invalid internal node
    if (dabc > M) {
      continue;
    }
    lld cost = P[db[i]] + P[dabc];
    ret = std::min(cost, ret);
  }
  return ret;
}

void fast_io() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  fast_io();
  cin >> T;
  for (int t = 0; t < T; ++t) {
    std::cout << solve() << '\n';
  }
  return 0;
}
