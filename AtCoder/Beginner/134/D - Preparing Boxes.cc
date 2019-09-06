#include <cstdio>
const int MAXN = 2e5+5;
int A[MAXN]{ };
int B[MAXN]{ };
int M, N;

int count_up(int i) {
  int sum = 0;
  for (int j = i; j <= N; j += i) {
    if (B[j]) sum ^= 1;
  }
  return sum;
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
  }
  M = 0;
  for (int i = N; i >= 1; --i) {
    if (count_up(i) != A[i]) {
      B[i] = 1;
      ++M;
    }
  }
  printf("%d\n", M);
  for (int i = 1; i <= N; ++i) {
    if (B[i]) printf("%d ", i);
  }
  putchar('\n');
  return 0;
}
