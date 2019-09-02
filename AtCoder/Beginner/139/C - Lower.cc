#include <algorithm>
#include <cstdio>
const int MAXN = 1e5+5;
int cnt[MAXN]{ };
int H[MAXN];
int N;

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &H[i]);
  }
  for (int i = 1; i < N; ++i) {
    if (H[i] <= H[i-1]) {
      cnt[i] = 1 + cnt[i-1];
    }
  }
  printf("%d\n", *std::max_element(cnt, cnt + N));
  return 0;
}
