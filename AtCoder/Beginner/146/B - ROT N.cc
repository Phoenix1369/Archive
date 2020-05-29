#include <cstdio>
#include <cstring>
const int MAXA = 26;
const int MAXN = 1e4+5;
char S[MAXN];
int N;

char advance(char c) {
  return ((c - 'A') + N) % MAXA + 'A';
}

int main() {
  scanf(" %d%s", &N, S);
  for (char *ptr = S; *ptr; ++ptr) {
    *ptr = advance(*ptr);
  }
  puts(S);
  return 0;
}
