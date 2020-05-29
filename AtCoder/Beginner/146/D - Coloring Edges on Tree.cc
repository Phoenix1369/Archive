#include <cstdio>
#include <vector>
const int MAXN = 1e5+5;
std::vector<int> G[MAXN];
unsigned deg[MAXN]{ };
int B[MAXN];
int C[MAXN];        // Edge color
int start[MAXN];    // Node starting color
int N;

int main() {
  scanf("%d", &N);
  for (int i = 1; i < N; ++i) {
    int a;
    scanf(" %d%d", &a, &B[i]);
    G[a].push_back(i);
    ++deg[a];
    ++deg[B[i]];
  }
  unsigned K = 0;
  for (int i = 1; i <= N; ++i) {
    K = std::max(deg[i], K);
  }
  start[1] = 1;
  for (int cur = 1; cur <= N; ++cur) {
    int tint = start[cur];
    for (int e: G[cur]) {
      C[e] = tint;
      tint = tint % K + 1;
      start[B[e]] = tint;
    }
  }
  printf("%u\n", K);
  for (int i = 1; i < N; ++i) {
    printf("%d\n", C[i]);
  }
  return 0;
}
