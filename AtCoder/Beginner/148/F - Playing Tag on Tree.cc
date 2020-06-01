#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define CLR(x) memset((x), -1, sizeof(x))
const int MAXN = 1e5+5;
std::vector<int> G[MAXN];
int A[MAXN];  // Aoki
int T[MAXN];  // Takahashi
int N, u, v;

void bfs(int src, int (&D)[MAXN]) {
  CLR(D);
  std::queue<int> Q;
  D[src] = 0;
  Q.push(src);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int v: G[u]) {
      if (D[v] == -1) {
        D[v] = D[u] + 1;
        Q.push(v);
      }
    }
  }
}

int main() {
  scanf(" %d%d%d", &N, &u, &v);
  for (int i = 1; i < N; ++i) {
    int a, b;
    scanf(" %d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bfs(u, T);
  bfs(v, A);
  int w = u;
  for (int i = 1; i <= N; ++i) {
    if ((A[i] > T[i]) && (A[i] > A[w])) {
      w = i;
    }
  }
  int ret = A[w] - 1;
  printf("%d\n", ret);
  return 0;
}
