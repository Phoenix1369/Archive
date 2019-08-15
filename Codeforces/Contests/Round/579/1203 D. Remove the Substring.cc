#include <algorithm>
#include <cstdio>
#include <cstring>
const int MAXS = 2e5+5;
char S[MAXS];
char T[MAXS];
int pre[MAXS];
int suf[MAXS];
int M, N;

int main() {
  scanf(" %s%s", S, T);
  N = strlen(S);
  M = strlen(T);

  // Prefix
  for (int i=0, j=0; i < M; ++i, ++j) {
    while ((j < N) && (S[j] != T[i])) ++j;
    pre[i] = j;
  }
  // Suffix
  for (int i=M-1, j=N-1; i >= 0; --i, --j) {
    while ((j >= 0) && (S[j] != T[i])) --j;
    suf[i] = j;
  }

  // Solve
  int ret = std::max(N - pre[M-1] - 1, suf[0]);
  for (int i = 1; i < M; ++i) {
    ret = std::max(suf[i] - pre[i-1] - 1, ret);
  }
  printf("%d\n", ret);
  return 0;
}
