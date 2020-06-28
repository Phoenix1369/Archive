#include <cstdio>
int a, b, T;

bool solve() {
  return ((a >> 1) <= b) && ((b >> 1) <= a) && (((a + b) % 3) == 0);
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf(" %d%d", &a, &b);
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}
