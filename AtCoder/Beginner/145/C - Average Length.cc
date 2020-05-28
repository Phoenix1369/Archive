#include <cmath>
#include <cstdio>
const int MAXN = 10;
int F[MAXN];
int X[MAXN];
int Y[MAXN];
int N;

void init() {
  F[0] = 1;
  for (int i = 1; i <= N; ++i) {
    F[i] = F[i-1] * i;
  }
}

int main() {
  scanf("%d", &N);
  init();
  for (int i = 1; i <= N; ++i) {
    scanf(" %d%d", &X[i], &Y[i]);
  }
  double sum = 0;
  for (int i = 1; i < N; ++i) {
    for (int j = i+1; j <= N; ++j) {
      double D = hypot(X[i] - X[j], Y[i] - Y[j]);
      sum += 2 * D * F[N-1];
    }
  }
  sum /= F[N];
  printf("%.9f\n", sum);
  return 0;
}
