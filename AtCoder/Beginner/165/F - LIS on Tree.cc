#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int INFN = 1e9+7;
const int MAXN = 2e5+5;
int A[MAXN];
vin G[MAXN];
int L[MAXN];      // LIS stack
int up[MAXN];     // DFS parent
int N;

int ret[MAXN];

void dfs(int u) {
  int pos = std::lower_bound(L, L + N, A[u]) - L;
  int save = L[pos];
  L[pos] = A[u];
  
  ret[u]  = std::lower_bound(L, L + N, INFN) - L;
  for (int v: G[u]) {
    if (v != up[u]) {
      up[v] = u;
      dfs(v);
    }
  }
  L[pos] = save;
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
  }
  for (int i = 1; i < N; ++i) {
    int u, v;
    scanf(" %d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 0; i < N; ++i) {
    L[i] = INFN;
  }
  up[1] = 1;
  dfs(1);
  for (int i = 1; i <= N; ++i) {
    printf("%d\n", ret[i]);
  }
  return 0;
}
