#include <algorithm>
#include <cstdio>
const int MAXN = 15;
int A[MAXN];
int X[MAXN][MAXN];
int Y[MAXN][MAXN];
int N;

bool test(int mask, int bit) { return ((mask >> bit) & 1); }

bool valid(int mask) {
  for (int i = 0; i < N; ++i) {
    if (!test(mask, i)) continue;
    for (int j = 0; j < A[i]; ++j) {
      if (Y[i][j] ^ test(mask, X[i][j])) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
    for (int j = 0; j < A[i]; ++j) {
      scanf(" %d%d", &X[i][j], &Y[i][j]);
      --X[i][j];
    }
  }
  int L = (1 << N);
  int ret = 0;
  for (int mask = 1; mask < L; ++mask) {
    if (!valid(mask)) continue;
    ret = std::max(__builtin_popcount(mask), ret);
  }
  printf("%d\n", ret); 
  return 0;
}
