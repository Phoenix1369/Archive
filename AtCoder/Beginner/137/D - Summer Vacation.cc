#include <algorithm>
#include <cstdio>
#include <queue>
const int MAXN = 1e5+5;
std::priority_queue<int> heap;
int M, N;

struct Pair {
  int A, B;

  bool operator < (const Pair& o) const {
    return A < o.A;
  }
} P[MAXN];

int main() {
  scanf(" %d%d", &N, &M);
  for (int i = 0; i < N; ++i) {
    scanf(" %d%d", &P[i].A, &P[i].B);
  }
  std::sort(P, P + N);
  int sum = 0;
  for (int i = 1, j = 0; i <= M; ++i) {
    while ((j < N) && (P[j].A == i)) {
      heap.push(P[j].B);
      ++j;
    }
    if (!heap.empty()) {
      sum += heap.top();
      heap.pop();
    }
  }
  printf("%d\n", sum);
  return 0;
}
