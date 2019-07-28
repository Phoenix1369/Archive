#include <cstdio>
int a, n;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  scanf("%d", &n);
  for (a = n-2; a >= 1; --a) {
    if (gcd(a, n) == 1) break;
  }
  printf("%d\n", a);
}
