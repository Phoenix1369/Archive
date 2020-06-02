#include <cstdio>
#include <cstring>
const int MAXN = 1e6+5;
char S[MAXN];
int D, N;

int solve() {
  N = strlen(S);
  int cnt = 0;
  int ret = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == '0') {
      ++cnt;
    } else {
      cnt = 0;
    }
    if (cnt >= D) {
      cnt = 0;
      ++ret;
    }
  }
  return ret;
}

int main() {
  scanf(" %s", S);
  scanf("%d", &D);
  printf("%d\n", solve());
  return 0;
}
