#include <cstdio>
int A, N;

int main() {
  scanf("%d", &N);
  double ret = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A);
    ret += 1.0 / A;
  }
  printf("%.9f\n", 1.0 / ret);
  return 0;
}
