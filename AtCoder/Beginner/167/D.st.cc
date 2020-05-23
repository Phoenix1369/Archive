#include <cstdio>
typedef long long lld;
const int MAXN = 2e5+5;
const int LOGK = 60; 
int A[LOGK][MAXN];
int N;
lld K;

int main() {
  scanf(" %d%lld", &N, &K);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[0][i]);
  }
  for (int j = 1; (1LL << j) <= K; ++j) {
    for (int i = 1; i <= N; ++i) {
      A[j][i] = A[j-1][A[j-1][i]];
    }
  }
  int ret = 1;
  for (int j = 0; K; ++j) {
    if (K & 1) {
      ret = A[j][ret];
    }
    K >>= 1;
  }
  printf("%d\n", ret);
  return 0;
}
