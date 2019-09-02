#include <algorithm>
#include <cstdio>
const int MAXN = 55;
int A[MAXN];
int N;

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  std::sort(A, A+N);
  double ret = A[0];
  for (int i = 1; i < N; ++i) {
    ret = (A[i] + ret) / 2.0;
  }
  printf("%.9f\n", ret);
  return 0;
}
