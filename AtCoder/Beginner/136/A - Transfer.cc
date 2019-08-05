#include <algorithm>
#include <cstdio>
int A, B, C;

int main() {
  scanf(" %d%d%d", &A, &B, &C);
  C -= std::min(A - B, C);
  printf("%d\n", C);
  return 0;
}
