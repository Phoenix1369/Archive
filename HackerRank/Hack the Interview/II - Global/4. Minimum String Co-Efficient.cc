#include <algorithm>
#include <cstdio>
using std::max;
using std::min;
const int MAXN = 1e6+5;
char S[MAXN];
int A[MAXN];
int K, N, P;

void init() {
  A[0] = K = 0;
}

void segments() {
  // Ignore first and last segments
  int pos = 0;
  while ((pos < N) && (S[pos] == S[0])) ++pos;
  
  int last = pos;
  while (pos < N) {
      if (S[pos] != S[last]) {
          ++K;
          A[K] = A[K-1] + (pos - last);
          last = pos;
      }
      ++pos;
  }
}

int solve() {
  int ret = N;
  // Even
  for (int i = 0; i <= P; ++i) {
    int lhs = min(i * 2, K);
    int rhs = max(K - 2 * (P - i), lhs);
    ret = min(A[rhs] - A[lhs], ret);
  }
  // Odd
  for (int i = 0; i < P; ++i) {
    int lhs = min(i * 2 + 1, K);
    int rhs = max(K - 2 * (P - i) + 1, lhs);
    ret = min(A[rhs] - A[lhs], ret);
  }
  return ret;
}

int main() {
  scanf(" %d%d%s", &N, &P, S);
  init();
  segments();
  printf("%d\n", solve());
  return 0;
}
