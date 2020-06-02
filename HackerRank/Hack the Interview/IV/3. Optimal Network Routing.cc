#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#define CLR(x) memset((x), 0x3F, sizeof(x))
const int MAXC = 1e6+5;
const int MAXK = 4;
const int MAXN = 305;
const int dir[MAXK][2] = {{0,-1}, {1,0}, {0,1}, {-1,0}};
int A[MAXN][MAXN];
int C[MAXN][MAXN];
int M, N;

struct State {
  int x, y, d;
  
  bool operator < (const State& o) const {
    return (o.d < d);
  }
  
  bool in_range() const {
    return (0 <= x) && (x < M) && (0 <= y) && (y < N);
  }
};

int dijkstra(State src) {
  CLR(A);
  std::priority_queue<State> Q;
  A[src.y][src.y] = src.d;
  Q.push(src);
  while (!Q.empty()) {
    State u = Q.top();
    Q.pop();
    if (u.d > A[u.y][u.x]) {
      continue;
    }
    if ((u.x == M-1) && (u.y == N-1)) {
      return u.d;
    }
    for (int k = 0; k < MAXK; ++k) {
      State v = {
        u.x + dir[k][0],
        u.y + dir[k][1],
        0
      };
      if (!v.in_range()) {
        continue;
      }
      v.d = std::max(abs(C[u.y][u.x] - C[v.y][v.x]), u.d);
      if (v.d >= A[v.y][v.x]) {
        continue;
      }
      A[v.y][v.x] = v.d;
      Q.push(v);
    }
  }
  return 0;
}

int main() {
  scanf(" %d%d", &N, &M);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      scanf("%d", &C[i][j]);
    }
  }
  printf("%d\n", dijkstra({0, 0, 0}));
  return 0;
}
