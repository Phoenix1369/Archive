#include <cstdio>
#include <cstring>
const int MAXS = 15;
char S[MAXS];
char T[MAXS];
int N;

int main() {
  scanf(" %s", S);
  scanf(" %s", T);
  N = strlen(S);
  T[N] = '\0';
  puts((strcmp(S, T) == 0) ? "Yes" : "No");
  return 0;
}
