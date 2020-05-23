#include <cstdio>
const int MAXN = 105;
int seen[MAXN]{ };
int A, K, N, d;

int main() {
  scanf(" %d%d", &N, &K);
  for (int i = 0; i < K; ++i) {
    scanf("%d", &d);
    for (int j = 0; j < d; ++j) {
      scanf("%d", &A);
      seen[A] = true;
    }
  }
  int ret = 0;
  for (int i = 1; i <= N; ++i) {
    if (!seen[i]) ++ret;
  }
  printf("%d\n", ret);
  return 0;
}
