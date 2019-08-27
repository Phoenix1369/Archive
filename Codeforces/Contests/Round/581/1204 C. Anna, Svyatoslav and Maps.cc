#include <algorithm>
#include <cstdio>
#include <vector>
const int INFN = 1e9+7;
const int MAXM = 1e6+5;
const int MAXN = 105;
int D[MAXN][MAXN];
int P[MAXM];
int M, N;
char A;
std::vector<int> ret;

void floyd_warshall() {
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        D[i][j] = std::min(D[i][k] + D[k][j], D[i][j]);
      }
    }
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      scanf(" %c", &A);
      D[i][j] = (i == j) ? 0 : (A == '1') ? 1 : INFN;
    }
  }
  floyd_warshall();
  scanf("%d", &M);
  for (int i = 1; i <= M; ++i) {
    scanf("%d", &P[i]);
  }
  ret.push_back(P[1]);
  for (int i = 2; i <= M; ++i) {
    if (D[ret.back()][P[i]] < D[ret.back()][P[i-1]] + D[P[i-1]][P[i]]) {
      ret.push_back(P[i-1]);
    }
  }
  if (ret.back() != P[M]) {
    ret.push_back(P[M]);
  }
  printf("%u\n", ret.size());
  for (auto v: ret) {
    printf("%d ", v);
  }
  putchar('\n');
  return 0;
}
