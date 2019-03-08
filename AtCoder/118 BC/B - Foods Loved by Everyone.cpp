#include <cstdio>
int A, K, M, N;

int bitcount(unsigned int n) { return n ? __builtin_popcount(n) : 0; }

int main() {
  scanf(" %d%d", &N, &M);
  int every = (1<<M) - 1;
  for (int i = 0; i < N; ++i) {
    int mask = 0;
    scanf("%d", &K);
    for (int j = 0; j < K; ++j) {
      scanf("%d", &A);
      mask |= (1<<(A-1));
    }
    every &= mask;
  }
  printf("%d\n", bitcount(every));
  return 0;
}
