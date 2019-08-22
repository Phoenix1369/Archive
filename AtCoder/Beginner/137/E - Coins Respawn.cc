#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int INFN = 1e9+7;
const int MAXM = 5005;
const int MAXN = 2505;
int dist[MAXN]{ };
enum { SRC = 1 };
vin G[MAXN];
vin H[MAXN]; // Reverse of G
int M, N, P;

struct Edge {
  int A, B, C;
} E[MAXM];
bool seenG[MAXM]{ };
bool seenH[MAXM]{ };

int bellman_ford() {
  for (int i = 1; i <= N; ++i) dist[i] = INFN;
  dist[SRC] = 0;

  // Relax
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (dist[E[j].A] == INFN) continue;
      seenG[j] = true;
      if (dist[E[j].B] > dist[E[j].A] + E[j].C) {
        dist[E[j].B] = dist[E[j].A] + E[j].C;
      }
    }
  }

  // Cycle
  for (int j = 0; j < M; ++j) {
    if (!seenG[j] || !seenH[j]) continue;
    if (dist[E[j].B] > dist[E[j].A] + E[j].C) {
      return -1;
    }
  }
  return std::max(-dist[N], 0);
}

void dfs(int cur) {
  // Reachability from N.
  for (auto nxt: H[cur]) {
    if (seenH[nxt]) continue;
    seenH[nxt] = true;
    dfs(E[nxt].A);
  }
}

int main() {
  scanf(" %d%d%d", &N, &M, &P);
  for (int i = 0; i < M; ++i) {
    scanf(" %d%d%d", &E[i].A, &E[i].B, &E[i].C);
    E[i].C -= P;  // Button press.
    E[i].C *= -1; // Longest path.
    G[E[i].A].push_back(i);
    H[E[i].B].push_back(i);
  }
  dfs(N);
  printf("%d\n", bellman_ford());
  return 0;
}
