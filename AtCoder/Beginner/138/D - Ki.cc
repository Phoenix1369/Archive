#include <cstdio>
#include <vector>
const int MAXN = 2e5+5;
const int ROOT = 1;
std::vector<int> G[MAXN];
bool seen[MAXN];
int C[MAXN];
int a, b, p, x;
int N, Q;

void dfs(int cur) {
  seen[cur] = true;
  for (auto nxt: G[cur]) {
    if (seen[nxt]) continue;
    C[nxt] += C[cur];
    dfs(nxt);
  }
}

void init() {
  for (int i = 1; i <= N; ++i) {
    C[i] = 0;
    G[i].clear();
    seen[i] = false;
  }
}

int main() {
  scanf(" %d%d", &N, &Q);
  init();
  for (int i = 1; i < N; ++i) {
    scanf(" %d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int q = 0; q < Q; ++q) {
    scanf(" %d%d", &p, &x);
    C[p] += x;
  }
  dfs(ROOT);
  for (int i = 1; i <= N; ++i) {
    printf("%d%c", C[i], (i == N) ? '\n' : ' ');
  }
  return 0;
}
