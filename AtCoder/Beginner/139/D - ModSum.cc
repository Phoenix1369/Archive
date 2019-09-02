#include <cstdio>
int N;

int main() {
  scanf("%d", &N);
  printf("%lld\n", 1LL * N * (N-1) / 2);
  return 0;
}
