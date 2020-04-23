#include <cstdio>
#include <unordered_map>
const int MAXN = 2e5+5;
int A[MAXN];
int cnt[MAXN*2];
int D[MAXN*2];
int K, N, T;

// D[i] = number of pairs achieving sum i within one move.

int solve() {
  scanf(" %d%d", &N, &K);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  int K2 = K*2;
  int N2 = N/2;
  for (int i = 0; i <= K2; ++i) {
    cnt[i] = 0;
    D[i] = 0;
  }
  for (int i = 0; i < N2; ++i) {
    int sum = A[i] + A[N-i-1];
    ++cnt[sum];

    int lo = std::min(A[i], A[N-i-1]);
    int hi = std::max(A[i], A[N-i-1]);
    ++D[lo+1];
    --D[hi+K+1];
  }
  for (int i = 1; i <= K2; ++i) {
    D[i] += D[i-1];
  }
  int ret = N;
  for (int i = 2; i <= K2; ++i) {
    int cost = (D[i] - cnt[i]) + 2 * (N2 - D[i]);
    ret = std::min(cost, ret);
  }
  return ret;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    printf("%d\n", solve());
  }
  return 0;
}
