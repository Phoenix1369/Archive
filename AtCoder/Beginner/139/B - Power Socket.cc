#include <cstdio>
int A, B;

int solve() {
  if (B == 1) return 0;
  // (B - 2) = (B - A + (A - 1) - 1) [round up]
  return 1 + (B - 2) / (A - 1);
}

int main() {
  scanf(" %d%d", &A, &B);
  printf("%d\n", solve());
  return 0;
}
