#include <cstdio>
const int MAXN = 1e5+5;
bool good[MAXN];
int H[MAXN];
int a, b, M, N;

int main() {
  scanf(" %d%d", &N, &M);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &H[i]);
    good[i] = true;
  }
  for (int i = 0; i < M; ++i) {
    scanf(" %d%d", &a, &b);
    good[a] &= (H[a] > H[b]);
    good[b] &= (H[b] > H[a]);
  }
  int ret = 0;
  for (int i = 1; i <= N; ++i) {
    if (good[i]) ++ret;
  }
  printf("%d\n", ret);
  return 0;
}
