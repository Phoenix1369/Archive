#include <cstdio>
const int MAXA = 26;
const int MAXN = 105;
char S[MAXN];
int A, N;

int main() {
  scanf(" %s", S);
  scanf("%d", &A);
  int ret = 0;
  for (char *ptr = S; *ptr; ++ptr) {
    ret += (*ptr - 'a' + A) % MAXA;
  }
  printf("%d\n", ret);
  return 0;
}
