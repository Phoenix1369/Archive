#include <algorithm>
#include <cstdio>
int A, B;

int main() {
  scanf(" %d%d", &A, &B);
  if (A > B) std::swap(A, B);
  int D = B - A;
  if (D & 1) {
    puts("IMPOSSIBLE");
  } else {
    printf("%d\n", A + D / 2);
  }
  return 0;
}
