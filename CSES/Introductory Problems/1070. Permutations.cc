#include <cstdio>
int n;

void solve() {
  if ((n == 2) || (n == 3)) {
    puts("NO SOLUTION");
    return;
  }
  for (int i = 2; i <= n; i += 2) printf("%d ", i);
  for (int i = 1; i <= n; i += 2) printf("%d ", i);
  putchar('\n');
}

int main() {
  scanf("%d", &n);
  solve();
  return 0;
}
