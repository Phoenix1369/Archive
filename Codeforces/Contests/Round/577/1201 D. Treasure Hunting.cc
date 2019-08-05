#include <algorithm>
#include <cstdio>
#include <utility>
#define x first
#define y second
typedef long long lld;
typedef std::pair<int,int> pii;
const int MAXK = 2e5+5;
const int MAXQ = 2e5+5;
pii A[MAXK];
int B[MAXQ];
lld dp[MAXK][2];
int prev[MAXK];
int K, M, N, Q;

int distance_from_safe_column(int i, int u, int v) {
    return std::abs(u - B[i]) + std::abs(B[i] - v);
}

int nearest_safe_column_right(int col) {
  return std::lower_bound(B, B+Q, col) - B;
}

int main() {
  scanf(" %d%d%d%d", &N, &M, &K, &Q);
  bool one = false;
  for (int i = 0; i < K; ++i) {
    scanf("%d%d", &A[i].x, &A[i].y);
    one |= (A[i].x == 1);
  }
  if (!one) {
    A[K++] = {1,1};
  }
  std::sort(A, A+K);
  for (int i = 0; i < Q; ++i) {
    scanf("%d", &B[i]);
  }
  std::sort(B, B+Q);

  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < 2; ++j) {
      dp[i][j] = -1;
    }
  }
  int c = 0;
  for (int i = 0, j; i < K; i = j, ++c) {
    j = i;
    while ((j < K) && (A[i].x == A[j].x)) ++j;
    prev[c] = A[i].y;
    if (!c) {
      dp[c][1] = A[j-1].y - 1;
      dp[c][0] = dp[c][1] + A[j-1].y - A[i].y;
      continue;
    }
    // Transitions
    int pl = prev[c-1]; // previous L-end
    int pr = A[i-1].y;  // previous R-end
    int py = A[i-1].x;  // previous Y-value (row index)

    int cl = prev[c];   // current L-end
    int cr = A[j-1].y;  // current R-end
    int cy = A[i].x;    // current Y-value (row index)

    lld lcost, rcost;
    { // PL
      int plR = nearest_safe_column_right(pl);
      if (plR == Q) --plR;
      int plL = plR;
      if (plL != 0) --plL;
      // (pl -> cr -> cl)
      lld llcost = (cy - py) + std::abs(cr - cl) + std::min(
        distance_from_safe_column(plR, pl, cr),
        distance_from_safe_column(plL, pl, cr)
      ) + dp[c-1][0];
      // (pl -> cl -> cr)
      lld lrcost = (cy - py) + std::abs(cr - cl) + std::min(
        distance_from_safe_column(plR, pl, cl),
        distance_from_safe_column(plL, pl, cl)
      ) + dp[c-1][0];

      // PR
      int prR = nearest_safe_column_right(pr);
      if (prR == Q) --prR;
      int prL = prR;
      if (prL != 0) --prL;
      // (pr -> cr -> cl)
      lld rlcost = (cy - py) + std::abs(cr - cl) + std::min(
        distance_from_safe_column(prR, pr, cr),
        distance_from_safe_column(prL, pr, cr)
      ) + dp[c-1][1];
      // (pr -> cl -> cr)
      lld rrcost = (cy - py) + std::abs(cr - cl) + std::min(
        distance_from_safe_column(prR, pr, cl),
        distance_from_safe_column(prL, pr, cl)
      ) + dp[c-1][1];

      lcost = std::min(llcost, rlcost);
      rcost = std::min(lrcost, rrcost);
    }
    dp[c][0] = lcost;
    dp[c][1] = rcost;
  }
  lld ret = std::min(dp[c-1][0], dp[c-1][1]);
  printf("%lld\n", ret);
  return 0;
}
