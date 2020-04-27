#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define ALL(x) (x).begin(), (x).end()

template <typename T>
using vec = std::vector<T>;

const int MAXN = 1e6+5;
const int NOPE = -1;
vec<int> G[MAXN];
int able[MAXN];
int dist[MAXN];
vec<int> ret;
int M, N, T;

void bfs(int src) {
  std::queue<int> Q;
  Q.push(src);
  able[src] = false;
  dist[src] = 0;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int v: G[u]) {
      if ((v == 1) || (dist[v] != NOPE)) {
        continue;
      }
      dist[v] = dist[u] + 1;
      able[v] = false;
      if (dist[v] < 2) {
        Q.push(v);
      }
    }
  }
}

void compute() {
  able[1] = false;
  for (int v: G[1]) {
    if (able[v]) {
      ret.push_back(v);
    }
  }
  std::sort(ALL(ret));
  ret.erase(unique(ALL(ret)), ret.end());
  if (ret.empty()) {
    ret.push_back(-1);
  }
}

void init() {
  for (int i = 1; i <= N; ++i) {
    able[i] = true;
    G[i].clear();
    dist[i] = -1;
  }
  ret.clear();
}

void solve() {
  scanf(" %d%d", &N, &M);
  init();
  for (int i = 0; i < M; ++i) {
    int a, b;
    scanf(" %d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bfs(2);
  compute();
  for (int& x: ret) {
    printf("%d ", x);
  }
  putchar('\n');
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
