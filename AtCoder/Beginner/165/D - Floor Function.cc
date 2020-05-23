#include <algorithm>
#include <cstdio>
typedef long long lld;
int A;
lld B, N;

lld f(lld x) {
  return (A * x) / B - A * (x / B);
}

int main() {
  scanf(" %d%lld%lld", &A, &B, &N);
  printf("%lld\n", f(std::min(B-1, N)));
  return 0;
}
