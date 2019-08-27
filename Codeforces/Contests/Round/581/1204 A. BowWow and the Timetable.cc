#include <cstdio>
#include <cstring>
const int MAXN = 105;
char S[MAXN];
int N;

bool trailing_one() {
  for (int i = 1; i < N; ++i) {
    if (S[i] == '1') {
      return true;
    }
  }
  return false;
}

int solve() {
  if (S[0] == '0') {
    return 0;
  }
  int ret = N / 2;
  if ((N & 1) && trailing_one()) ++ret;
  return ret;
}

int main() {
  scanf("%s", S);
  N = strlen(S);
  printf("%d\n", solve());
  return 0;
}
