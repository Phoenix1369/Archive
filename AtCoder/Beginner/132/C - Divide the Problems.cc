#include <algorithm>
#include <cstdio>
const int MAXN = 1e5+5;
int D[MAXN];
int N;

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &D[i]);
  }
  std::sort(D, D+N);
  int h = N/2;
  printf("%d\n", D[h] - D[h-1]);
  return 0;
}
