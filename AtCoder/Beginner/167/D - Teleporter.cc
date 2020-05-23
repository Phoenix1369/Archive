#include <cstdio>
typedef long long lld;
const int MAXN = 2e5+5;
int A[MAXN];
int B[MAXN];
int pos[MAXN];
int N;
lld K;

int solve() {
  int cur = 1;
  pos[cur] = 0;
  B[pos[cur]] = cur;
  while (pos[A[cur]] == -1) {
    pos[A[cur]] = pos[cur] + 1;
    cur = A[cur];
    B[pos[cur]] = cur;
  }
  int init = pos[A[cur]];
  int loop = pos[cur] - init + 1;
  if (K <= init) {
    return B[K];
  }
  return B[(K - init) % loop + init];
}

int main() {
  scanf(" %d%lld", &N, &K);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
    pos[i] = -1;
  }
  printf("%d\n", solve());
  return 0;
}
