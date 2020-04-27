#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
template <typename T>
using vec = std::vector<T>;
template <typename T>
using min_heap = std::priority_queue<T, vec<T>, std::greater<T>>;

typedef long long lld;
const int MAXC = 2500;
const int MAXN = 55;
const lld MAXT = 3e12;
int C[MAXN];
int D[MAXN];
int M, N, S;

struct Edge {
  int v;
  int a, b;
};
vec<Edge> G[MAXN];
bool seen[MAXN];
int visited;

lld T[MAXN][MAXC+5];
// T[i][j] = min time to arrive at city i with j silver coins.

struct State {
  lld time;
  int u, s;

  bool operator > (const State& o) const {
    return time > o.time;
  }
};

void dijkstra(int src) {
  min_heap<State> pq;

  pq.push({0, src, S});
  T[src][S] = 0;
  seen[src] = true;
  ++visited;

  while (!pq.empty()) {
    State cur = pq.top();
    pq.pop();

    if (T[cur.u][cur.s] < cur.time) {
      continue;
    }

    if (!seen[cur.u]) {
      seen[cur.u] = true;
      if (++visited == N) {
        break;
      }
    }

    for (auto& nxt: G[cur.u]) {
      lld time = cur.time;
      int silver = cur.s;
      if (silver < nxt.a) {
        int xchg = (nxt.a - silver + C[cur.u] - 1) / C[cur.u];
        silver = std::min(xchg * C[cur.u] + silver, MAXC);
        time += 1LL * xchg * D[cur.u];
      }

      auto transit = [&time, &silver, &nxt, &pq](){
        lld nt = time + nxt.b;
        int ns = silver - nxt.a; 
        if (nt < T[nxt.v][ns]) {
          pq.push({nt, nxt.v, ns});
          T[nxt.v][ns] = nt;
        }
      };
      transit();

      while (silver < MAXC) {
        silver = std::min(silver + C[cur.u], MAXC);
        time += D[cur.u];
        transit();
      }
    }    
  }
}

void output() {
  for (int t = 2; t <= N; ++t) {
    lld ans = *std::min_element(T[t], T[t]+MAXC+1);
    printf("%lld\n", ans);
  }
}

void fastio() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

void init() {
  for (int i = 1; i <= N; ++i) {
    G[i].clear();
    seen[i] = false;
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= MAXC; ++j) {
      T[i][j] = MAXT;
    }
  }
  S = std::min(MAXC, S);
  visited = 0;
}

int main() {
  fastio();
  cin >> N >> M >> S;
  init();
  for (int i = 0; i < M; ++i) {
    int a, b, u, v;
    cin >> u >> v >> a >> b;
    G[u].push_back({v, a, b});
    G[v].push_back({u, a, b});
  }
  for (int i = 1; i <= N; ++i) {
    cin >> C[i] >> D[i];
  }
  dijkstra(1);
  output();
  return 0;
}
