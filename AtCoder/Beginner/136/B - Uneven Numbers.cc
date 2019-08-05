#include <cstdio>
const int BASE = 10;
const int BB = BASE*BASE;
int N, T;

int main() {
  scanf("%d", &N);
  int T = 1;
  int ret = 0;
  while ((BASE*T - 1) <= N) {
    ret += (BASE - 1) * T;
    T *= BB;
  }
  if (T <= N) {
    ret += N - T + 1;
  }
  printf("%d\n", ret);
  return 0;
}
