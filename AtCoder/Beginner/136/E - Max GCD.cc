#include <algorithm>
#include <cmath>
#include <cstdio>
const int MAXN = 505;
int A[MAXN];
int B[MAXN];
int K, N;

bool check(int M) {
  for (int i = 0; i < N; ++i) {
    B[i] = A[i] % M;
  }
  std::sort(B, B+N);
  int lo = 0;
  int hi = N-1;
  int cost = 0;
  while (lo < hi) {
    int sum = B[lo] + B[hi];
    if (sum < M) {
      cost += B[lo];
      B[hi] += B[lo];
      B[lo] = 0;
      ++lo;
    } else {
      // (sum >= M)
      cost += M - B[hi];
      B[hi] = M;
      B[lo] = sum - M;
      if (!B[lo]) ++lo;
      --hi;
    }
  }
  return (B[lo] % M == 0) && (cost <= K);
}

int main() {
  scanf(" %d%d", &N, &K);
  int S = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
    S += A[i];
  }
  int ret = 1;
  int sqrtS = sqrt(S);
  for (int i = 1; i <= sqrtS; ++i) if ((S % i) == 0) {
    int j = S / i;
    if (check(i)) ret = std::max(i, ret);
    if (check(j)) ret = std::max(j, ret);
  }
  printf("%d\n", ret);
  return 0;
}
