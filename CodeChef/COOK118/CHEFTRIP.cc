#include <cmath>
#include <cstdio>
#include <vector>
const int LOGN = 17;
const int MAXN = 1e5+5;
std::vector<int> G[MAXN];
int    A[MAXN];
char out[MAXN];

int  dec[MAXN];
int  inc[MAXN];
int  lvl[MAXN];   // DFS depth
int  par[LOGN][MAXN];
int N, Q, T;

void dfs(int u) {
  for (int v: G[u]) {
    if (v == par[0][u]) continue;
    par[0][v] = u;
    dec[v] = v;
    inc[v] = v;
    if (A[v] < A[u]) {
      inc[v] = inc[u];
    } else if (A[v] > A[u]) {
      dec[v] = dec[u];
    }
    lvl[v] = lvl[u] + 1;
    dfs(v);
  }
}

void compute() {
  for (int k = 1; k < LOGN; ++k) {
    for (int i = 1; i <= N; ++i) {
      par[k][i] = par[k-1][par[k-1][i]];
    }
  }
}

int lca(int u, int v) {
  if (lvl[u] > lvl[v]) {
    std::swap(u, v);
  }

  int diff = lvl[v] - lvl[u];
  for (int k = 0; k < LOGN; ++k) {
    if ((diff >> k) & 1) {
      v = par[k][v];
    }
  }
  if (u == v) {
    return u;
  }

  for (int k = LOGN-1; k >= 0; --k) {
    if (par[k][u] != par[k][v]) {
      u = par[k][u];
      v = par[k][v];
    }
  }
  return par[0][u];
}

int solve(int x, int y) {
  int z = lca(x, y);
  int L = lvl[z];

  int xp = inc[x];
  if (lvl[xp] < L) xp = z;
  int yp = inc[y];
  if (lvl[yp] < L) yp = z;

  if (xp == yp) {
    return 1;
  }
  if (lvl[xp] == L) {
    return (lvl[dec[yp]] <= L) ? 1 : 0;
  } else if (lvl[yp] == L) {
    return (lvl[dec[xp]] <= L) ? 1 : 0;
  }
  return 0;
}

void init() {
  for (int i = 1; i <= N; ++i) {
    G[i].clear();
  }
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf(" %d%d", &N, &Q);
    init();
    for (int i = 1; i < N; ++i) {
      int u, v;
      scanf(" %d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    for (int i = 1; i <= N; ++i) {
      scanf("%d", &A[i]);
    }

    int root = 1;
    par[0][root] = root;
    dec[root] = root;
    inc[root] = root;
    lvl[root] = 0;
    dfs(root);
    compute();

    for (int i = 0; i < Q; ++i) {
      int x, y;
      scanf(" %d%d", &x, &y);
      out[i] = solve(x, y) + '0';
    }
    out[Q] = '\0';
    puts(out);
  }
  return 0;
}
