#include <cstdio>
#include <queue>
typedef long long lld;
std::priority_queue<int> pq;
int A, M, N;

lld solve() {
  for (int i = 0; i < M; ++i) {
    if (pq.empty()) break;
    int v = pq.top();
    pq.pop();
    v /= 2;
    if (v) pq.push(v);
  }
  lld sum = 0LL;
  while (!pq.empty()) {
    sum += pq.top();
    pq.pop();
  }
  return sum;
}

int main() {
  scanf(" %d%d", &N, &M);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A);
    pq.push(A);
  }
  printf("%lld\n", solve());
  return 0;
}
