#include <algorithm>
#include <cstdio>
const int MAXN = 25;
int P[MAXN];
int N;

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &P[i]);
  }
  int ret = 0;
  for (int i = 2; i < N; ++i) {
    int mn = P[i-1];
    int mx = P[i+1];
    if (mn > mx) std::swap(mn, mx);
    if ((mn < P[i]) && (P[i] < mx)) ++ret;
  }
  printf("%d\n", ret);
  return 0;
}
