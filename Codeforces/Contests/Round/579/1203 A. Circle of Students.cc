#include <cstdio>
const int MAXN = 405;
int A[MAXN];
int B[MAXN], C[MAXN];
int N, Q;

bool solve() {
  B[0] = C[0] = 0;
  int N2 = 2*N;
  for (int i = 1; i <= N2; ++i) {
    if (A[i-1] == A[i] - 1) {
      B[i] = B[i-1] + 1;
      C[i] = 1;
    } else if (A[i-1] == A[i] + 1) {
      B[i] = 1;
      C[i] = C[i-1] + 1;
    } else {
      B[i] = C[i] = 1;
    }
    if ((B[i] == N) || (C[i] == N)) {
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d", &Q);
  for (int q = 1; q <= Q; ++q) {
    scanf("%d", &N);
    A[0] = 0;
    for (int i = 1; i <= N; ++i) {
      scanf("%d", &A[i]);
      A[i+N] = A[i];
    }
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}
