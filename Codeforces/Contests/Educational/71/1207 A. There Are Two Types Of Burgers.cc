#include <algorithm>
#include <cstdio>
int A[2], P[2];
int B, C, T;

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf(" %d%d%d%d%d",
          &B, &A[0], &A[1], &P[0], &P[1]);
    if (P[1] > P[0]) {
      std::swap(A[0], A[1]);
      std::swap(P[0], P[1]);
    }
    int ret = 0;
    for (int i = 0; i < 2; ++i) {
      C = std::min(B / 2, A[i]);
      ret += C * P[i];
      B -= C * 2;
    }
    printf("%d\n", ret);
  }
  return 0;
}
