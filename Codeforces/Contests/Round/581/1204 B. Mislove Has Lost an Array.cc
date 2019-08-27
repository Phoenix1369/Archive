#include <cstdio>
int l, n, r;

int main() {
  scanf(" %d%d%d", &n, &l, &r);
  printf("%d %d\n",
         1 * (n - l) + (1 << l) - 1,
         (1 << r) - 1 + (1 << (r - 1)) * (n - r)
  );
  return 0;
}
