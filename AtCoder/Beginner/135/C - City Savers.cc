#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 1e5+5;
int A[MAXN], B[MAXN];
lld ret;
int N;

void dec(int i, int j) {
    int val = std::min(A[i], B[j]);
    A[i] -= val;
    B[j] -= val;
    ret += val;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i <= N; ++i) {
    scanf("%d", &A[i]);
  }
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &B[i]);
  }
  ret = 0LL;
  for (int i = 1; i <= N; ++i) {
    dec(i-1, i);
    dec(i, i);
  }
  printf("%lld\n", ret);
  return 0;
}
