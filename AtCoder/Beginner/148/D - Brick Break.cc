#include <cstdio>
int A, N;

int main() {
  scanf("%d", &N);
  int C = 1;
  int ret = 0;
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A);
    if (A == C) {
      ++C;
    } else {
      ++ret;
    }
  }
  if (ret == N) {
    ret = -1;
  }
  printf("%d\n", ret);
  return 0;
}
