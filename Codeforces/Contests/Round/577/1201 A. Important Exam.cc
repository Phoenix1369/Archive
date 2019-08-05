#include <algorithm>
#include <cstdio>
const int MAXC = 5;
const int MAXN = 1005;
char  s[MAXN][MAXN];
int cnt[MAXN][MAXC];
int a[MAXN];
int m, n;

int main() {
  scanf(" %d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int j = 0; j < m; ++j) {
    scanf("%d", &a[j]);
  }
  int ret = 0;
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      ++cnt[j][s[i][j]-'A'];
    }
    int best = *std::max_element(cnt[j], cnt[j] + MAXC);
    ret += a[j] * best;
  }
  printf("%d\n", ret);
  return 0;
}
