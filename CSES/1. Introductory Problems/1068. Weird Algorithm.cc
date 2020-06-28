#include <cstdio>
typedef long long lld;
lld N;

lld hailstone(lld n) {
  return (n & 1) ? (3 * n + 1) : (n / 2);
}

int main() {
  scanf("%lld", &N);
  while (true) {
    printf("%lld ", N);
    if (N == 1) break;
    N = hailstone(N);
  }
  putchar('\n');
  return 0;
} 
