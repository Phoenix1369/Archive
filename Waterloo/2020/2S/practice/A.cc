#include <cstdio>
int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i += 2) {
    printf("%d\n", i);
  }
  return 0;
}
