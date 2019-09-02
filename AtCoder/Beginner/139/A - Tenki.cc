#include <cstdio>
const int MAXS = 3;
char S[MAXS + 5];
char T[MAXS + 5];

int main() {
  scanf(" %s%s", S, T);
  int ret = 0;
  for (int i = 0; i < MAXS; ++i) {
    if (S[i] == T[i]) ++ret;
  }
  printf("%d\n", ret);
  return 0;
}
