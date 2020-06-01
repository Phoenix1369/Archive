#include <cstdio>
#include <iostream>
const int MAXS = 105;
char S[MAXS];
int N;

int main() {
  scanf(" %s", S);
  N = strlen(S);
  int cnt = 0;
  for (int i=0, j=N-1; i < j; ++i, --j) {
    if (S[i] != S[j]) ++cnt;
  }
  printf("%d\n", cnt);
  return 0;
}
