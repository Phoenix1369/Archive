#include <cstdio>
typedef long long lld;
const int MAXN = 1e5+5;
int A[MAXN];
int n, x;

int f(int k) {
  return (k / x) * x;
}

int main() {
  scanf(" %d%d", &n, &x);
  lld ret = 0LL;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
    if (A[i] > 0) {
      while (true) {
        int y = f(A[i]);
        if (y == A[i]) {
          break;
        }
        A[i] = y;
      }
    }
    ret += A[i];
  }
  printf("%lld\n", ret);
  return 0;
}
