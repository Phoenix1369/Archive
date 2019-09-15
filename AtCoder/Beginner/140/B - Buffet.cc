#include <cstdio>
const int MAXN = 25;
int A[MAXN], B[MAXN], C[MAXN];
int N;

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
  for (int i = 1; i <= N; ++i) scanf("%d", &B[i]);
  for (int i = 1; i <  N; ++i) scanf("%d", &C[i]);
  int ret = 0;
  for (int i = 1; i <= N; ++i) {
    ret += B[A[i]];
    if ((i >= 2) && (A[i] == A[i-1] + 1)) {
      ret += C[A[i-1]];
    }
  }
  printf("%d\n", ret);
  return 0;
}
