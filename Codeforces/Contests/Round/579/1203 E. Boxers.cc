#include <algorithm>
#include <cstdio>
const int MAXN = 1.5e5+5;
int A[MAXN];
int N;

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  std::sort(A, A+N);
  int L = 0;
  int ret = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = -1; j <= 1; ++j) {
      int k = A[i] + j;
      if (L < k) {
        L = k;
        ++ret;
        break;
      }
    }
  }
  printf("%d\n", ret);
  return 0;
}
