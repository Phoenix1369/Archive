#include <cstdio>
int A, G, N;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  scanf("%d", &N);
  int G = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A);
    G = gcd(A, G);
  }
  printf("%d\n", G);
  return 0;
}
