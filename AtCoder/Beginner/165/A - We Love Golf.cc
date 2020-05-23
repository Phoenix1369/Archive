#include <cstdio>
int A, B, K;

int main() {
  scanf(" %d%d%d", &K, &A, &B);
  int mul = (B / K) * K;
  puts((A <= mul) ? "OK" : "NG");
  return 0;
}
