#include <cstdio>
int H, K, N;

int main() {
  scanf(" %d%d", &N, &K);
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &H);
    if (H >= K) ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
