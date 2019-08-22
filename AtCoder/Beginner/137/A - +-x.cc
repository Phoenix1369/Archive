#include <algorithm>
#include <cstdio>
int A, B;

int main() {
  scanf(" %d%d", &A, &B);
  printf("%d\n", std::max(A + B, std::max(A - B, A * B)));
  return 0;
}
