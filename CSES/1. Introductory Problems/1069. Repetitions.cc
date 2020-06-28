#include <algorithm>
#include <cstdio>
#include <cstring>
const int MAXN = 1e6+5;
char s[MAXN];
int n;

int main() {
  scanf(" %s", s);
  n = strlen(s);
  int cnt = 1;
  int ret = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i-1]) {
      ret = std::max(cnt, ret);
      cnt = 1;
    } else {
      ++cnt;
    }
  }
  ret = std::max(cnt, ret);
  printf("%d\n", ret);
  return 0;
}
