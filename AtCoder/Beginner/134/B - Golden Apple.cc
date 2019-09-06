#include <cstdio>
int D, N;

int main() {
  scanf(" %d%d", &N, &D);
  int K = 2 * D + 1;
  printf("%d\n", (N + K - 1) / K);
  return 0;
}
