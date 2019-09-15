#include <algorithm>
#include <cstdio>
const int MAXB = 1e5+5;
int B, N;

int main() {
  scanf("%d", &N);
  int prev = MAXB;
  int ret = 0;
  for (int i = 1; i < N; ++i) {
    scanf("%d", &B);
    ret += std::min(B, prev);
    prev = B;
  }
  ret += B;
  printf("%d\n", ret);
  return 0;
}
