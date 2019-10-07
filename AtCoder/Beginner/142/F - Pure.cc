#include <cstdio>
#include <queue>
#include <vector>
const int MAXN = 1005;
const int NOPE = -1;
typedef std::vector<int> vin;
int  dist[MAXN];
bool seen[MAXN];
vin G[MAXN];
int M, N;
int a, b;

struct State {
  int sink;
  int size;
  int upper[MAXN];

  void display() {
    printf("%d\n", size + 1);
    int cur = sink;
    while (cur != NOPE) {
      printf("%d\n", cur);
      cur = upper[cur];
    }
  }

  void reset() {
    sink = NOPE;
    size = NOPE;
    for (int i = 1; i <= N; ++i) {
      upper[i] = NOPE;
    }
  }
} best, S;

void reset() {
  for (int i = 1; i <= N; ++i) {
    dist[i] = NOPE;
    seen[i] = false;
  }
  S.reset();
}

void bfs(int src) {
  reset();
  std::queue<int> Q;
  dist[src] = 0;
  seen[src] = true;
  Q.push(src);

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (int nxt: G[cur]) {
      if (nxt == src) {
        if ((S.sink == NOPE) ||
            (dist[cur] < S.size)) {
          S.sink = cur;
          S.size = dist[cur];
        } // Shortest cycle at "src".
      }
      if (seen[nxt]) continue;
      dist[nxt] = dist[cur] + 1;
      seen[nxt] = true;
      S.upper[nxt] = cur;
      Q.push(nxt);
    }
  }
}

void solve() {
  best.reset();
  for (int i = 1; i <= N; ++i) {
    bfs(i);
    if (S.sink == NOPE) continue;
    if ((best.sink == NOPE) || (S.size < best.size)) {
      best = S;
    } // Shortest cycle overall.
  }
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; ++i) {
    scanf(" %d%d", &a, &b);
    G[a].push_back(b);
  }
  solve();
  if (best.sink != NOPE) {
    best.display();
  } else {
    puts("-1");
  }
  return 0;
}
