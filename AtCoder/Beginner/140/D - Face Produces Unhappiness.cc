#include <algorithm>
#include <cstdio>
const int MAXN = 1e5+5;
char S[MAXN];
int K, N;

int solve() {
  int A = 0;
  for (int i = 0; i < N; ++i) {
    if ((S[i] == 'L') && (i > 0) && (S[i-1] == S[i])) ++A;
    if ((S[i] == 'R') && (i+1 < N) && (S[i+1] == S[i])) ++A;
  }
  return std::min(N-1, A+2*K);
}

int main() {
  scanf(" %d%d%s", &N, &K, S);
  printf("%d\n", solve());
  return 0;
}
