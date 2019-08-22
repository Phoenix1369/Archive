#include <cstdio>
int K, X;

int main() {
  scanf(" %d%d", &K, &X);
  int end = X + K;
  for (int i = X - K + 1; i < end; ++i) {
    printf("%d ", i);
  }
  putchar('\n');
  return 0;
}
