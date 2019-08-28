#include <cstdio>
#include <cstdlib>
const int LOGN = 7;
const int MAXA = 100;

void query(int k) {
  putchar('?');
  for (int i = 1; i <= MAXA; ++i) {
    printf(" %d", i * k);
  }
  putchar('\n');
  fflush(stdout);
}

int read() {
  int val;
  scanf("%d", &val);
  if (val == -1) exit(0);
  return val;
}

int main() {
  int mask = (1 << LOGN) - 1;
  query(1);
  int res = read() & (mask << LOGN);
  query(1 << 7);
  res |= read() & mask;
  printf("! %d\n", res);
  return 0;
}
