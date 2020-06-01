#include <cstdio>
const int MAXN = 105;
char S[MAXN];
char T[MAXN];
int N;

int main() {
  scanf("%d", &N);
  scanf(" %s%s", S, T);
  for (int i = 0; i < N; ++i) {
    printf("%c%c", S[i], T[i]);
  }
  putchar('\n');
  return 0;
}
