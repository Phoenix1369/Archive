#include <cstdio>
#include <cstring>
const int MAXS = 2e5+5;
char S[MAXS];

int main() {
  scanf("%s", S);
  int N = strlen(S);
  int ret = 1;
  for (int i = 1; i < N; ++i) {
    // Single character
    if (S[i] != S[i-1]) {
      ++ret;
    } else {
      // Greedily augment
      ++i;
      if (i < N) ++ret;
      ++i;
      if (i < N) ++ret;
    }
  }
  printf("%d\n", ret);
  return 0;
}
