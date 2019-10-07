#include <cstdio>
const int MAXN = 1e5+5;
int out[MAXN];
int A, N;

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A);
    out[A] = i;
  }
  for (int i = 1; i <= N; ++i) {
    printf("%d ", out[i]);
  }
  putchar('\n');
  return 0;
}
