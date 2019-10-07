#include <cstdio>
int C, N;

int main() {
  scanf("%d", &N);
  C = (N + 1) / 2;
  printf("%.9f\n", 1.0 * C / N);
  return 0;
}
