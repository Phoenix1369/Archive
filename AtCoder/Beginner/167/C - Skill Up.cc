#include <algorithm>
#include <cstdio>
const int INFN = 12e5 + 5;
const int MAXN = 12;
int A[MAXN][MAXN];
int C[MAXN];
int M, N, X;

int main() {
  scanf(" %d%d%d", &N, &M, &X);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &C[i]);
    for (int j = 0; j < M; ++j) {
      scanf("%d", &A[i][j]);
    }
  }
  int L = 1 << N;
  int ret = INFN;
  for (int mask = 1; mask < L; ++mask) {
    int B[MAXN]{ };
    int cost = 0;
    for (int bit = 0; bit < N; ++bit) {
      if ((mask >> bit) & 1) {
        for (int j = 0; j < M; ++j) {
          B[j] += A[bit][j];
        }
        cost += C[bit];
      }
    }
    auto pred = [](int u) { return (u >= X); };
    if (std::all_of(B, B + M, pred)) {
      ret = std::min(cost, ret);
    }
  }
  if (ret == INFN) {
    ret = -1;
  }
  printf("%d\n", ret);
  return 0;
}
