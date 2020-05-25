#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 1005;
int A[MAXN];
vin C, D, P;
int N, T;

bool solve() {
  C.assign(MAXN, 0);
  D.assign(MAXN, 0);
  P.assign(MAXN, -1);
  for (int i = 0; i < N; ++i) {
    if ((P[A[i]] != -1) && (P[A[i]] != i-1)) {
      return false;
    }
    P[A[i]] = i;
    ++C[A[i]];
  }
  for (int i = 1; i < MAXN; ++i) {
    if (C[i] && D[C[i]]++) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}
