#include <algorithm>
#include <cstdio>
const int MAXN = 2e5+5;
int A[MAXN];
int suf[MAXN];
int N;

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
  }
  A[0] = suf[N+1] = 0;
  for (int i = N; i >= 1; --i) {
    suf[i] = std::max(suf[i+1], A[i]);
  }
  for (int i = 1; i <= N; ++i) {
    printf("%d\n", std::max(A[i-1], suf[i+1]));
    A[i] = std::max(A[i-1], A[i]);
  }
  return 0;
}
