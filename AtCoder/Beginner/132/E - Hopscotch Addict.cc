#include <cstdio>
#include <queue>
#include <vector>
const int INFN = 1e9+7;
const int MAXK = 3;
const int MAXN = 1e5+5;
std::vector<int> G[MAXN];
int D[MAXN][MAXK];
int M, N, S, T;

struct Pair {
  int node, state;
};

int solve() {
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < MAXK; ++j) {
      D[i][j] = INFN;
    }
  }
  std::queue<Pair> Q;
  D[S][0] = 0;
  Q.push(Pair{S, 0});
  while (!Q.empty()) {
    Pair cur = Q.front();
    Q.pop();
    int nst = (cur.state + 1) % MAXK;
    for (int nxt: G[cur.node]) {
      if (D[nxt][nst] == INFN) {
        D[nxt][nst] = D[cur.node][cur.state] + 1;
        Q.push(Pair{nxt, nst});
      }
    }
  }
  if (D[T][0] == INFN) {
    D[T][0] = -1;
  } else {
    D[T][0] /= MAXK;
  }
  return D[T][0];
}

int main() {
  scanf(" %d%d", &N, &M);
  for (int i = 0; i < M; ++i) {
    int u, v;
    scanf(" %d%d", &u, &v);
    G[u].push_back(v);
  }
  scanf(" %d%d", &S, &T);
  printf("%d\n", solve());
  return 0;
}
