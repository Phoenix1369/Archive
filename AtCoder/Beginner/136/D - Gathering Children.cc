#include <cstdio>
#include <cstring>
const int MAXN = 1e5+5;
int A[MAXN];
char S[MAXN];
int N;

int main() {
  scanf("%s", S);
  N = strlen(S);
  for (int i = 0; i < N; ++i) {
    A[i] = 0;
  }
  for (int i = 0, j; i < N; i = j) {
    int p = i;
    while (S[i] == 'R') ++i;
    j = i;
    while ((j < N) && (S[j] == 'L')) ++j;
    int lhs = i-p;
    int rhs = j-i;
    A[i] = lhs / 2 + (rhs + 1) / 2;
    A[i-1] = (lhs + 1) / 2 + rhs / 2;
  }
  for (int i = 0; i < N; ++i) {
    printf("%d%c", A[i], (i+1 == N) ? '\n' : ' ');
  }
  return 0;
}
