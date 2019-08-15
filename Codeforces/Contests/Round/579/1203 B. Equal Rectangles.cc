#include <algorithm>
#include <cstdio>
const int MAXN = 405;
int A[MAXN];
int N, Q;
int N4;

bool solve() {
  int lo = 1;
  int hi = N4;
  int area = A[lo] * A[hi];
  while (lo < hi) {
    if ((A[lo] != A[lo+1]) ||
        (A[hi] != A[hi-1]) ||
        (A[lo] * A[hi] != area)) {
      return false;
    }
    lo += 2;
    hi -= 2;
  }
  return true;
}

int main() {
  scanf("%d", &Q);
  for (int q = 1; q <= Q; ++q) {
    scanf("%d", &N);
    N4 = 4*N;
    for (int i = 1; i <= N4; ++i) {
      scanf("%d", &A[i]);
    }
    std::sort(A+1, A+N4+1);
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}
