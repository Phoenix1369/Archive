#include <cstdio>
const int MAXN = 1e5+5;
int P[MAXN]{ };
int A, K, N, Q;

int main() {
  scanf(" %d%d%d", &N, &K, &Q);
  for (int i = 0; i < Q; ++i) {
    scanf("%d", &A);
    ++P[A];
  }
  for (int i = 1; i <= N; ++i) {
    int score = K + P[i] - Q;
    puts((score > 0) ? "Yes" : "No");
  }
  return 0;
}
