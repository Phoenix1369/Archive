#include <algorithm>
#include <cstdio>
#include <cstring>
const int MAXS = 1e5+5;
char S[MAXS];
int P[MAXS];
int s, T;

int main() {
  scanf("%d", &T);
  P[0] = 0;
  for (int t = 1; t <= T; ++t) {
    scanf(" %s", S+1);
    s = strlen(S+1);
    for (int i = 1; i <= s; ++i) {
      P[i] = P[i-1];
      if (S[i] == '(') ++P[i];
    }
    int ret = 0;
    for (int i = 1; i <= s; ++i) {
      int super = std::min(P[i], (s - i) - (P[s] - P[i]));
      ret = std::max(super, ret);
    }
    printf("%d\n", ret*2);
  }
  return 0;
}
