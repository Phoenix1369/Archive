#include <cstdio>
const int MAXN = 2e5+5;
int A[MAXN];
int N, T;

bool solve() {
  scanf("%d", &N);
  int N2 = N/2;
  if (N2 & 1) {
    return false;
  }
  for (int i = 1; i <= N2; ++i) {
    A[i] = 2 * i;
  }
  for (int i = 1; i < N2; ++i) {
    A[N2 + i] = 2 * i - 1;
  }
  A[N] = 3 * N2 - 1;
  return true;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    if (solve()) {
      puts("YES");
      for (int i = 1; i <= N; ++i) {
        printf("%d ", A[i]);
      }
      putchar('\n');
    } else {
      puts("NO");
    }
  }
  return 0;
}
